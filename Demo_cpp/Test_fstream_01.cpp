// Author:      Li Leo Wang
// Start Date:  2019-06-05
// Description:
//      - Test fstream 
//      - Add "_CRT_SECURE_NO_WARNINGS" to project properties --> preprocessor
// Change history:
//      - Refer to GitHub comments related to each source file.
//

#include "pch.h"
#include "Test_fstream_01.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

Test_fstream_01::Test_fstream_01()
{
}


Test_fstream_01::~Test_fstream_01()
{
}

bool Test_fstream_01::Run()
{
    bool bRet = true;
    string fn = "c:\\temp\\test.txt";

    if (bRet)
    {
        ofstream ofs;
        ofs.open(fn, ios::out);
        if (ofs.is_open())
        {
            time_t now = time(0);

            ofs << ctime(&now) << endl;
        }
        else
        {
            cout << "cannot write to file " << fn.c_str() << endl;
            bRet = false;
        }
        ofs.close();
    }

    if (bRet)
    {
        ifstream ifs;
        ifs.open(fn, ios::in);
        if (ifs.is_open())
        {
            cout << ifs.rdbuf() << endl;
        }
        else
        {
            cout << "cannot read file " << fn.c_str() << endl;
            bRet = false;
        }
    }

    return bRet;
}