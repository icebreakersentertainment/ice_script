#include "analyzer/detail/analyzers/ArglistNodeAnalyzer.hpp"

#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Arglist process(Context& context, const ast::ArglistNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Arglist arglist{};

    const std::vector<std::shared_ptr<Type>>& expectedTypes = scope.expectedTypes();

    for (int i=0; i < node.value.size(); ++i)
//    for (const auto& argument : node.value)
    {
        const auto& argument = node.value[i];

        scope.pushExpectedTypes({expectedTypes[i]});

        const auto& assignNode = argument.assignNode;
        const auto assign = process(context, assignNode.get());

        arglist.arguments.push_back(asg::Argument{assign});

        scope.popExpectedTypes();
    }

    return arglist;
}

}}}