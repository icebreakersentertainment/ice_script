#include "generator/llvm/detail/generators/CaseGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Case& caseStatement)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(caseStatement).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}