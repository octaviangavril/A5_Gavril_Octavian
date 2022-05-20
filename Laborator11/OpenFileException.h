#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "MyException.h"
#include <string>
class OpenFileException :
    public MyException
{
public:
    OpenFileException(std::string s) 
        :MyException(s)
    { 
        text.insert(0, "can't open file {}");
    }
};

