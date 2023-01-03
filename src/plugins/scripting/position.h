#ifndef __PLUGIN_RUNTIME_POSITION_H__
#define __PLUGIN_RUNTIME_POSITION_H__

namespace mu::plugins::scripting {

class Position
{
    typedef Position ThisType;

public:
    Position(int line, int column);

    int column() const;
    int line() const;

    Position* backward(int count);
    Position* forward(int count);
    Position* span_to(const Position &other);

private:
    int _column;
    int _line;
};

class Span
{
    typedef Span ThisType;

public:
    Span(Position* start, Position* end);

    Position* start() const;
    Position* end() const;

    Span* merge(const Span &other);

private:
    Position* _start;
    Position* _end;
};

template<typename T>
class Spanned
{
    typedef Spanned<T> ThisType;

public:
    Spanned(T value, Span* span)
    {
        _value = value;
        _span = span;
    }

    Span* span() const
    {
        return _span;
    }

    T value() const
    {
        return _value;
    }

private:
    Span* _span;
    T _value;
};

} // namespace mu::plugins::scripting

#endif