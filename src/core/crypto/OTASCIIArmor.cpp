/************************************************************
 *
 *  OTASCIIArmor.cpp
 *
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA1

 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  Copyright (C) 2010-2013 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- otlib.........A class library.......LICENSE:...LAGPLv3
 *   -- otapi.........A client API..........LICENSE:...LAGPLv3
 *   -- opentxs/ot....Command-line client...LICENSE:...LAGPLv3
 *   -- otserver......Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (bitcointrader4@gmail.com).
 *  The open-source community has since actively contributed.
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT API, then you
 *   don't have to open-source your code--only your changes to
 *   Open-Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open-Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open-Transactions terms remain respected, with regard to
 *   the Open-Transactions code itself.
 *
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/src/otlib/lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   See Lucre on Github:  https://github.com/benlaurie/lucre
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.

 -----BEGIN PGP SIGNATURE-----
 Version: GnuPG v1.4.9 (Darwin)

 iQIcBAEBAgAGBQJRSsfJAAoJEAMIAO35UbuOQT8P/RJbka8etf7wbxdHQNAY+2cC
 vDf8J3X8VI+pwMqv6wgTVy17venMZJa4I4ikXD/MRyWV1XbTG0mBXk/7AZk7Rexk
 KTvL/U1kWiez6+8XXLye+k2JNM6v7eej8xMrqEcO0ZArh/DsLoIn1y8p8qjBI7+m
 aE7lhstDiD0z8mwRRLKFLN2IH5rAFaZZUvj5ERJaoYUKdn4c+RcQVei2YOl4T0FU
 LWND3YLoH8naqJXkaOKEN4UfJINCwxhe5Ke9wyfLWLUO7NamRkWD2T7CJ0xocnD1
 sjAzlVGNgaFDRflfIF4QhBx1Ddl6wwhJfw+d08bjqblSq8aXDkmFA7HeunSFKkdn
 oIEOEgyj+veuOMRJC5pnBJ9vV+7qRdDKQWaCKotynt4sWJDGQ9kWGWm74SsNaduN
 TPMyr9kNmGsfR69Q2Zq/FLcLX/j8ESxU+HYUB4vaARw2xEOu2xwDDv6jt0j3Vqsg
 x7rWv4S/Eh18FDNDkVRChiNoOIilLYLL6c38uMf1pnItBuxP3uhgY6COm59kVaRh
 nyGTYCDYD2TK+fI9o89F1297uDCwEJ62U0Q7iTDp5QuXCoxkPfv8/kX6lS6T3y9G
 M9mqIoLbIQ1EDntFv7/t6fUTS2+46uCrdZWbQ5RjYXdrzjij02nDmJAm2BngnZvd
 kamH0Y/n11lCvo1oQxM+
 =uSzz
 -----END PGP SIGNATURE-----
 **************************************************************/

#include <opentxs/core/stdafx.hpp>

#include <opentxs/core/crypto/OTASCIIArmor.hpp>
#include <opentxs/core/crypto/OTCrypto.hpp>
#include <opentxs/core/crypto/OTEnvelope.hpp>
#include <opentxs/core/Log.hpp>
#include <opentxs/core/OTStorage.hpp>

#include <sstream>
#include <fstream>
#include <cstring>
#include <zlib.h>

