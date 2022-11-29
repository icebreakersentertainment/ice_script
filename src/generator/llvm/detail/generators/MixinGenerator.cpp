#include "generator/llvm/detail/generators/MixinGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Mixin& mixin)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(mixin).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}