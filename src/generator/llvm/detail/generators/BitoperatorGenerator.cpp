#include "generator/llvm/detail/generators/BitoperatorGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

BinaryOperatorFactory process(Context& context, Llvm& llvm, const asg::Bitoperator& bitoperator)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(bitoperator).name())

    Scope& scope = context.scope();

    return BinaryOperatorFactory(context, llvm);
}

}}}}