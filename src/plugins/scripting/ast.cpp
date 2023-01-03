#include <vector>

#include "ast.h"
#include "position.h"

using namespace std;
using namespace mu::plugins::scripting;

namespace mu::plugins::scripting {
    struct Identifier
    {
        string *name;
    };

    struct ItemName {
        Spanned<Identifier>* name;
        vector<Spanned<Identifier*>> type_params;
    };

    struct FunctionParameters
    {
        Spanned<Identifier>* name;
    };

    struct Function
    {
        Span complete_span;
        Identifier* name;
        FunctionParameters params;
        Spanned<AST::Type> return_type;
        vector<AST::Statement> body;
    };

    struct Program
    {
        vector<Function> functions;
        vector<Identifier*> possible_functions;
    };
}