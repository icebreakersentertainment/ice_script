#include "generator/llvm/detail/generators/DowhileGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Dowhile& dowhile)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(dowhile).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}