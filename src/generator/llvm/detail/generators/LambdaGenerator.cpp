#include "generator/llvm/detail/generators/LambdaGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Lambda& lambda)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(lambda).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}