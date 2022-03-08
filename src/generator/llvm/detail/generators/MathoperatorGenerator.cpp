#include "generator/llvm/detail/generators/MathoperatorGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ::llvm;
using namespace ice_script::asg;

BinaryOperatorFactory process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Mathoperator& mathoperator)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(mathoperator).name())

    Scope& scope = context.scope();

    return BinaryOperatorFactory(logger, context, llvm);
//    BinaryOperator* r = llvm.builder().CreateFAdd(L, R, "addtmp");
}

}}}}