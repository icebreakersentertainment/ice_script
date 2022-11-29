#include "generator/llvm/detail/generators/SwitchGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Switch& switchStatement)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(switchStatement).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}