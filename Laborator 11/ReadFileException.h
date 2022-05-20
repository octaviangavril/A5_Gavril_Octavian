#pragma once
#include "MyException.h"
#include <string>
class ReadFileException :
    public MyException
{
public:
    ReadFileException(std::string s)
        :MyException(s)
    {
        text.insert(0, "can't read file {}");
    }
};

