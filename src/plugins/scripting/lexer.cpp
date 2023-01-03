#include "lexer.h"
#include "token.h"

using namespace mu;
using namespace mu::plugins::scripting;

namespace mu::plugins::scripting {
//---------------------------------------------------------
//   Lexer
//---------------------------------------------------------

Lexer::Lexer(std::string text)
{
    _punctuators = map<char, Token::TokenType>();
    _index = 0;
    _source = text;

    for (Token::TokenType type = Token::TokenType::LeftParen; type <= Token::TokenType::Colon; type = static_cast<Token::TokenType>(static_cast<int>(type) + 1))
    {
        _punctuators[Token::Punctuator(type)] = type;
    }
}

Token Lexer::Next()
{
    while(_index < _source.length()) {
        char c = _source[_index++];

        if (_punctuators.find(c) != _punctuators.end()) {
            return Token(_punctuators[c], string(1, c), 0, 0);
        }
        else if (isalpha(c)) {
            string value = string(1, c);

            while (_index < _source.length() && isalnum(_source[_index])) {
                value += _source[_index++];
            }

            return Token(Token::TokenType::EndOfFile, value, 0, 0);
        }
        else if (isdigit(c)) {
            string value = string(1, c);

            while (_index < _source.length() && isdigit(_source[_index])) {
                value += _source[_index++];
            }

            return Token(Token::TokenType::EndOfFile, value, 0, 0);
        }
        else if (isspace(c)) {
            continue;
        }
        else {
            return Token(Token::TokenType::EndOfFile, string(1, c), 0, 0);
        }
    }

    return Token(Token::TokenType::EndOfFile, "", 0, 0);
}

} // namespace mu::plugins::scripting