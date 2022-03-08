#include "generator/llvm/detail/generators/LiteralGenerator.hpp"

#include "generator/llvm/detail/visitors/LiteralVisitor.hpp"

#include "generator/llvm/detail/LlvmUtilities.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Literal& literal)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(literal).name())

    Scope& scope = context.scope();

    LiteralVisitor visitor{logger, context, llvm};
    return boost::get<::llvm::Value*>(boost::apply_visitor(visitor, literal.value));
}

}}}}