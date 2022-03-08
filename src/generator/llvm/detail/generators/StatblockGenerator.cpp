#include "generator/llvm/detail/generators/StatblockGenerator.hpp"

#include "generator/llvm/detail/visitors/StatblockVisitor.hpp"

#include "generator/llvm/detail/LlvmUtilities.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Statblock& statblock)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(statblock).name())

    Scope& scope = context.scope();

    StatblockVisitor visitor{logger, context, llvm};
    for (const auto& variableOrStatement : statblock.values)
    {
        boost::apply_visitor(visitor, variableOrStatement);
    }

    return nullptr;
}

}}}}