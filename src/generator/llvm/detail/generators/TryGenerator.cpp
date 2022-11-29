#include "generator/llvm/detail/generators/TryGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Try& tryStatement)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(tryStatement).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}