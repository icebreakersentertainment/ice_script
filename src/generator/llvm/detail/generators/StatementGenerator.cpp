#include "generator/llvm/detail/generators/StatementGenerator.hpp"

#include "generator/llvm/detail/visitors/StatementVisitor.hpp"

#include "generator/llvm/detail/LlvmUtilities.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Statement& statement)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(statement).name())

    Scope& scope = context.scope();

    StatementVisitor visitor{logger, context, llvm};
    return boost::get<::llvm::Value*>(boost::apply_visitor(visitor, statement.value));

//    return nullptr;
}

}}}}