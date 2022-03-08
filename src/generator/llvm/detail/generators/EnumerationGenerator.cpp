#include "generator/llvm/detail/generators/EnumerationGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Enumeration& enumeration)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(enumeration).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}