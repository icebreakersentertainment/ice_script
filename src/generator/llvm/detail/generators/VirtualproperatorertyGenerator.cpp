#include "generator/llvm/detail/generators/VirtualproperatorertyGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Virtualproperatorerty& virtualproperatorerty)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(virtualproperatorerty).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}