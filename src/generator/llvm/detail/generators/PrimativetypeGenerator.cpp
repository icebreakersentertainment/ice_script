#include "generator/llvm/detail/generators/PrimativetypeGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Primativetype& primativetype)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(primativetype).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}