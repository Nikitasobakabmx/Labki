#include "except.h"

except::except(char* str)
{
    string = str;
}

const char* except::what() const noexcept
{
    return string;
}

except::~except()
{
    
}