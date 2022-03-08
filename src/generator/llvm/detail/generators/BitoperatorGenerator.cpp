#include "generator/llvm/detail/generators/BitoperatorGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

BinaryOperatorFactory process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Bitoperator& bitoperator)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(bitoperator).name())

    Scope& scope = context.scope();

    return BinaryOperatorFactory(logger, context, llvm);
}

}}}}