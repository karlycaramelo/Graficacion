#include "ShaderException.h"

ShaderException::ShaderException(const string& msg): runtime_error(msg)
{
    //ctor
}

ShaderException::~ShaderException()
{
    //dtor
}
