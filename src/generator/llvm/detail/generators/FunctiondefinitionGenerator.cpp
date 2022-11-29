#include "generator/llvm/detail/generators/FunctiondefinitionGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Functiondefinition& functiondefinition)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(functiondefinition).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}