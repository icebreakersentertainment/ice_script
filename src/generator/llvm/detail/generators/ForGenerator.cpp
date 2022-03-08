#include "generator/llvm/detail/generators/ForGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::For& forLoop)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(forLoop).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}