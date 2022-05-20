#pragma once
#include "MyException.h"
class WriterFileException :
    public MyException
{
public:
    WriterFileException(std::string s)
        :MyException(s)
    {
        text.insert(0, "can't write file {}");
    }
};

