#include "ast.h"
#include "parser.h"
#include "position.h"

using namespace mu;

namespace mu::plugins::scripting {
//---------------------------------------------------------
//   Parser
//---------------------------------------------------------

Parser::Parser(Lexer tokens)
{
    _tokens = tokens;
}

void Parser::Register(Token::TokenType type, Parser *parser)
{
    _prefixes[type] =* parser;
}

void Parser::ParseExpression(int precedence)
{
    Token token = _tokens.Next();
    Parser prefix = _prefixes[token.type()];

    prefix.ParseExpression(precedence);
}

Token Parser::consume(Token::TokenType type)
{
    Token token = _tokens.Next();

    if (token.type() != type) {
        throw std::runtime_error("Unexpected token");
    }

    return token;
}

Token Parser::consume()
{
    return _tokens.Next();
}

Token Parser::peek(int distance)
{
    while (_read.size() <= distance) {
        _read.push_back(_tokens.Next());
    }

    return _read[distance];
}

bool Parser::match(Token::TokenType type)
{
    return peek(0).type() == type;
}

} // namespace mu::plugins::scripting