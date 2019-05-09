// Author:      Li Leo Wang
// Start Date:  2019-05-09
// Description:
//      - Test boost regex
// Notes:
//      - Add system environment variables:
//          BOOST_ROOT ==> C : \Program Files\boost\boost_1_60_0_VC14
//          BOOST_ROOT_LIB ==> C : \Program Files\boost\boost_1_60_0_VC14\stage\lib
//      - Project properties --> VC++ directories:
//          Include directories: $(BOOST_ROOT)
//          Library directories: $(BOOST_ROOT_LIB)
// Change history:
//      - Refer to GitHub comments related to each source file.
//

#include "pch.h"
#include "Test_boost_regex.h"

#include <iostream>
#include <boost/regex.hpp>

using namespace std;

Test_boost_regex::Test_boost_regex()
{
}


Test_boost_regex::~Test_boost_regex()
{
}

bool Test_boost_regex::Run()
{
    bool bRet = true;

    string s =
        "start: \n"
        "256 bytes from 11:22:33:44:55:66 in 12.34 ms \n"
        "256 bytes from 11:22:33:44:55:66 in 12.34 ms \n"
        "256 bytes from 11:22:33:44:55:66 in 12.34 ms \n"
        "256 bytes from 11:22:33:44:55:66 in 12.34 ms \n"
        "end.\n";
    string p =
        "(\\d+) bytes from "
        "(\\w{2}:\\w{2}:\\w{2}:\\w{2}:\\w{2}:\\w{2}) in "
        "(\\d+\\.\\d+) ms";

    const int matches[] = { 3,2,1 };
    boost::regex re(p);
    boost::sregex_token_iterator it(s.begin(), s.end(), re, matches), end;

    for (int count = 1; it != end; count++, it++)
    {
        cout << it->str() << " ";
        if (count % 3 == 0)
        {
            cout << endl;
        }
    }

    return bRet;
}
