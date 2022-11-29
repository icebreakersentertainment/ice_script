#include "generator/llvm/detail/generators/ImportGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Import& import)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(import).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}