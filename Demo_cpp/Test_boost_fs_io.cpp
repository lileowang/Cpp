// Author:      Li Leo Wang
// Start Date:  2019-06-06
// Description:
//      - Test boost filesystem and iostreams 
// Change history:
//      - Refer to GitHub comments related to each source file.
//

#include "pch.h"
#include "Test_boost_fs_io.h"
#include <iostream>
#include <string>
#include <sstream>
#include <boost/filesystem.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/file.hpp>

using namespace std;
namespace fs = boost::filesystem;
namespace io = boost::iostreams;

Test_boost_fs_io::Test_boost_fs_io()
{
}


Test_boost_fs_io::~Test_boost_fs_io()
{
}

bool Test_boost_fs_io::Run()
{
    bool bRet = true;
    string fn = "..\\Demo_cpp\\Test_boost_fs_io.cpp";

    try
    {
        cout << fs::file_size(fn) << endl;

        io::file_source f(fn);
        if (f.is_open())
        {
            io::stream<io::file_source> ms(f);
            //cout << ms.rdbuf() << endl;

            // convert to string
            std::stringstream ss;
            ss << ms.rdbuf();
            cout << ss.str() << endl;
        }
        else
        {
            cout << "cannot open file " << fn.c_str() << endl;
            bRet = false;
        }
    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
        bRet = false;
    }

    return bRet;
}
