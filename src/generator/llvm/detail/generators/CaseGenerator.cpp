#include "generator/llvm/detail/generators/CaseGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Case& caseStatement)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(caseStatement).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}