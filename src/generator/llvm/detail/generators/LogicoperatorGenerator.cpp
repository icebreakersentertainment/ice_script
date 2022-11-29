#include "generator/llvm/detail/generators/LogicoperatorGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

BinaryOperatorFactory process(Context& context, Llvm& llvm, const asg::Logicoperator& logicoperator)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(logicoperator).name())

    Scope& scope = context.scope();

    return BinaryOperatorFactory(context, llvm);
}

}}}}