#include "generator/llvm/detail/generators/ExpressionvalueGenerator.hpp"

#include "generator/llvm/detail/visitors/ExpressionvalueVisitor.hpp"

#include "generator/llvm/detail/LlvmUtilities.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Expressionvalue& expressionvalue)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(expressionvalue).name())

    Scope& scope = context.scope();

    ExpressionvalueVisitor visitor{logger, context, llvm};
    return boost::get<::llvm::Value*>(boost::apply_visitor(visitor, expressionvalue.value));

//    return nullptr;
}

}}}}