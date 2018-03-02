#ifndef SHADEREXCEPTION_H
#define SHADEREXCEPTION_H

#include <iostream>
#include <string>

using namespace std;


class ShaderException : public runtime_error
{
    public:
        ShaderException(const string& msg);
        virtual ~ShaderException();
};

#endif // SHADEREXCEPTION_H
