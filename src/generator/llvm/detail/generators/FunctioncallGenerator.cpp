#include "generator/llvm/detail/generators/FunctioncallGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Functioncall& functioncall)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(functioncall).name())

    Scope& scope = context.scope();

    std::vector<::llvm::Value*> arguments{};

    auto value = scope.value();

    if (value->getType()->isDoubleTy() || value->getType()->isFloatTy())
    {
        auto alloca = llvm.builder().CreateAlloca(value->getType(), 0, "");
        auto store = llvm.builder().CreateStore(value, alloca);
        auto load = llvm.builder().CreateLoad(alloca);

//    return llvm.builder().CreateIntCast(value, ::llvm::Type::getInt32Ty(llvm.context()), true);
        return llvm.builder().CreateFPToUI(load, ::llvm::Type::getInt8Ty(llvm.context()));
    }

    return llvm.builder().CreateIntCast(value, ::llvm::Type::getInt32Ty(llvm.context()), true);
//    return value;

//    Value* constant1 = ConstantInt::get(IntegerType::getInt64Ty(*context), 1);
//    Value* constant2 = ConstantInt::get(IntegerType::getInt64Ty(*context), 1);
//    ArgsV.push_back(constant1);
//    ArgsV.push_back(constant2);
//
//    Value* result = builder->CreateCall(testFunction, ArgsV, "calltmp");

//    return nullptr;
}

}}}}