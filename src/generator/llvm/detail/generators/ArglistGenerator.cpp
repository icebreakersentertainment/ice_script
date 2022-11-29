#include "generator/llvm/detail/generators/ArglistGenerator.hpp"

#include "generator/llvm/detail/generators/AssignGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

std::vector<::llvm::Value*> process(Context& context, Llvm& llvm, const asg::Arglist& arglist)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(arglist).name())

    Scope& scope = context.scope();

    std::vector<::llvm::Value*> arguments{};

    for (const auto& argument : arglist.arguments)
    {
        arguments.push_back(process(context, llvm, argument.assign.get()));
    }

    return arguments;
}

}}}}