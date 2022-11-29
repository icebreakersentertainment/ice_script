#include "generator/llvm/detail/generators/AssignGenerator.hpp"

#include "generator/llvm/detail/generators/ConditionGenerator.hpp"
#include "generator/llvm/detail/generators/FunctioncallGenerator.hpp"

#include "asg/AsgPrinter.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Assign& assign)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(assign).name())

    Scope& scope = context.scope();
    
    std::cout << "HIMOM" << std::endl;
    ice_script::asg::AsgPrinter{std::cout}(assign);

    auto value = process(context, llvm, assign.condition.get());

    if (assign.functioncall)
    {
        scope.set(value);

        value = process(context, llvm, assign.functioncall.get().get());
    }

    return value;
}

}}}}