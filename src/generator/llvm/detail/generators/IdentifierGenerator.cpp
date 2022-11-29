#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Identifier& identifier)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(identifier).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}