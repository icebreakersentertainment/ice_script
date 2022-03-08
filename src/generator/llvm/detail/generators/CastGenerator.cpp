#include "generator/llvm/detail/generators/CastGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Cast& cast)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(cast).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}