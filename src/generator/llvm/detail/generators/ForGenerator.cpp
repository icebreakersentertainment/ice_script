#include "generator/llvm/detail/generators/ForGenerator.hpp"

#include "generator/llvm/detail/generators/ExpressionstatGenerator.hpp"
#include "generator/llvm/detail/generators/AssignGenerator.hpp"
#include "generator/llvm/detail/generators/StatementGenerator.hpp"

#include "generator/llvm/detail/visitors/ForVisitor.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;
using namespace ::llvm;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::For& forLoop)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(forLoop).name())

    Scope& scope = context.scope();

    ::llvm::Function* function = llvm.builder().GetInsertBlock()->getParent();

    ForVisitor visitor{context, llvm};
    Value* variableOrExpressionstatValue = boost::get<::llvm::Value*>(boost::apply_visitor(visitor, forLoop.variableOrExpressionstat));

    BasicBlock* loopBasicBlock = BasicBlock::Create(llvm.context(), "loop", function);
    BasicBlock* loopBodyBasicBlock = BasicBlock::Create(llvm.context(), "loop_body");
    BasicBlock* loopEpilogueBasicBlock = BasicBlock::Create(llvm.context(), "loop_epilogue");
    BasicBlock* loopDoneBasicBlock = BasicBlock::Create(llvm.context(), "loop_done");

    llvm.builder().CreateBr(loopBasicBlock);

    llvm.builder().SetInsertPoint(loopBasicBlock);

    scope.set(variableOrExpressionstatValue);
    Value* expressionstatValue = process(context, llvm, forLoop.expressionstat.get());

    ::llvm::BranchInst* branchInstruction = llvm.builder().CreateCondBr(expressionstatValue, loopBodyBasicBlock, loopDoneBasicBlock);

    function->getBasicBlockList().push_back(loopBodyBasicBlock);
    llvm.builder().SetInsertPoint(loopBodyBasicBlock);

    Value* statementValue = process(context, llvm, forLoop.statement.get());

    llvm.builder().CreateBr(loopEpilogueBasicBlock);

    function->getBasicBlockList().push_back(loopEpilogueBasicBlock);
    llvm.builder().SetInsertPoint(loopEpilogueBasicBlock);

    for (const auto& assign : forLoop.assigns)
    {
        Value* assignValue = process(context, llvm, assign.get());
    }

    llvm.builder().CreateBr(loopBasicBlock);

    function->getBasicBlockList().push_back(loopDoneBasicBlock);
    llvm.builder().SetInsertPoint(loopDoneBasicBlock);

    return nullptr;
}

}}}}