#include "generator/llvm/detail/generators/WhileGenerator.hpp"

#include "generator/llvm/detail/generators/AssignGenerator.hpp"
#include "generator/llvm/detail/generators/StatementGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;
using namespace ::llvm;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::While& whileStatement)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(whileStatement).name())

    Scope& scope = context.scope();

    ::llvm::Function* function = llvm.builder().GetInsertBlock()->getParent();

    BasicBlock* loopBasicBlock = BasicBlock::Create(llvm.context(), "loop", function);
    BasicBlock* loopBodyBasicBlock = BasicBlock::Create(llvm.context(), "loop_body");
    BasicBlock* loopDoneBasicBlock = BasicBlock::Create(llvm.context(), "loop_done");

    llvm.builder().CreateBr(loopBasicBlock);

    llvm.builder().SetInsertPoint(loopBasicBlock);

//    scope.set(variableOrExpressionstatValue);
    Value* assignValue = process(context, llvm, whileStatement.assign.get());

    ::llvm::BranchInst* branchInstruction = llvm.builder().CreateCondBr(assignValue, loopBodyBasicBlock, loopDoneBasicBlock);

    function->getBasicBlockList().push_back(loopBodyBasicBlock);
    llvm.builder().SetInsertPoint(loopBodyBasicBlock);

    Value* statementValue = process(context, llvm, whileStatement.statement.get());

    llvm.builder().CreateBr(loopBasicBlock);

    function->getBasicBlockList().push_back(loopDoneBasicBlock);
    llvm.builder().SetInsertPoint(loopDoneBasicBlock);

    return nullptr;
}

}}}}