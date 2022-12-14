#include "generator/llvm/detail/generators/AssignoperatorGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Assignoperator& assignoperator)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(assignoperator).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}