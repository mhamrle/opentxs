#!/usr/bin/python3 

import base64
import cgi
import sys

def html_escape(input):
    s = cgi.escape(input)
    return s.replace('\n', '<br>\n')

class Line:
    def __init__(self, input, output, link):
#        print "input: ", input 
#        print "output: ", output 
#        print "link: ", link
        self.input = input
        self.output = output
        self.link = link

    def generate(self, lines):
        found = {}
        for l in lines:
            if l == self:
                continue
            begin = 0
            while(True):
                start = self.input.find(l.output, begin)
                if start == -1:
                    break
                found[(start, -len(l.output))] = l
                begin = start + len(l.output)

        maximum_reached = -1
        result = {}
        for key in sorted(found.keys()):
            if key[0] < maximum_reached:
                continue
            # key[1] is negative
            maximum_reached = key[0] - key[1]
            result[(key[0], maximum_reached - 1)] = found[key]
            # and process also result
            found[key].generate(lines)

        maximum_reached = -1
        for key in sorted(result.keys()):
            if key[0] > maximum_reached + 1:
                result[(maximum_reached + 1, key[0] - 1)] = None
            maximum_reached = key[1]

        if maximum_reached + 1 <= len(self.input) - 1:
            result[(maximum_reached + 1, len(self.input) - 1)] = None

#        print(self.input)
#        print(found)
#        print(result)
        self.tree = result

    def generateHtml(self, bgcolor=None, nested=0):
        html = '<a href="#" class="toggler toggler-%s">toggle [-]</a><br/>' % nested
        html += '<table border="1" '
        if bgcolor:
            html += 'bgcolor="%s" ' % bgcolor
        html += '>'
        for key in sorted(self.tree.keys()):
            html += "<tr>"
            html += ("""<td class="nested nested-%d"><span>""" % nested) + html_escape(self.input[key[0]:key[1]+1]) + "</span></td>"
            html += """<td class="nest nest-%d">""" % nested
            l = self.tree[key]
            if l:
                html += l.generateHtml(nested=nested+1)
            html += "</td>"
            if l:
                html += "<td>" + l.link + "</td>"
            else:
                html += "<td></td>"
            html += "</tr>"
        html += "</table>"
        return html

class Message:
    def __init__(self, line):
        self.line = line
        self.lines = []
        self.time = line.output.split("_")[3]
        self.device = line.output.split("_")[1]

    def addLine(self, line):
        self.lines.append(line)

    def generateHtml(self):
        self.line.generate(self.lines)
        bgcolor = None
        if self.device == "server":
            bgcolor = "#F5F5DC"
        if self.device == "client":
            bgcolor = "#F0F8FF"
        
        return self.line.output + "<br>" + self.line.generateHtml(bgcolor=bgcolor)


lines = []
def parse_file(filename):
    messages = []
    with open(filename, "r") as f:
        for line in f:
            if not line.startswith("TraceLine:"):
                continue
            ss = line.split(" ", 1)[1]
            s = ss.split(";")
            if s[1].startswith("message_"):
                l = Line(base64.decodestring(s[0]), s[1], s[2])
                messages.append(Message(l))
                messages[-1].lines = lines
            else:
                l = Line(base64.decodestring(s[0]), base64.decodestring(s[1]), s[2])
            lines.append(l)
    return messages

messages = parse_file(sys.argv[1])
if len(sys.argv) > 2:
    messages_client = parse_file(sys.argv[2])
    messages.extend(messages_client)
    messages.sort(key=lambda x: int(x.time))

print "<html>\n"
print """
<head>
  <script src="http://ajax.googleapis.com/ajax/libs/prototype/1.7.2.0/prototype.js"></script>
  <script>
    $(document).observe("dom:loaded", function() {
    $$("a.toggler").each(function(el) {
    el.observe("click", function() {
    var tbl = el.next("table");
    if(tbl.visible()) {
    el.innerHTML = "toggle [+]";
    tbl.hide();
} else {
el.innerHTML = "toggle [-]";
tbl.show();
}
    return false;
    });
    });
    });
  </script>

  <style>
    td { vertical-align: top; }
    td.nested-1>span { 
    display: inline-block;
    max-height: 100px;
    overflow: auto;
    }
  </style>
</head>
<body>
"""
for i, m in enumerate(messages):
    sys.stderr.write("%d - %s time %s\n" % (i, len(messages), m.time))
    print m.generateHtml()
    print "\n"
print "\n</body></html>\n"
