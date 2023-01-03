#ifndef __PLUGIN_RUNTIME_AST_H__
#define __PLUGIN_RUNTIME_AST_H__

namespace mu::plugins::scripting {

class AST
{
    typedef AST ThisType;

public:
    enum Expression {
        Binary,
        Unary,
        Call,
        Field,
        Name,
        Literal,
        Cast,
    };

    enum BinaryOperators
    {
        Equal,
        NotEqual,
        StrictEqual,
        StrictNotEqual,
        Less,
        LessEqual,
        Greater,
        GreaterEqual,
        Plus,
        Minus,
        Asterisk,
        Slash,
        Percent,
        Caret,
        And,
        Or,
    };

    enum UnaryOperators
    {
        Plus,
        Minus,
        Not,
        Typeof,
        Void,
        Delete,
    };

    enum Literal
    {
        String,
        Number,
        Boolean,
        Null,
    };

    enum Mutability
    {
        Mutable,
        Immutable,
    };

    enum Statement
    {
        Block,
        Expression,
        If,
        For,
        While,
        DoWhile,
        Break,
        Continue,
        Return,
        Let,
        Function,
    };

    enum Type
    {
        Void,
        Boolean,
        Number,
        String,
        Object,
        Array,
    };

};

} // namespace mu::plugins::scripting

#endif