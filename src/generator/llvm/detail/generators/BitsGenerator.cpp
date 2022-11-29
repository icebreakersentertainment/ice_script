#include "generator/llvm/detail/generators/BitsGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Bits& bits)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(bits).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}