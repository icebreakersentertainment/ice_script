#include "generator/llvm/detail/generators/DatatypeGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Datatype& datatype)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(datatype).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}