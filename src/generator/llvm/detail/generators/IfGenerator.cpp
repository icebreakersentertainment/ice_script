#include "generator/llvm/detail/generators/IfGenerator.hpp"

#include "generator/llvm/detail/generators/AssignGenerator.hpp"
#include "generator/llvm/detail/generators/StatementGenerator.hpp"

#include "asg/AsgPrinter.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::If& ifStatement)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(ifStatement).name())

    Scope& scope = context.scope();

    ::llvm::Function* function = llvm.builder().GetInsertBlock()->getParent();

    auto assignValue = process(context, llvm, ifStatement.assign.get());

    ::llvm::BasicBlock* basicBlockTrue = ::llvm::BasicBlock::Create(llvm.context(), "then", function);
    ::llvm::BasicBlock* basicBlockFalse = nullptr;
    ::llvm::BasicBlock* basicBlockDone = ::llvm::BasicBlock::Create(llvm.context(), "ifcont");

    if (ifStatement.optionalStatement)
    {
        basicBlockFalse = ::llvm::BasicBlock::Create(llvm.context(), "else");
    }

    ::llvm::BranchInst* branchInstruction = nullptr;

    if (!basicBlockFalse)
    {
        branchInstruction = llvm.builder().CreateCondBr(assignValue, basicBlockTrue, basicBlockDone);
        scope.set(basicBlockTrue);
        llvm.builder().SetInsertPoint(basicBlockTrue);
    }
    else
    {
        branchInstruction = llvm.builder().CreateCondBr(assignValue, basicBlockTrue, basicBlockFalse);
    }

    scope.set(basicBlockTrue);
    llvm.builder().SetInsertPoint(basicBlockTrue);

    auto statementValue = process(context, llvm, ifStatement.statement.get());

    // If the statblock is empty statementValue will be null
    if (!statementValue || !::llvm::isa<::llvm::ReturnInst>(statementValue))
    {
        llvm.builder().CreateBr(basicBlockDone);
    }

    // Codegen of 'Then' can change the current block, update ThenBB for the PHI.
    basicBlockTrue = llvm.builder().GetInsertBlock();

    ::llvm::Value* optionalStatementValue = nullptr;

    if (ifStatement.optionalStatement)
    {
        function->getBasicBlockList().push_back(basicBlockFalse);

        scope.set(basicBlockFalse);
        llvm.builder().SetInsertPoint(basicBlockFalse);

        optionalStatementValue = process(context, llvm, ifStatement.optionalStatement.get().get());

        // If the statblock is empty optionalStatementValue will be null
        if (!optionalStatementValue || !::llvm::isa<::llvm::ReturnInst>(optionalStatementValue))
        {
            llvm.builder().CreateBr(basicBlockDone);
        }

        // codegen of 'Else' can change the current block, update ElseBB for the PHI.
        basicBlockFalse = llvm.builder().GetInsertBlock();
    }

    // Emit merge block.
    function->getBasicBlockList().push_back(basicBlockDone);
    scope.set(basicBlockDone);
    llvm.builder().SetInsertPoint(basicBlockDone);

    return nullptr;
}

}}}}