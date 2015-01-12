/************************************************************
 *
 *  CmdBase.cpp
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

#include "CmdBase.hpp"

#include "../ot_made_easy_ot.hpp"
#include <opentxs/client/ot_otapi_ot.hpp>
#include "../ot_utility_ot.hpp"

#include <opentxs/client/OpenTransactions.hpp>
#include <opentxs/client/OTAPI.hpp>
#include <opentxs/client/OTWallet.hpp>
#include <opentxs/ext/Helpers.hpp>
#include <opentxs/core/Account.hpp>
#include <opentxs/core/AssetContract.hpp>
#include <opentxs/core/Log.hpp>
#include <opentxs/core/Nym.hpp>
#include <opentxs/core/OTServerContract.hpp>

#include <map>
#include <sstream>

using namespace opentxs;
using namespace std;

CmdBase::CmdBase()
    : category(catError)
    , command(nullptr)
    , help(nullptr)
    , usage(nullptr)
{
    for (int i = 0; i < MAX_ARGS; i++) {
        args[i] = nullptr;
    }
}

CmdBase::~CmdBase()
{
}

bool CmdBase::checkAccount(const char* name, string& account) const
{
    if (!checkMandatory(name, account)) {
        return false;
    }

    OTWallet* wallet = getWallet();
    Account* theAccount = wallet->GetAccount(account);
    if (theAccount == nullptr) {
        theAccount = wallet->GetAccountPartialMatch(account);
        if (theAccount == nullptr) {
            otOut << "Error: " << name << ": unknown account: " << account
                  << "\n";
            return false;
        }
    }

    String tmp;
    theAccount->GetPurportedAccountID().GetString(tmp);
    account = tmp.Get();
    otOut << "Using " << name << ": " << account << "\n";
    return true;
}

int64_t CmdBase::checkAmount(const char* name, const string& amount,
                             const string& myacct) const
{
    if (!checkMandatory(name, amount)) {
        return OT_ERROR_AMOUNT;
    }

    string assetType = getAccountAssetType(myacct);
    if ("" == assetType) {
        return OT_ERROR_AMOUNT;
    }

    int64_t value = OTAPI_Wrap::StringToAmount(assetType, amount);
    if (OT_ERROR_AMOUNT == value) {
        otOut << "Error: " << name << ": invalid amount: " << amount << "\n";
        return OT_ERROR_AMOUNT;
    }

    return value;
}

bool CmdBase::checkFlag(const char* name, const string& value) const
{
    if (!checkMandatory(name, value)) {
        return false;
    }

    if (value != "false" && value != "true") {
        otOut << "Error: " << name << ": expected 'false' or 'true'.\n";
        return false;
    }

    return true;
}

int32_t CmdBase::checkIndex(const char* name, const string& index,
                            int32_t items) const
{
    if (!checkValue(name, index)) {
        return -1;
    }

    if (!checkIndicesRange(name, index, items)) {
        return -1;
    }

    return stoi(index);
}

bool CmdBase::checkIndices(const char* name, const string& indices) const
{
    if (!checkMandatory(name, indices)) {
        return false;
    }

    if ("all" == indices) {
        return true;
    }

    for (string::size_type i = 0; i < indices.length(); i++) {
        if (!isdigit(indices[i])) {
            otOut << "Error: " << name << ": not a value: " << indices << "\n";
            return false;
        }
        for (i++; i < indices.length() && isdigit(indices[i]); i++) {
        }
        if (i < indices.length() && ',' != indices[i]) {
            otOut << "Error: " << name << ": not a value: " << indices << "\n";
            return false;
        }
    }

    return true;
}

bool CmdBase::checkIndicesRange(const char* name, const string& indices,
                                int32_t items) const
{
    if ("all" == indices) {
        return true;
    }

    for (string::size_type i = 0; i < indices.length(); i++) {
        int32_t value = 0;
        for (; isdigit(indices[i]); i++) {
            value = value * 10 + indices[i] - '0';
        }
        if (0 > value || value >= items) {
            otOut << "Error: " << name << ": value (" << value
                  << ") out of range (must be < " << items << ")\n";
            return false;
        }
    }

    return true;
}

bool CmdBase::checkMandatory(const char* name, const string& value) const
{
    if ("" == value) {
        otOut << "Error: " << name << ": mandatory parameter not specified.\n";
        return false;
    }

    return true;
}

bool CmdBase::checkNym(const char* name, string& nym, bool checkExistance) const
{
    if (!checkMandatory(name, nym)) {
        return false;
    }

    OTWallet* wallet = getWallet();
    Nym* theNym = wallet->GetNymByID(nym);
    if (theNym == nullptr) {
        theNym = wallet->GetNymByIDPartialMatch(nym);
        if (theNym == nullptr && checkExistance) {
            otOut << "Error: " << name << ": unknown nymm: " << nym << "\n";
            return false;
        }
    }

    if (theNym) {
        String tmp;
        theNym->GetIdentifier(tmp);
        nym = tmp.Get();
    }
    otOut << "Using " << name << ": " << nym << "\n";
    return true;
}

bool CmdBase::checkPurse(const char* name, string& purse) const
{
    if (!checkMandatory(name, purse)) {
        return false;
    }

    OTWallet* wallet = getWallet();
    AssetContract* thePurse = wallet->GetAssetContract(purse);
    if (thePurse == nullptr) {
        thePurse = wallet->GetAssetContractPartialMatch(purse);
        if (thePurse == nullptr) {
            otOut << "Error: " << name << ": unknown purse: " << purse << "\n";
            return false;
        }
    }

    String tmp;
    thePurse->GetIdentifier(tmp);
    purse = tmp.Get();
    otOut << "Using " << name << ": " << purse << "\n";
    return true;
}

bool CmdBase::checkServer(const char* name, string& server) const
{
    if (!checkMandatory(name, server)) {
        return false;
    }

    OTWallet* wallet = getWallet();
    OTServerContract* theServer = wallet->GetServerContract(server);
    if (theServer == nullptr) {
        theServer = wallet->GetServerContractPartialMatch(server);
        if (theServer == nullptr) {
            otOut << "Error: " << name << ": unknown server: " << server
                  << "\n";
            return false;
        }
    }

    String tmp;
    theServer->GetIdentifier(tmp);
    server = tmp.Get();
    otOut << "Using " << name << ": " << server << "\n";
    return true;
}

int64_t CmdBase::checkTransNum(const char* name, const string& id) const
{
    if (!checkMandatory(name, id)) {
        return -1;
    }

    for (string::size_type i = 0; i < id.length(); i++) {
        if (!isdigit(id[i])) {
            otOut << "Error: " << name << ": not a value: " << id << "\n";
            return -1;
        }
    }

    int64_t value = stoll(id);
    if (0 >= value) {
        otOut << "Error: " << name << ": invalid value: " << id << "\n";
        return -1;
    }

    return value;
}

bool CmdBase::checkValue(const char* name, const string& value) const
{
    if (!checkMandatory(name, value)) {
        return false;
    }

    for (string::size_type i = 0; i < value.length(); i++) {
        if (!isdigit(value[i])) {
            otOut << "Error: " << name << ": not a value: " << value << "\n";
            return false;
        }
    }

    return true;
}

void CmdBase::dashLine() const
{
    // 76 dashes :-)
    cout << "--------------------------------------"
            "--------------------------------------\n";
}

const vector<string>& CmdBase::extractArgumentNames()
{
    // only do this once
    if (0 != argNames.size()) {
        return argNames;
    }

    // extract argument names from usage help text
    for (int i = 0; i < MAX_ARGS && args[i] != nullptr; i++) {
        const char* arg = args[i];
        while ('[' == *arg || '-' == *arg) {
            arg++;
        }
        string argName = "";
        for (; isalpha(*arg); arg++) {
            argName += *arg;
        }
        argNames.push_back(argName);
    }

    return argNames;
}

string CmdBase::formatAmount(const string& assetType, int64_t amount) const
{
    if (OT_ERROR_AMOUNT == amount) {
        // this probably should not happen
        return "UNKNOWN_AMOUNT";
    }

    if ("" == assetType) {
        // just return unformatted
        return to_string(amount);
    }

    return OTAPI_Wrap::FormatAmount(assetType, amount);
}

Category CmdBase::getCategory() const
{
    return category;
}

const char* CmdBase::getCommand() const
{
    return command;
}

const char* CmdBase::getHelp() const
{
    return help;
}

string CmdBase::getAccountAssetType(const string& myacct) const
{
    string assetType =
        OTAPI_Wrap::GetAccountWallet_InstrumentDefinitionID(myacct);
    if ("" == assetType) {
        otOut << "Error: cannot load instrument definition from myacct.\n";
    }
    return assetType;
}

string CmdBase::getOption(string optionName) const
{
    auto result = options.find(optionName);
    if (result == options.end()) {
        otWarn << "Option " << optionName << " not found.\n";
        return "";
    }

    otInfo << "Option  " << result->first << ": " << result->second << "\n";
    return result->second;
}

string CmdBase::getUsage() const
{
    stringstream ss;

    // construct usage string
    ss << "Usage:   " << command;
    for (int i = 0; i < MAX_ARGS && args[i] != nullptr; i++) {
        ss << " " << args[i];
    }
    ss << "\n\n" << help << "\n\n";
    if (usage != nullptr) {
        ss << usage << "\n\n";
    }

    return ss.str();
}

OTWallet* CmdBase::getWallet() const
{
    OTWallet* wallet = OTAPI_Wrap::OTAPI()->GetWallet();
    OT_ASSERT_MSG(wallet != nullptr, "Cannot load wallet->\n");
    return wallet;
}

int32_t CmdBase::harvestTxNumbers(const string& contract, const string& mynym)
{
    OTAPI_Wrap::Msg_HarvestTransactionNumbers(contract, mynym, false, false,
                                              false, false, false);
    return -1;
}

string CmdBase::inputLine()
{
    return OT_CLI_ReadLine();
}

string CmdBase::inputText(const char* what)
{
    cout << "Please paste " << what << ",\n"
         << "followed by an EOF or a ~ on a line by itself:\n";

    string input = OT_CLI_ReadUntilEOF();
    if ("" == input) {
        otOut << "Error: you did not paste " << what << ".\n";
    }
    return input;
}

int32_t CmdBase::processResponse(const string& response, const char* what) const
{
    switch (responseStatus(response)) {
    case 1:
        break;

    case 0:
        otOut << "Error: failed to " << what << ".\n";
        return -1;

    default:
        otOut << "Error: cannot " << what << ".\n";
        return -1;
    }

    cout << response << "\n";
    return 1;
}

int32_t CmdBase::processTxResponse(const string& server, const string& mynym,
                                   const string& myacct, const string& response,
                                   const char* what) const
{
    if (1 != responseStatus(response)) {
        otOut << "Error: cannot " << what << ".\n";
        return -1;
    }

    if (1 != VerifyMsgBalanceAgrmntSuccess(server, mynym, myacct, response)) {
        otOut << "Error: " << what << " balance agreement failed.\n";
        return -1;
    }

    if (1 != VerifyMsgTrnxSuccess(server, mynym, myacct, response)) {
        otOut << "Error: " << what << " transaction failed.\n";
        return -1;
    }

    cout << response << "\n";

    return 1;
}

int32_t CmdBase::responseReply(const string& response, const string& server,
                               const string& mynym, const string& myacct,
                               const char* function) const
{
    return InterpretTransactionMsgReply(server, mynym, myacct, function,
                                        response);
}

int32_t CmdBase::responseStatus(const string& response) const
{
    return VerifyMessageSuccess(response);
}

bool CmdBase::run(const map<string, string>& _options)
{
    options = _options;
    int32_t returnValue = runWithOptions();
    options.clear();

    switch (returnValue) {
    case 0: // no action performed, return success
        return true;
    case 1: // success
        return true;
    case -1: // failed
        return false;
    default:
        otOut << "Error: undefined error code: " << returnValue << ".\n";
        break;
    }

    return false;
}

vector<string> CmdBase::tokenize(const string& str, char delim,
                                 bool noEmpty) const
{
    vector<string> tokens;

    const char* p = str.c_str();
    int begin = 0;
    while (true) {
        int next = begin;
        while (p[next] != delim && '\0' != p[next]) {
            next++;
        }
        if (next != begin || !noEmpty) {
            tokens.push_back(str.substr(begin, next - begin));
        }
        if ('\0' == p[next]) {
            break;
        }
        begin = next + 1;
    }

    return tokens;
}
