#include <llvm/IR/Function.h>

#include "generator/llvm/detail/generators/FunctionGenerator.hpp"

#include "generator/llvm/detail/generators/StatblockGenerator.hpp"

#include "generator/llvm/detail/LlvmUtilities.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ::llvm;
using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Function& function)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(function).name())

    Scope& scope = context.scope();
    Scope& currentScope = context.pushScope();

    ::llvm::Function& func = context.llvmSymbolTable().getFunctionByKey(function.symbol->key());

    // scope.add(function.name, func);
    // currentScope.add(function.name, func);
    currentScope.set(&func);

    // set parameter variables to be in scope
    for (auto& arg : func.args())
    {
        currentScope.add(std::string(arg.getName()), arg);
    }

    BasicBlock* BB = BasicBlock::Create(llvm.context(), "entry", &func);
    
    currentScope.set(BB);
    llvm.builder().SetInsertPoint(BB);
    
    process(context, llvm, function.body.get());

    const BasicBlock& lastBasicBlock = func.back();
    
    // TODO
    if (lastBasicBlock.empty() || !lastBasicBlock.getTerminator())
    {
        llvm.builder().CreateRetVoid();
    }

    context.popScope();
    llvm.builder().SetInsertPoint(static_cast<BasicBlock*>(nullptr));

    return nullptr;
}

}}}}