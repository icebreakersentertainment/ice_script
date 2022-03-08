#include "generator/llvm/detail/generators/ArglistGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Arglist& arglist)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(arglist).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}