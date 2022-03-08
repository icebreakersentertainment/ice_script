#include "generator/llvm/detail/generators/ScriptGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Script& script)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(script).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}