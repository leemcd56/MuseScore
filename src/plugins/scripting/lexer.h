#include <map>
#include <string>

#ifndef __PLUGIN_RUNTIME_LEXER_H__
#define __PLUGIN_RUNTIME_LEXER_H__

namespace mu::plugins::scripting {

class Lexer
{
    typedef Lexer ThisType;

public:
    Lexer(string text);

    Token Next();

private:
    map<char, Token::TokenType> _punctuators;
    string _source;
    int _index;
};

} // namespace mu::plugins::scripting

#endif