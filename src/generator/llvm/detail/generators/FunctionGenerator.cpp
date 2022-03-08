#include <llvm/IR/Function.h>

#include "generator/llvm/detail/generators/FunctionGenerator.hpp"

#include "generator/llvm/detail/generators/StatblockGenerator.hpp"

//#include "generator/llvm/detail/visitors/FunctionVisitor.hpp"

#include "generator/llvm/detail/LlvmUtilities.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ::llvm;
using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Function& function)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(function).name())

    Scope& scope = context.scope();
    Scope& currentScope = context.pushScope();

    auto parameterList = createParameterTypeList(llvm.context(), function.parameters);
    auto returnType = toLlvmType(llvm.context(), *function.returnType);

    ::llvm::FunctionType* functionType = ::llvm::FunctionType::get(returnType, parameterList, false);

    ::llvm::Function* func = ::llvm::Function::Create(functionType, ::llvm::Function::ExternalLinkage, function.name, &llvm.module());

    scope.add(function.name, *func);
    currentScope.add(function.name, *func);
    currentScope.set(func);

    // Set names for all arguments.
    auto argsIterator = func->args();
    for (int i = 0; i < func->arg_size(); ++i)
    {
        auto arg = func->getArg(i);
        const auto& parameter = function.parameters[i];

//            const auto& type = parameter.get<0>().get();
//            const auto& typeMod = parameter.get<1>().get();
//            const auto& expression = parameter.get<3>();
//        auto param = Type::getInt64Ty(llvm.context());
//        auto paramType = llvmType(type);

        arg->setName(parameter.name);
    }

    // set parameter variables to be in scope
    for (auto& arg : func->args())
    {
        currentScope.add(std::string(arg.getName()), arg);
    }

    BasicBlock* BB = BasicBlock::Create(llvm.context(), "entry", func);
    llvm.builder().SetInsertPoint(BB);

//    auto expressionterm = process(logger, context, llvm, expression.expressionterm.get());
    process(logger, context, llvm, function.body.get());

//    FunctionVisitor visitor{logger, context, llvm};
//    for (const auto& variableOrStatement : function.body.get().values)
//    {
//        boost::apply_visitor(visitor, variableOrStatement);
////        boost::apply_visitor(*this, variableOrStatement);
//    }

    context.popScope();

    return nullptr;
}

}}}}