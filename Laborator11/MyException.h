#pragma once
#include <exception>
#include <string>
class MyException :
    public std::exception
{
protected:
    std::string text;
public:
    MyException(std::string s)
        :text(s)
    {

    }
 
    const char * what()
    {
        return text.c_str();
    }
};

