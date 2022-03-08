#include "analyzer/detail/analyzers/ClassNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Class process(logger::ILogger& logger, Context& context, const ast::ClassNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Class classData{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return classData;
}

}}}