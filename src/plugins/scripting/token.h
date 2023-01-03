#include <string>

using namespace std;

#ifndef __PLUGIN_RUNTIME_TOKEN_H__
#define __PLUGIN_RUNTIME_TOKEN_H__

namespace mu::plugins::scripting {
class Token
{
    typedef Token ThisType;

public:
    enum TokenKeyword
    {
        None,
        If,
        Else,
        For,
        While,
        Do,
        Break,
        Continue,
        Return,
        Let,
        Function,
        True,
        False,
        Null,
    };

    enum TokenType
    {
        LeftParen,
        RightParen,
        LeftBrace,
        RightBrace,
        LeftBracket,
        RightBracket,
        And,
        Or,
        Underscore,
        Colon,
        DoubleColon,
        Semicolon,
        Comma,
        Equal,
        NotEqual,
        StrictEqual,
        StrictNotEqual,
        Less,
        LessEqual,
        Greater,
        GreaterEqual,
        Assign,
        Percent,
        Plus,
        Minus,
        Asterisk,
        Slash,
        Caret,
        Tilde,
        Not,
        Question,
        EndOfFile,
    };

    Token(TokenType type, const string &value, int line, int column) {}

    TokenKeyword keyword() const { return TokenKeyword::None; }

    TokenType type() const { return TokenType::EndOfFile; }

    bool is_expression_start(TokenKeyword keyword) const { return false; }

    bool is_operator(TokenKeyword keyword) const { return false; }

    const string &value() const { return string(); }

    int line() const { return 0; }

    int column() const { return 0; }

    static string Keyword (TokenKeyword keyword) { return "null"; }

    static char Punctuator(TokenType type) { return '\0'; }
};
} // namespace mu::plugins::scripting

#endif