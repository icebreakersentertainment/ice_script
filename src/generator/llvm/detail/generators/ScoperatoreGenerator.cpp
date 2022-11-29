#include "generator/llvm/detail/generators/ScoperatoreGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Scoperatore& scoperatore)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(scoperatore).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}