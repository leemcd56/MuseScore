#include <string>
#include <vector>

#include "lexer.h"
#include "token.h"

#ifndef __PLUGIN_RUNTIME_PARSER_H__
#define __PLUGIN_RUNTIME_PARSER_H__

namespace mu::plugins::scripting {

class Parser
{
    typedef Parser ThisType;

public:
    Parser(Lexer tokens);

    bool match(Token::TokenType type);

    void Register(Token::TokenType type, Parser *parser);

    void ParseExpression(int precedence);

    Token consume(Token::TokenType type);

    Token consume();

    Token peek(int distance);

private:
    Lexer _tokens;
    vector<Token> _read;
    map<Token::TokenType, Parser> _prefixes;
    map<Token::TokenType, Parser> _infixes;
};

} // namespace mu::plugins::scripting

#endif