// Author:      Li Leo Wang
// Start Date:  2019-05-09
// Description:
//      - Demo project for C/C++  features
// Notes:
//      - The individual features are implemented in separated classes.
//      - Add system environment variables:
//          BOOST_ROOT ==> C : \Program Files\boost\boost_1_60_0_VC14
//          BOOST_ROOT_LIB ==> C : \Program Files\boost\boost_1_60_0_VC14\stage\lib
//      - Project properties --> VC++ directories:
//          Include directories: $(BOOST_ROOT)
//          Library directories: $(BOOST_ROOT_LIB)
//      - Build configuration: x86 (not x64)
// Change history:
//      - Refer to GitHub comments related to each source file.
//

#include "pch.h"
#include <iostream>
#include "Test_boost_regex.h"

using namespace std;

int main()
{
    bool bRet = true;

    Test_boost_regex test_boost_regex;
    bRet = test_boost_regex.Run();

    //cout << (bRet ? "pass" : "fail") << endl;
    printf("%s \n", bRet ? "pass" : "fail");
    getchar();
    return 0;
}
