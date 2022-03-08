#include "generator/llvm/detail/generators/InterfaceGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Interface& interfaceData)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(interfaceData).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}