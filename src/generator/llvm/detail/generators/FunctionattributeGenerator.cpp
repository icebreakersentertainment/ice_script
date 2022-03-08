#include "generator/llvm/detail/generators/FunctionattributeGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Functionattribute& functionattribute)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(functionattribute).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}