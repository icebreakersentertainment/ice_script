#include "generator/llvm/detail/generators/BreakGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Break& breakStatement)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(breakStatement).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}