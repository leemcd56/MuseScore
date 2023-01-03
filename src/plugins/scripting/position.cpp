#include <algorithm>

#include "position.h"

using namespace std;

namespace mu::plugins::scripting
{
//---------------------------------------------------------
//   Position
//---------------------------------------------------------

Position::Position(int line, int column)
{
    _line = line;
    _column = column;
}

int Position::column() const
{
    return _column;
}

int Position::line() const
{
    return _line;
}

Position* Position::backward(int count)
{
    if (_column < count) {
        _column = 0;
    }
    else {
        _column -= count;
    }
}

Position* Position::forward(int count)
{
    _column += count;
}

Position* span_to(const Position &other, int to)
{
    return new Position(other.line(), to);
}

Span::Span(Position* start, Position* end)
{
    _start = start;
    _end = end;
}

Position* Span::start() const
{
    return _start;
}

Position* Span::end() const
{
    return _end;
}

Span* Span::merge(const Span &other)
{
    int start = min(_start->column(), other.start()->column());
    int end = max(_end->column(), other.end()->column());

    Position position = Position(_start->line(), start);
    return new Span(&position, span_to(position, end));
}

} // namespace mu::plugins::scripting