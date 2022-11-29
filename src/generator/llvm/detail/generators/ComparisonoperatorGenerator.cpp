#include "generator/llvm/detail/generators/ComparisonoperatorGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ::llvm;
using namespace ice_script::asg;

BinaryOperatorFactory process(Context& context, Llvm& llvm, const asg::Comparisonoperator& comparisonoperator)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(comparisonoperator).name())

    Scope& scope = context.scope();

    return BinaryOperatorFactory(context, llvm);
}

}}}}