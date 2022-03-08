#include "generator/llvm/detail/generators/VariableGenerator.hpp"

#include "generator/llvm/detail/visitors/VariableVisitor.hpp"

#include "generator/llvm/detail/LlvmUtilities.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ::llvm;
using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Variable& variable)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(variable).name())

    Scope& scope = context.scope();

    auto type = toLlvmType(llvm.context(), *variable.type);

    auto alloca = llvm.builder().CreateAlloca(type, 0, variable.name);

    scope.add(variable.name, *alloca);

    VariableVisitor visitor{logger, context, llvm};
    auto value = boost::apply_visitor(visitor, variable.value);

////    auto value = boost::apply_visitor(*this, variable.value);

    Value* v = boost::get<Value*>(value);

    if (value.type() == typeid(Value*))
    {
        if (isa<AllocaInst>(v))
        {
            AllocaInst* a = dyn_cast<AllocaInst>(v);
            auto loadInstruction = llvm.builder().CreateLoad(a);
            llvm.builder().CreateStore(loadInstruction, alloca);
        }
        else if (isa<ConstantInt>(v))
        {
            llvm.builder().CreateStore(v, alloca);
        }
        else
        {
            llvm.builder().CreateStore(v, alloca);
        }
    }
    else// if (value.type() == typeid(monostate))
    {
        std::cout << "OOF" << std::endl;
    }

    return nullptr;
}

}}}}