namespace opentxs
{

const char* OT_BEGIN_ARMORED = "-----BEGIN OT ARMORED";
const char* OT_END_ARMORED = "-----END OT ARMORED";

const char* OT_BEGIN_ARMORED_escaped = "- -----BEGIN OT ARMORED";
const char* OT_END_ARMORED_escaped = "- -----END OT ARMORED";

const char* OT_BEGIN_SIGNED = "-----BEGIN SIGNED";
const char* OT_BEGIN_SIGNED_escaped = "- -----BEGIN SIGNED";

// Let's say you don't know if the input string is raw base64, or if it has
// bookends
// on it like -----BEGIN BLAH BLAH ...
// And if it DOES have Bookends, you don't know if they are escaped:  -
// -----BEGIN ...
// Let's say you just want an easy function that will figure that crap out, and
// load the
// contents up properly into an OTASCIIArmor object. (That's what this function
// will do.)
//
// str_bookend is a default.
// So you could make it more specific like, -----BEGIN ENCRYPTED KEY (or
// whatever.)
//
// static
bool OTASCIIArmor::LoadFromString(OTASCIIArmor& ascArmor,
                                  const String& strInput,
                                  std::string str_bookend)
{

    if (strInput.Contains(str_bookend)) // YES there are bookends around this.
    {
        const std::string str_escaped("- " + str_bookend);

        const bool bEscaped = strInput.Contains(str_escaped);

        String strLoadFrom(strInput);

        if (!ascArmor.LoadFromString(strLoadFrom, bEscaped)) // removes the
                                                             // bookends so we
                                                             // have JUST the
                                                             // coded part.
        {
            //          otErr << "%s: Failure loading string into OTASCIIArmor
            // object:\n\n%s\n\n",
            //                        __FUNCTION__, strInput.Get());
            return false;
        }
    }
    else
        ascArmor.Set(strInput.Get());

    return true;
}

// initializes blank.
OTASCIIArmor::OTASCIIArmor()
    : String()
{
}

// encodes
OTASCIIArmor::OTASCIIArmor(const String& strValue)
    : String(/*Don't pass here, since we're encoding.*/)
{
    SetString(strValue);
}

// encodes
OTASCIIArmor::OTASCIIArmor(const OTData& theValue)
    : String()
{
    SetData(theValue);
}

// Copies (already encoded)
OTASCIIArmor::OTASCIIArmor(const OTASCIIArmor& strValue)
    : String(dynamic_cast<const String&>(strValue))
{
}

// assumes envelope contains encrypted data;
// grabs that data in base64-form onto *this.
OTASCIIArmor::OTASCIIArmor(const OTEnvelope& theEnvelope)
    : String()
{
    theEnvelope.GetAsciiArmoredData(*this);
}

// copies (already encoded)
OTASCIIArmor::OTASCIIArmor(const char* szValue)
    : String(szValue)
{
}

// copies, assumes already encoded.
OTASCIIArmor& OTASCIIArmor::operator=(const char* szValue)
{
    Set(szValue);
    return *this;
}

// encodes
OTASCIIArmor& OTASCIIArmor::operator=(const String& strValue)
{
    if ((&strValue) != (&(dynamic_cast<const String&>(*this)))) {
        SetString(strValue);
    }
    return *this;
}

// encodes
OTASCIIArmor& OTASCIIArmor::operator=(const OTData& theValue)
{
    SetData(theValue);
    return *this;
}

// assumes is already encoded and just copies the encoded text
OTASCIIArmor& OTASCIIArmor::operator=(const OTASCIIArmor& strValue)
{
    if ((&strValue) != this) // prevent self-assignment
    {
        String::operator=(dynamic_cast<const String&>(strValue));
    }
    return *this;
}

// Source for these two functions: http://panthema.net/2007/0328-ZLibString.html

/** Compress a STL string using zlib with given compression level and return
 * the binary data. */
std::string OTASCIIArmor::compress_string(
    const std::string& str, int32_t compressionlevel = Z_BEST_COMPRESSION) const
{
    z_stream zs; // z_stream is zlib's control structure
    memset(&zs, 0, sizeof(zs));

    if (deflateInit(&zs, compressionlevel) != Z_OK)
        throw(std::runtime_error("deflateInit failed while compressing."));

    zs.next_in = reinterpret_cast<Bytef*>(const_cast<char*>(str.data()));
    zs.avail_in = static_cast<uInt>(str.size()); // set the z_stream's input

    int32_t ret;
    char outbuffer[32768];
    std::string outstring;

    // retrieve the compressed bytes blockwise
    do {
        zs.next_out = reinterpret_cast<Bytef*>(outbuffer);
        zs.avail_out = sizeof(outbuffer);

        ret = deflate(&zs, Z_FINISH);

        if (outstring.size() < zs.total_out) {
            // append the block to the output string
            outstring.append(outbuffer, zs.total_out - outstring.size());
        }
    } while (ret == Z_OK);

    deflateEnd(&zs);

    if (ret != Z_STREAM_END) { // an error occurred that was not EOF
        std::ostringstream oss;
        oss << "Exception during zlib compression: (" << ret << ") " << zs.msg;
        throw(std::runtime_error(oss.str()));
    }

    return outstring;
}

/** Decompress an STL string using zlib and return the original data. */
std::string OTASCIIArmor::decompress_string(const std::string& str) const
{
    z_stream zs; // z_stream is zlib's control structure
    memset(&zs, 0, sizeof(zs));

    if (inflateInit(&zs) != Z_OK)
        throw(std::runtime_error("inflateInit failed while decompressing."));

    zs.next_in = reinterpret_cast<Bytef*>(const_cast<char*>(str.data()));
    zs.avail_in = static_cast<uInt>(str.size());

    int32_t ret;
    char outbuffer[32768];
    std::string outstring;

    // get the decompressed bytes blockwise using repeated calls to inflate
    do {
        zs.next_out = reinterpret_cast<Bytef*>(outbuffer);
        zs.avail_out = sizeof(outbuffer);

        ret = inflate(&zs, 0);

        if (outstring.size() < zs.total_out) {
            outstring.append(outbuffer, zs.total_out - outstring.size());
        }

    } while (ret == Z_OK);

    inflateEnd(&zs);

    if (ret != Z_STREAM_END) { // an error occurred that was not EOF
        std::ostringstream oss;
        oss << "Exception during zlib decompression: (" << ret << ")";
        if (zs.msg != nullptr) {
            oss << " " << zs.msg;
        }
        throw(std::runtime_error(oss.str()));
    }

    return outstring;
}

// Base64-decode
bool OTASCIIArmor::GetData(OTData& theData,
                           bool bLineBreaks) const // linebreaks=true
{
    theData.Release();

    if (GetLength() < 1) return true;

    size_t outSize = 0;
    uint8_t* pData = OTCrypto::It()->Base64Decode(Get(), &outSize, bLineBreaks);

    if (!pData) {
        otErr << __FUNCTION__ << "Base64Decode fail\n";
        return false;
    }

    theData.Assign(pData, outSize);
    delete[] pData;
    return true;
}

// Base64-encode
bool OTASCIIArmor::SetData(const OTData& theData, bool bLineBreaks)
{
    Release();

    if (theData.GetSize() < 1) return true;

    char* pString = OTCrypto::It()->Base64Encode(
        static_cast<const uint8_t*>(theData.GetPointer()), theData.GetSize(),
        bLineBreaks);

    if (!pString) {
        otErr << __FUNCTION__ << "Base64Encode fail\n";
        return false;
    }

    TRACE(theData, pString);
    Set(pString);
    delete[] pString;
    return true;
}

// Base64-decode an decompress
bool OTASCIIArmor::GetString(String& strData,
                             bool bLineBreaks) const // bLineBreaks=true
{
    strData.Release();

    if (GetLength() < 1) {
        return true;
    }

    size_t outSize = 0;
    uint8_t* pData = OTCrypto::It()->Base64Decode(Get(), &outSize, bLineBreaks);

    if (!pData) {
        otErr << __FUNCTION__ << "Base64Decode fail\n";
        return false;
    }

    std::string str_decoded(pData, pData + outSize);

    delete[] pData;

    std::string str_uncompressed;
    try {
        str_uncompressed = decompress_string(str_decoded);
    }
    catch (const std::runtime_error&) {
        otErr << __FUNCTION__ << "decompress fail\n";
        return false;
    }

    strData.Set(str_uncompressed.c_str(), str_uncompressed.length());

    return true;
}

// Compress and Base64-encode
bool OTASCIIArmor::SetString(const String& strData, bool bLineBreaks) //=true
{
    Release();

    if (strData.GetLength() < 1) return true;

    std::string stdstring = std::string(strData.Get());
    std::string str_compressed = compress_string(stdstring);

    // "Success"
    if (str_compressed.size() == 0) {
        otErr << "OTASCIIArmor::" << __FUNCTION__ << ": compression fail 0.\n";
        return false;
    }

    char* pString = OTCrypto::It()->Base64Encode(
        reinterpret_cast<const uint8_t*>((str_compressed.data())),
        static_cast<int32_t>(str_compressed.size()), bLineBreaks);

    if (!pString) {
        otErr << "OTASCIIArmor::" << __FUNCTION__ << ": Base64Encode fail.\n";
        return false;
    }

    TRACE(strData, pString);
    Set(pString);
    delete[] pString;
    return true;
}

// This code reads up the file, discards the bookends, and saves only the
// gibberish itself.
bool OTASCIIArmor::LoadFromFile(const String& foldername,
                                const String& filename)
{
    OT_ASSERT(foldername.Exists());
    OT_ASSERT(filename.Exists());

    if (!OTDB::Exists(foldername.Get(), filename.Get())) {
        otErr << "OTASCIIArmor::LoadFromFile: File does not exist: "
              << foldername << "" << Log::PathSeparator() << "" << filename
              << "\n";
        return false;
    }

    String strFileContents(OTDB::QueryPlainString(
        foldername.Get(), filename.Get())); // <=== LOADING FROM DATA STORE.

    if (strFileContents.GetLength() < 2) {
        otErr << "OTASCIIArmor::LoadFromFile: Error reading file: "
              << foldername << Log::PathSeparator() << filename << "\n";
        return false;
    }

    return LoadFromString(strFileContents);
}

bool OTASCIIArmor::LoadFromExactPath(const std::string& filename)
{
    std::ifstream fin(filename.c_str(), std::ios::binary);

    if (!fin.is_open()) {
        otWarn << "OTASCIIArmor::LoadFromExactPath: Failed opening file: "
               << filename << "\n";
        return false;
    }

    return LoadFrom_ifstream(fin);
}

// This code reads up the file, discards the bookends, and saves only the
// gibberish itself.
bool OTASCIIArmor::LoadFrom_ifstream(std::ifstream& fin)
{
    std::stringstream buffer;
    buffer << fin.rdbuf();

    std::string contents(buffer.str());

    String theString;
    theString.Set(contents.c_str());

    return LoadFromString(theString);
}

bool OTASCIIArmor::SaveToExactPath(const std::string& filename)
{
    std::ofstream fout(filename.c_str(), std::ios::out | std::ios::binary);

    if (!fout.is_open()) {
        otWarn << "OTASCIIArmor::SaveToExactPath: Failed opening file: "
               << filename << "\n";
        return false;
    }

    return SaveTo_ofstream(fout);
}

bool OTASCIIArmor::SaveTo_ofstream(std::ofstream& fout)
{
    String strOutput;
    std::string str_type("DATA"); // -----BEGIN OT ARMORED DATA-----

    if (WriteArmoredString(strOutput, str_type) && strOutput.Exists()) {
        // WRITE IT TO THE FILE
        //
        fout << strOutput;

        if (fout.fail()) {
            otErr << __FUNCTION__ << ": Failed saving to file.\n Contents:\n\n"
                  << strOutput << "\n\n";
            return false;
        }

        return true;
    }

    return false;
}

// const char * OT_BEGIN_ARMORED   = "-----BEGIN OT ARMORED";
// const char * OT_END_ARMORED     =   "-----END OT ARMORED";

bool OTASCIIArmor::WriteArmoredFile(
    const String& foldername, const String& filename,
    const // for "-----BEGIN OT LEDGER-----", str_type would contain "LEDGER"
    std::string str_type, // There's no default, to force you to enter the right
                          // string.
    bool bEscaped) const
{
    OT_ASSERT(foldername.Exists());
    OT_ASSERT(filename.Exists());

    String strOutput;

    if (WriteArmoredString(strOutput, str_type, bEscaped) &&
        strOutput.Exists()) {
        // WRITE IT TO THE FILE
        // StorePlainString will attempt to create all the folders leading up to
        // the path
        // for the output file.
        //
        bool bSaved = OTDB::StorePlainString(strOutput.Get(), foldername.Get(),
                                             filename.Get());

        if (!bSaved) {
            otErr << "OTASCIIArmor::WriteArmoredFile"
                  << ": Failed saving to file: %s%s%s\n\n Contents:\n\n"
                  << strOutput << "\n\n",
                foldername.Get(), Log::PathSeparator(), filename.Get();
            return false;
        }

        return true;
    }

    return false;
}

// const char * OT_BEGIN_ARMORED   = "-----BEGIN OT ARMORED";
// const char * OT_END_ARMORED     =   "-----END OT ARMORED";

bool OTASCIIArmor::WriteArmoredString(
    String& strOutput,
    const // for "-----BEGIN OT LEDGER-----", str_type would contain "LEDGER"
    std::string str_type, // There's no default, to force you to enter the right
                          // string.
    bool bEscaped) const
{
    const char* szEscape = "- ";

    String strTemp;
    strTemp.Format(
        "%s%s %s-----\n" // "%s-----BEGIN OT ARMORED %s-----\n"
        "Version: Open Transactions %s\n"
        "Comment: "
        "http://github.com/FellowTraveler/Open-Transactions/wiki\n\n" // todo
        // hardcoding.
        "%s"                // Should already have a newline at the bottom.
        "%s%s %s-----\n\n", // "%s-----END OT ARMORED %s-----\n"
        bEscaped ? szEscape : "",
        OT_BEGIN_ARMORED, str_type.c_str(), // "%s%s %s-----\n"
        Log::Version(),                     // "Version: Open Transactions %s\n"
        /* No variable */                   // "Comment:
        // http://github.com/FellowTraveler/Open-Transactions/wiki\n\n",
        Get(), //  "%s"     <==== CONTENTS OF THIS OBJECT BEING
               // WRITTEN...
        bEscaped ? szEscape : "", OT_END_ARMORED,
        str_type.c_str()); // "%s%s %s-----\n"

    strOutput.Concatenate("%s", strTemp.Get());

    return true;
}

// This code reads up the string, discards the bookends, and saves only the
// gibberish itself.
// the bEscaped option allows you to load a normal ASCII-Armored file if off,
// and allows
// you to load an escaped ASCII-armored file (such as inside the contracts when
// the public keys
// are escaped with a "- " before the rest of the ------- starts.)
//
bool OTASCIIArmor::LoadFromString(String& theStr, // input
                                  bool bEscaped,
                                  const // This szOverride sub-string determines
                                  // where the content starts, when loading.
                                  std::string str_override) // Default is
                                                            // "-----BEGIN"
{
    // Should never be 0 size, as default is "-----BEGIN"
    // But if you want to load a private key, try "-----BEGIN ENCRYPTED PRIVATE"
    // instead.
    // *smile*
    const std::string str_end_line =
        "-----END"; // Someday maybe allow parameterized option for this.

    const int32_t nBufSize = 2100;  // todo: hardcoding
    const int32_t nBufSize2 = 2048; // todo: hardcoding

    char buffer1[2100]; // todo: hardcoding

    std::fill(&buffer1[0], &buffer1[(nBufSize - 1)], 0); // Initializing to 0.

    bool bContentMode = false; // "Currently IN content mode."
    bool bHaveEnteredContentMode =
        false; // "Have NOT YET entered content mode."

    // Clear out whatever string might have been in there before.
    Release();

    // Load up the string from theStr,
    // (bookended by "-----BEGIN ... -----" and "END-----" messages)
    bool bIsEOF = false;
    theStr.reset(); // So we can call theStr.sgets(). Making sure position is at
                    // start of string.

    do {
        bIsEOF = !(theStr.sgets(buffer1, nBufSize2)); // 2048

        std::string line = buffer1;
        const char* pBuf = line.c_str();

        // It's not a blank line.
        if (line.length() < 2) {
            continue;
        }

        // if we're on a dashed line...
        else if (line.at(0) == '-' && line.at(2) == '-' && line.at(3) == '-' &&
                 (bEscaped ? (line.at(1) == ' ') : (line.at(1) == '-'))) {
            // If I just hit a dash, that means there are only two options:

            // a. I have not yet entered content mode, and potentially just now
            // entering it for the first time.
            if (!bHaveEnteredContentMode) {
                // str_override defaults to:  "-----BEGIN" (If you want to load
                // a private key instead,
                // Try passing "-----BEGIN ENCRYPTED PRIVATE" instead of going
                // with the default.)
                //
                if (line.find(str_override) != std::string::npos &&
                    line.at(0) == '-' && line.at(2) == '-' &&
                    line.at(3) == '-' &&
                    (bEscaped ? (line.at(1) == ' ') : (line.at(1) == '-'))) {
                    //                    otErr << "Reading ascii-armored
                    // contents...";
                    bHaveEnteredContentMode = true;
                    bContentMode = true;
                    continue;
                }
                else {
                    continue;
                }
            }

            // b. I am now LEAVING content mode!
            else if (bContentMode &&
                     // str_end_line is "-----END"
                     (line.find(str_end_line) != std::string::npos)) {
                //                otErr << "Finished reading ascii-armored
                // contents.\n";
                //                otErr << "Finished reading ascii-armored
                // contents:\n%s(END DATA)\n", Get());
                bContentMode = false;
                continue;
            }
        }

        // Else we're on a normal line, not a dashed line.
        else {
            if (bHaveEnteredContentMode && bContentMode) {
                if (line.compare(0, 8, "Version:") == 0) {
                    //                    otErr << "Skipping version line...\n";
                    continue;
                }
                if (line.compare(0, 8, "Comment:") == 0) {
                    //                    otErr << "Skipping comment line...\n";
                    continue;
                }
            }
        }

        // Here we save the line to member variables, if appropriate
        if (bContentMode) {
            Concatenate("%s\n", pBuf);
        }
    } while (!bIsEOF && (bContentMode || !bHaveEnteredContentMode));

    // reset the string position back to 0
    theStr.reset();

    if (!bHaveEnteredContentMode) {
        otErr << "Error in OTASCIIArmor::LoadFromString: EOF before "
                 "ascii-armored "
                 "content found, in:\n\n" << theStr << "\n\n";
        return false;
    }
    else if (bContentMode) {
        otErr
            << "Error in OTASCIIArmor::LoadFromString: EOF while still reading "
               "content, in:\n\n" << theStr << "\n\n";
        return false;
    }
    else
        return true;
}

OTASCIIArmor::~OTASCIIArmor()
{
    // ~OTString called automatically, which calls Release().
}

} // namespace opentxs
