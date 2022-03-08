#include "generator/llvm/detail/generators/TypeGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Type& type)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(type).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}