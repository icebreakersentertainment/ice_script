#include "generator/llvm/detail/generators/TypemodifierGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const Typemodifier& typemodifier)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(typemodifier).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}