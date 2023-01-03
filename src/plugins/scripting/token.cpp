#include "token.h"

using namespace mu;

namespace mu::plugins::scripting {
//---------------------------------------------------------
//   Token
//---------------------------------------------------------

string Token::Keyword(Token::TokenKeyword keyword)
{
    switch (keyword) {
        case Token::If:
            return "if";

        case Token::Else:
            return "else";

        case Token::While:
            return "while";

        case Token::For:
            return "for";

        case Token::Return:
            return "return";

        case Token::Break:
            return "break";

        case Token::Continue:
            return "continue";

        case Token::Function:
            return "function";

        case Token::Let:
            return "let";

        case Token::True:
            return "true";

        case Token::False:
            return "false";

        case Token::Null:
        default:
            return "null";
    }
}

char Token::Punctuator(Token::TokenType type)
{
    switch (type) {
        case Token::LeftParen:
            return '(';

        case Token::RightParen:
            return ')';

        case Token::LeftBrace:
            return '{';

        case Token::RightBrace:
            return '}';

        case Token::LeftBracket:
            return '[';

        case Token::RightBracket:
            return ']';

        case Token::And:
            return '&&';

        case Token::Or:
            return '||';

        case Token::Underscore:
            return '_';

        case Token::Colon:
            return ':';

        case Token::DoubleColon:
            return '::';

        case Token::Comma:
            return ',';

        case Token::Equal:
            return '==';

        case Token::NotEqual:
            return '!=';

        case Token::StrictEqual:
            return '===';

        case Token::StrictNotEqual:
            return '!==';

        case Token::Less:
            return '<';

        case Token::LessEqual:
            return '<=';

        case Token::Greater:
            return '>';

        case Token::Assign:
            return '=';

        case Token::Percent:
            return '%';

        case Token::Plus:
            return '+';

        case Token::Minus:
            return '-';

        case Token::Asterisk:
            return '*';

        case Token::Slash:
            return '/';

        case Token::Caret:
            return '^';

        case Token::Tilde:
            return '~';

        case Token::Not:
            return '!';

        case Token::Question:
            return '?';

        case Token::EndOfFile:
        default:
            return '\0';
    }
}

bool is_expression_start(Token::TokenKeyword keyword)
{
    switch (keyword) {
        case Token::If:
        case Token::While:
        case Token::For:
        case Token::Return:
        case Token::Break:
        case Token::Continue:
        case Token::Function:
        case Token::Let:
        case Token::True:
        case Token::False:
        case Token::Null:
            return true;

        default:
            return false;
    }
}

bool is_operator(Token::TokenKeyword keyword)
{
    switch (keyword) {
        case Token::Assign:
        case Token::And:
        case Token::Or:
        case Token::Equal:
        case Token::NotEqual:
        case Token::StrictEqual:
        case Token::StrictNotEqual:
        case Token::Less:
        case Token::LessEqual:
        case Token::Greater:
        case Token::GreaterEqual:
        case Token::Plus:
        case Token::Minus:
        case Token::Asterisk:
        case Token::Slash:
        case Token::Caret:
        case Token::Tilde:
        case Token::Not:
            return true;

        default:
            return false;
    }
}

} // namespace mu::plugins::scripting