#include "generator/llvm/detail/generators/ParameterlistGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Parameterlist& parameterlist)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(parameterlist).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}