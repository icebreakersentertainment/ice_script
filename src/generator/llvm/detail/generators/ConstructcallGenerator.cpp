#include "generator/llvm/detail/generators/ConstructcallGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Constructcall& constructcall)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(constructcall).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}