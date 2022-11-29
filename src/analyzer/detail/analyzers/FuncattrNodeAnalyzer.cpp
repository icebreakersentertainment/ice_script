#include "analyzer/detail/analyzers/FuncattrNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Functionattribute process(Context& context, const ast::FuncattrNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Functionattribute functionattribute{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return functionattribute;
}

}}}