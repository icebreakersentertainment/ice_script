#include "generator/llvm/detail/generators/ContinueGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Continue& continueStatement)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(continueStatement).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}