#include "generator/llvm/detail/generators/VariableaccessGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Variableaccess& variableaccess)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(variableaccess).name())

    Scope& scope = context.scope();

    return &scope.getAllocaInst(variableaccess.name);
}

}}}}