#include "generator/llvm/detail/generators/TypedefinitionGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Typedefinition& typedefinition)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(typedefinition).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}