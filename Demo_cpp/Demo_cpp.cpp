// Author:      Li Leo Wang
// Start Date:  2019-05-09
// Description:
//      - Demo project for C/C++  features
// Notes:
//      - The individual features are implemented in separated classes.
// Change history:
//      - Refer to GitHub comments related to each source file.
//

#include "pch.h"
#include <iostream>
#include "Test_boost_regex.h"

int main()
{
    bool bRet = true;

    Test_boost_regex test_boost_regex;
    bRet = test_boost_regex.Run();

    printf("%s \n", bRet ? "pass" : "fail");
    getchar();
    return 0;
}
