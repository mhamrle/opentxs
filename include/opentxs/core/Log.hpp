/************************************************************
 *
 *  OTLog.hpp
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

#ifndef OPENTXS_CORE_OTLOG_HPP
#define OPENTXS_CORE_OTLOG_HPP

#include "String.hpp"
#include "util/Assert.hpp"

#include <deque>
#include <iostream>
#include <cstdint>
#include <chrono>

#if defined(unix) || defined(__unix__) || defined(__unix) ||                   \
    defined(__APPLE__) || defined(linux) || defined(__linux) ||                \
    defined(__linux__)
#define PREDEF_PLATFORM_UNIX 1
#endif

#if defined(debug) || defined(_DEBUG) || defined(DEBUG)
#define PREDEF_MODE_DEBUG 1
#endif

#define TRACE(input, output)                                                   \
    trace(input, output, __FILE__, __FUNCTION__, __LINE__)
#define TRACE_MESSAGE(input, spec, id)                                         \
    trace_message(input, spec, id, __FILE__, __FUNCTION__, __LINE__)

namespace opentxs
{

class OTData;

typedef std::deque<String*> dequeOfStrings;

class OTLogStream;

#ifdef _WIN32
#ifdef OTLOG_IMPORT
#undef OTLOG_IMPORT
#define OTLOG_IMPORT __declspec(dllexport)
#else
#define OTLOG_IMPORT __declspec(dllimport)
#endif
#else
#ifndef OTLOG_IMPORT
#define OTLOG_IMPORT
#endif
#endif

OTLOG_IMPORT extern OTLogStream otErr;  // logs using OTLog::vError()
OTLOG_IMPORT extern OTLogStream otInfo; // logs using OTLog::vOutput(2)
OTLOG_IMPORT extern OTLogStream otOut;  // logs using OTLog::vOutput(0)
OTLOG_IMPORT extern OTLogStream otWarn; // logs using OTLog::vOutput(1)
OTLOG_IMPORT extern OTLogStream otLog3; // logs using OTLog::vOutput(3)
OTLOG_IMPORT extern OTLogStream otLog4; // logs using OTLog::vOutput(4)
OTLOG_IMPORT extern OTLogStream otLog5; // logs using OTLog::vOutput(5)

class OTLogStream : public std::ostream, std::streambuf
{
private:
    int logLevel;
    int next;
    char* pBuffer;

public:
    OTLogStream(int _logLevel);
    ~OTLogStream();

    virtual int overflow(int c);
};

// cppcheck-suppress noConstructor
class Log
{
private:
    // public:  // should be private, but since of bug in msvc.

    static Log* pLogger;

    static const String m_strVersion;
    static const String m_strPathSeparator;

    dequeOfStrings logDeque;

    String m_strThreadContext;
    String m_strLogFileName;
    String m_strLogFilePath;

    int32_t m_nLogLevel;

    bool m_bInitialized;

    // For things that represent internal inconsistency in the code.
    // Normally should NEVER happen even with bad input from user.
    // (Don't call this directly. Use the above #defined macro instead.)
    static Assert::fpt_Assert_sz_n_sz(logAssert);

    static bool CheckLogger(Log* pLogger);

public:
    // EXPORT static OTLog& It();

    // now the logger checks the global config file itself for the log-filename.
    EXPORT static bool Init(const String& strThreadContext = "",
                            const int32_t& nLogLevel = 0);

    EXPORT static bool IsInitialized();

    EXPORT static bool Cleanup();

    // OTLog Constants.
    //

    // Compiled into OTLog:

    EXPORT static const char* Version();
    EXPORT static const String& GetVersion();

    EXPORT static const char* PathSeparator();
    EXPORT static const String& GetPathSeparator();

    // Set in constructor:

    EXPORT static const String& GetThreadContext();

    EXPORT static const char* LogFilePath();
    EXPORT static const String& GetLogFilePath();

    EXPORT static int32_t LogLevel();
    EXPORT static bool SetLogLevel(const int32_t& nLogLevel);

    // OTLog Functions:
    //

    EXPORT static bool LogToFile(const String& strOutput);

    // We keep 1024 logs in memory, to make them available via the API.
    EXPORT static int32_t GetMemlogSize();
    EXPORT static String GetMemlogAtIndex(int32_t nIndex);
    EXPORT static String PeekMemlogFront();
    EXPORT static String PeekMemlogBack();
    EXPORT static bool PopMemlogFront();
    EXPORT static bool PopMemlogBack();
    EXPORT static bool PushMemlogFront(const String& strLog);
    EXPORT static bool SleepMilliseconds(int64_t lMilliseconds);

    // Output() logs normal output, which carries a verbosity level.
    //
    // If nVerbosity of a message is 0, the message will ALWAYS log. (ALL output
    // levels are higher or equal to 0.)
    // If nVerbosity is 1, the message will run only if __CurrentLogLevel is 1
    // or higher.
    // If nVerbosity if 2, the message will run only if __CurrentLogLevel is 2
    // or higher.
    // Etc.
    // THEREFORE: The higher the verbosity level for a message, the more verbose
    // the
    // software must be configured in order to display that message.
    //
    // Default verbosity level for the software is 0, and output that MUST
    // appear on
    // the screen should be set at level 0. For output that you don't want to
    // see as often,
    // set it up to 1. Set it up even higher for the really verbose stuff (e.g.
    // only if you
    // really want to see EVERYTHING.)

    EXPORT static void Output(int32_t nVerbosity,
                              const char* szOutput); // stdout
    EXPORT static void vOutput(int32_t nVerbosity, const char* szOutput, ...)
        ATTR_PRINTF(2, 3);

    // This logs an error condition, which usually means bad input from the
    // user, or a file wouldn't open,
    // or something like that. This contrasted with Assert() which should NEVER
    // actually happen. The software
    // expects bad user input from time to time. But it never expects a loaded
    // mint to have a nullptr pointer.
    // The bad input would log with Error(), whereas the nullptr pointer would
    // log
    // with Assert();
    EXPORT static void Error(const char* szError);      // stderr
    EXPORT static void vError(const char* szError, ...) // stderr
        ATTR_PRINTF(1, 2);

    // This method will print out errno and its associated string.
    // Optionally you can pass the location you are calling it from,
    // which will be prepended to the log.
    //
    EXPORT static void Errno(const char* szLocation = nullptr); // stderr

    // String Helpers
    EXPORT static bool StringFill(String& out_strString, const char* szString,
                                  int32_t iLength,
                                  const char* szAppend = nullptr);

    EXPORT static void SetupSignalHandler(); // OPTIONAL. Therefore I will call
                                             // it in xmlrpcxx_client.cpp just
                                             // above OT_Init.
};

std::string trace_to_string(const char* input);
std::string trace_to_string(const std::string& input);
std::string trace_to_string(const String& input);
std::string trace_to_string(const OTData& input);

template <class I, class O>
void trace(const I& input, const O& output, const char* filename,
           const char* function, int line)
{
    std::string input_str = trace_to_string(input);
    std::string output_str = trace_to_string(output);
    otErr << "TraceLine: " << input_str << ";" << output_str << ";" << filename
          << ":" << function << ":" << line << "\n";
}

template <class I>
void trace_message(const I& input, const std::string spec, int id,
                   const char* filename, const char* function, int line)
{
    std::string input_str = trace_to_string(input);
    std::chrono::milliseconds milisec =
        std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::high_resolution_clock::now().time_since_epoch());
    std::string output("message_" + spec + "_" + std::to_string(id) + "_" +
                       std::to_string(milisec.count()));
    otErr << "TraceLine: " << input_str << ";" << output << ";" << filename
          << ":" << function << ":" << line << "\n";
}

} // namespace opentxs

#endif // OPENTXS_CORE_OTLOG_HPP
