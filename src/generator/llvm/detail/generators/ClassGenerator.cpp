#include "generator/llvm/detail/generators/ClassGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Class& classData)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(classData).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}