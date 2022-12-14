#include "generator/llvm/detail/generators/InitlistGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Initlist& initlist)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(initlist).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}