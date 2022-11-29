#include <llvm/IR/Value.h>

#include "generator/llvm/detail/generators/FunctioncallGenerator.hpp"

#include "generator/llvm/detail/generators/ArglistGenerator.hpp"
#include "generator/llvm/detail/generators/AssignGenerator.hpp"

#include "asg/AsgPrinter.hpp"

#include "detail/SymbolKeyResolver.hpp"
#include "detail/Assert.hpp"

#include "exceptions/InvalidArgumentException.hpp"
#include "type/Type.hpp"
#include "type/TypeModifier.hpp"
#include "type/TypeQualifier.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;
using namespace ice_script::detail;

::llvm::Value* createPrimitiveCastFromFloatingPoint(Context& context, Llvm& llvm, const Type::TypeId toTypeId)
{
    Scope& scope = context.scope();

    auto value = scope.value();

    auto alloca = llvm.builder().CreateAlloca(value->getType(), 0, "");
    auto store = llvm.builder().CreateStore(value, alloca);
    auto load = llvm.builder().CreateLoad(alloca);

    switch (toTypeId)
    {
        case Type::TypeId::BOOLEAN: return llvm.builder().CreateFCmpUEQ(load, ::llvm::ConstantInt::get(::llvm::Type::getFloatTy(llvm.context()), 0.0f));
        case Type::TypeId::INTEGER8: return llvm.builder().CreateFPToUI(load, ::llvm::Type::getInt8Ty(llvm.context()));
        case Type::TypeId::INTEGER16: return llvm.builder().CreateFPToUI(load, ::llvm::Type::getInt16Ty(llvm.context()));
        case Type::TypeId::INTEGER32: return llvm.builder().CreateFPToUI(load, ::llvm::Type::getInt32Ty(llvm.context()));
        case Type::TypeId::INTEGER: return llvm.builder().CreateFPToUI(load, ::llvm::Type::getInt32Ty(llvm.context()));
        case Type::TypeId::INTEGER64: return llvm.builder().CreateFPToUI(load, ::llvm::Type::getInt64Ty(llvm.context()));
//        case Type::TypeId::UINTEGER8: llvm.builder().CreateFPToUI(load, ::llvm::Type::getInt8Ty(llvm.context()));

        default:
            throw InvalidArgumentException("");
    }

    return nullptr;
}

::llvm::Value* createPrimitiveCastFromInteger(Context& context, Llvm& llvm, const Type::TypeId toTypeId)
{
    Scope& scope = context.scope();

    auto value = scope.value();

//    auto alloca = llvm.builder().CreateAlloca(value->getType(), 0, "");
//    auto store = llvm.builder().CreateStore(value, alloca);
//    auto load = llvm.builder().CreateLoad(alloca);

    auto load = value;
    if (::llvm::isa<::llvm::AllocaInst>(load))
    {
        ::llvm::AllocaInst* allocaInst = ::llvm::dyn_cast<::llvm::AllocaInst>(load);
//            auto loadInstruction = llvm_->builder().CreateLoad(allocaInst);
        load = llvm.builder().CreateLoad(allocaInst);
    }
    else if (::llvm::isa<::llvm::GetElementPtrInst>(load))
    {
        ::llvm::GetElementPtrInst* getElementPtrInst = ::llvm::dyn_cast<::llvm::GetElementPtrInst>(load);
//            auto loadInstruction = llvm_->builder().CreateLoad(allocaInst);
        load = llvm.builder().CreateLoad(getElementPtrInst);
        // llvm.builder().CreateStore(loadInstruction, alloca);
    }
    
    while (load->getType()->isPointerTy())
    {
        load = llvm.builder().CreateLoad(load);
    }

    switch (toTypeId)
    {
        case Type::TypeId::BOOLEAN: return llvm.builder().CreateICmpEQ(load, ::llvm::ConstantInt::get(::llvm::Type::getInt32Ty(llvm.context()), 0));
//        case Type::TypeId::INTEGER8: llvm.builder().CreateFPToUI(load, ::llvm::Type::getInt8Ty(llvm.context()));
//        case Type::TypeId::INTEGER16: llvm.builder().CreateFPToUI(load, ::llvm::Type::getInt16Ty(llvm.context()));
        case Type::TypeId::INTEGER32: return llvm.builder().CreateIntCast(load, ::llvm::Type::getInt32Ty(llvm.context()), false);
        case Type::TypeId::INTEGER: return llvm.builder().CreateIntCast(load, ::llvm::Type::getInt32Ty(llvm.context()), false);
//        case Type::TypeId::INTEGER64: llvm.builder().CreateFPToUI(load, ::llvm::Type::getInt64Ty(llvm.context()));
//        case Type::TypeId::UINTEGER8: llvm.builder().CreateFPToUI(load, ::llvm::Type::getInt8Ty(llvm.context()));
        case Type::TypeId::DOUBLE: return llvm.builder().CreateSIToFP(load, ::llvm::Type::getDoubleTy(llvm.context()));

        default:
            throw InvalidArgumentException("");
    }

    return nullptr;
}

::llvm::Value* createPrimitiveCastFromUinteger8(Context& context, Llvm& llvm, const Type::TypeId toTypeId)
{
    Scope& scope = context.scope();

    auto value = scope.value();

    auto alloca = llvm.builder().CreateAlloca(value->getType(), 0, "");
    auto store = llvm.builder().CreateStore(value, alloca);
    auto load = llvm.builder().CreateLoad(alloca);

    switch (toTypeId)
    {
        case Type::TypeId::BOOLEAN: return llvm.builder().CreateICmpEQ(load, ::llvm::ConstantInt::get(::llvm::Type::getInt8Ty(llvm.context()), 0));
//        case Type::TypeId::INTEGER8: llvm.builder().CreateFPToUI(load, ::llvm::Type::getInt8Ty(llvm.context()));
//        case Type::TypeId::INTEGER16: llvm.builder().CreateFPToUI(load, ::llvm::Type::getInt16Ty(llvm.context()));
        case Type::TypeId::INTEGER32: return llvm.builder().CreateIntCast(load, ::llvm::Type::getInt32Ty(llvm.context()), false);
        case Type::TypeId::INTEGER: return llvm.builder().CreateIntCast(load, ::llvm::Type::getInt32Ty(llvm.context()), false);
//        case Type::TypeId::INTEGER64: llvm.builder().CreateFPToUI(load, ::llvm::Type::getInt64Ty(llvm.context()));
//        case Type::TypeId::UINTEGER8: llvm.builder().CreateFPToUI(load, ::llvm::Type::getInt8Ty(llvm.context()));
        case Type::TypeId::DOUBLE: return llvm.builder().CreateUIToFP(load, ::llvm::Type::getDoubleTy(llvm.context()));

        default:
            throw InvalidArgumentException("");
    }

    return nullptr;
}

::llvm::Value* createPrimitiveCastFromUinteger16(Context& context, Llvm& llvm, const Type::TypeId toTypeId)
{
    Scope& scope = context.scope();

    auto value = scope.value();

    auto alloca = llvm.builder().CreateAlloca(value->getType(), 0, "");
    auto store = llvm.builder().CreateStore(value, alloca);
    auto load = llvm.builder().CreateLoad(alloca);

    switch (toTypeId)
    {
        case Type::TypeId::BOOLEAN: return llvm.builder().CreateICmpEQ(load, ::llvm::ConstantInt::get(::llvm::Type::getInt16Ty(llvm.context()), 0));
//        case Type::TypeId::INTEGER8: llvm.builder().CreateFPToUI(load, ::llvm::Type::getInt8Ty(llvm.context()));
//        case Type::TypeId::INTEGER16: llvm.builder().CreateFPToUI(load, ::llvm::Type::getInt16Ty(llvm.context()));
        case Type::TypeId::INTEGER32: return llvm.builder().CreateIntCast(load, ::llvm::Type::getInt32Ty(llvm.context()), false);
        case Type::TypeId::INTEGER: return llvm.builder().CreateIntCast(load, ::llvm::Type::getInt32Ty(llvm.context()), false);
//        case Type::TypeId::INTEGER64: llvm.builder().CreateFPToUI(load, ::llvm::Type::getInt64Ty(llvm.context()));
//        case Type::TypeId::UINTEGER8: llvm.builder().CreateFPToUI(load, ::llvm::Type::getInt8Ty(llvm.context()));
        case Type::TypeId::DOUBLE: return llvm.builder().CreateUIToFP(load, ::llvm::Type::getDoubleTy(llvm.context()));

        default:
            throw InvalidArgumentException("");
    }

    return nullptr;
}

::llvm::Value* createPrimitiveAssignment(Context& context, Llvm& llvm, const Functioncall& functioncall)
{
    Scope& scope = context.scope();

    ICE_SCRIPT_ASSERT(functioncall.arglist.get().arguments.size() == 1)

    auto lhs = scope.value();
    auto rhs = process(context, llvm, functioncall.arglist.get().arguments[0].assign.get());

//    if (::llvm::isa<::llvm::AllocaInst>(lhs))
//    {
//        ::llvm::AllocaInst* allocaInst = ::llvm::dyn_cast<::llvm::AllocaInst>(lhs);
////            auto loadInstruction = llvm_->builder().CreateLoad(allocaInst);
//        lhs = llvm.builder().CreateLoad(allocaInst);
//    }

    // if (rhs->getType()->isPointerTy())
    // {
    //     rhs = llvm.builder().CreateLoad(rhs);
    // }
//     if (::llvm::isa<::llvm::AllocaInst>(rhs))
//     {
//         ::llvm::AllocaInst* allocaInst = ::llvm::dyn_cast<::llvm::AllocaInst>(rhs);
// //            auto loadInstruction = llvm_->builder().CreateLoad(allocaInst);
//         rhs = llvm.builder().CreateLoad(allocaInst);
//     }

    while (lhs->getType()->isPointerTy() && lhs->getType()->getNumContainedTypes() >= 1 && lhs->getType()->getContainedType(0)->isPointerTy())
    {
        lhs = llvm.builder().CreateLoad(lhs);
    }
    
    if (rhs->getType()->isPointerTy() && rhs->getType()->getNumContainedTypes() >= 1)
    {
        rhs = llvm.builder().CreateLoad(rhs);
    }

    return llvm.builder().CreateStore(rhs, lhs);
}

::llvm::Value* createPrimitiveEquals(Context& context, Llvm& llvm, const Functioncall& functioncall)
{
    Scope& scope = context.scope();

    auto lhs = scope.value();

    ICE_SCRIPT_ASSERT(functioncall.arglist.get().arguments.size() == 1)
    ICE_SCRIPT_ASSERT(functioncall.type->parameters().size() == 1)

    auto rhs = process(context, llvm, functioncall.arglist.get().arguments[0].assign.get());

    if (::llvm::isa<::llvm::AllocaInst>(lhs))
    {
        ::llvm::AllocaInst* allocaInst = ::llvm::dyn_cast<::llvm::AllocaInst>(lhs);
        lhs = llvm.builder().CreateLoad(allocaInst);
    }
    else if (::llvm::isa<::llvm::GetElementPtrInst>(lhs))
    {
        ::llvm::GetElementPtrInst* getElementPtrInst = ::llvm::dyn_cast<::llvm::GetElementPtrInst>(lhs);
        lhs = llvm.builder().CreateLoad(getElementPtrInst);
    }
    
    if (::llvm::isa<::llvm::AllocaInst>(rhs))
    {
        ::llvm::AllocaInst* allocaInst = ::llvm::dyn_cast<::llvm::AllocaInst>(rhs);
        rhs = llvm.builder().CreateLoad(allocaInst);
    }

    switch (functioncall.type->parameters()[0]->typeId())
    {
        case Type::TypeId::BOOLEAN: return llvm.builder().CreateICmpEQ(lhs, rhs);
        case Type::TypeId::INTEGER8: return llvm.builder().CreateICmpEQ(lhs, rhs);
        case Type::TypeId::INTEGER16: return llvm.builder().CreateICmpEQ(lhs, rhs);
        case Type::TypeId::INTEGER32: return llvm.builder().CreateICmpEQ(lhs, rhs);
        case Type::TypeId::INTEGER: return llvm.builder().CreateICmpEQ(lhs, rhs);
        case Type::TypeId::INTEGER64: return llvm.builder().CreateICmpEQ(lhs, rhs);
        case Type::TypeId::UINTEGER8: return llvm.builder().CreateICmpEQ(lhs, rhs);
        case Type::TypeId::UINTEGER16: return llvm.builder().CreateICmpEQ(lhs, rhs);
        case Type::TypeId::UINTEGER32: return llvm.builder().CreateICmpEQ(lhs, rhs);
        case Type::TypeId::UINTEGER: return llvm.builder().CreateICmpEQ(lhs, rhs);
        case Type::TypeId::UINTEGER64: return llvm.builder().CreateICmpEQ(lhs, rhs);
        case Type::TypeId::DOUBLE: return llvm.builder().CreateFCmpUEQ(lhs, rhs);

        default:
            throw InvalidArgumentException("");
    }
}

::llvm::Value* createPrimitiveLessThan(Context& context, Llvm& llvm, const Functioncall& functioncall)
{
    Scope& scope = context.scope();

    auto lhs = scope.value();

    ICE_SCRIPT_ASSERT(functioncall.arglist.get().arguments.size() == 1)
    ICE_SCRIPT_ASSERT(functioncall.type->parameters().size() == 1)

    auto rhs = process(context, llvm, functioncall.arglist.get().arguments[0].assign.get());

    if (::llvm::isa<::llvm::AllocaInst>(lhs))
    {
        ::llvm::AllocaInst* allocaInst = ::llvm::dyn_cast<::llvm::AllocaInst>(lhs);
        lhs = llvm.builder().CreateLoad(allocaInst);
    }

    switch (functioncall.type->parameters()[0]->typeId())
    {
//        case Type::TypeId::BOOLEAN: return llvm.builder().CreateICmpEQ(lhs, rhs);
        case Type::TypeId::INTEGER8: return llvm.builder().CreateICmpSLT(lhs, rhs);
        case Type::TypeId::INTEGER16: return llvm.builder().CreateICmpSLT(lhs, rhs);
        case Type::TypeId::INTEGER32: return llvm.builder().CreateICmpSLT(lhs, rhs);
        case Type::TypeId::INTEGER: return llvm.builder().CreateICmpSLT(lhs, rhs);
        case Type::TypeId::INTEGER64: return llvm.builder().CreateICmpSLT(lhs, rhs);
        case Type::TypeId::UINTEGER8: return llvm.builder().CreateICmpULT(lhs, rhs);
        case Type::TypeId::UINTEGER16: return llvm.builder().CreateICmpULT(lhs, rhs);
        case Type::TypeId::UINTEGER32: return llvm.builder().CreateICmpULT(lhs, rhs);
        case Type::TypeId::UINTEGER: return llvm.builder().CreateICmpULT(lhs, rhs);
        case Type::TypeId::UINTEGER64: return llvm.builder().CreateICmpULT(lhs, rhs);
        case Type::TypeId::DOUBLE: return llvm.builder().CreateFCmpOLT(lhs, rhs);

        default:
            throw InvalidArgumentException("");
    }
}

::llvm::Value* createPrimitiveAdd(Context& context, Llvm& llvm, const Functioncall& functioncall)
{
    Scope& scope = context.scope();

    auto lhs = scope.value();

    ICE_SCRIPT_ASSERT(functioncall.arglist.get().arguments.size() == 1)
    ICE_SCRIPT_ASSERT(functioncall.type->parameters().size() == 1)

    auto rhs = process(context, llvm, functioncall.arglist.get().arguments[0].assign.get());

    if (lhs->getType()->isPointerTy())
    {
        lhs = llvm.builder().CreateLoad(lhs);
    }
    
    if (rhs->getType()->isPointerTy())
    {
        rhs = llvm.builder().CreateLoad(rhs);
    }
    
    // if (::llvm::isa<::llvm::AllocaInst>(lhs))
    // {
    //     ::llvm::AllocaInst* allocaInst = ::llvm::dyn_cast<::llvm::AllocaInst>(lhs);
    //     lhs = llvm.builder().CreateLoad(allocaInst);
    // }
    // else if (::llvm::isa<::llvm::GetElementPtrInst>(lhs))
    // {
    //     ::llvm::GetElementPtrInst* getElementPtrInst = ::llvm::dyn_cast<::llvm::GetElementPtrInst>(lhs);
    //     lhs = llvm.builder().CreateLoad(getElementPtrInst);
    // }

    // if (::llvm::isa<::llvm::AllocaInst>(rhs))
    // {
    //     ::llvm::AllocaInst* allocaInst = ::llvm::dyn_cast<::llvm::AllocaInst>(rhs);
    //     rhs = llvm.builder().CreateLoad(allocaInst);
    // }
    // else if (::llvm::isa<::llvm::GetElementPtrInst>(rhs))
    // {
    //     ::llvm::GetElementPtrInst* getElementPtrInst = ::llvm::dyn_cast<::llvm::GetElementPtrInst>(rhs);
    //     rhs = llvm.builder().CreateLoad(getElementPtrInst);
    // }

    switch (functioncall.type->parameters()[0]->typeId())
    {
//        case Type::TypeId::BOOLEAN: return llvm.builder().CreateICmpEQ(lhs, rhs);
        case Type::TypeId::INTEGER8:
        case Type::TypeId::INTEGER16:
        case Type::TypeId::INTEGER32:
        case Type::TypeId::INTEGER:
        case Type::TypeId::INTEGER64:
        case Type::TypeId::UINTEGER8:
        case Type::TypeId::UINTEGER16:
        case Type::TypeId::UINTEGER32:
        case Type::TypeId::UINTEGER:
        case Type::TypeId::UINTEGER64: return llvm.builder().CreateAdd(lhs, rhs);
        case Type::TypeId::DOUBLE: return llvm.builder().CreateFAdd(lhs, rhs);

        default:
            throw InvalidArgumentException("");
    }
}

::llvm::Value* createPrimitiveSubtract(Context& context, Llvm& llvm, const Functioncall& functioncall)
{
    Scope& scope = context.scope();

    auto lhs = scope.value();

    ICE_SCRIPT_ASSERT(functioncall.arglist.get().arguments.size() == 1)
    ICE_SCRIPT_ASSERT(functioncall.type->parameters().size() == 1)

    auto rhs = process(context, llvm, functioncall.arglist.get().arguments[0].assign.get());

    if (::llvm::isa<::llvm::AllocaInst>(lhs))
    {
        ::llvm::AllocaInst* allocaInst = ::llvm::dyn_cast<::llvm::AllocaInst>(lhs);
        lhs = llvm.builder().CreateLoad(allocaInst);
    }

    switch (functioncall.type->parameters()[0]->typeId())
    {
//        case Type::TypeId::BOOLEAN: return llvm.builder().CreateICmpEQ(lhs, rhs);
        case Type::TypeId::INTEGER8:
        case Type::TypeId::INTEGER16:
        case Type::TypeId::INTEGER32:
        case Type::TypeId::INTEGER:
        case Type::TypeId::INTEGER64:
        case Type::TypeId::UINTEGER8:
        case Type::TypeId::UINTEGER16:
        case Type::TypeId::UINTEGER32:
        case Type::TypeId::UINTEGER:
        case Type::TypeId::UINTEGER64: return llvm.builder().CreateSub(lhs, rhs);
        case Type::TypeId::DOUBLE: return llvm.builder().CreateFSub(lhs, rhs);

        default:
            throw InvalidArgumentException("");
    }
}

::llvm::Value* createPrimitiveAnd(Context& context, Llvm& llvm, const Functioncall& functioncall)
{
    Scope& scope = context.scope();

    auto lhs = scope.value();

    ICE_SCRIPT_ASSERT(functioncall.arglist.get().arguments.size() == 1)
    ICE_SCRIPT_ASSERT(functioncall.type->parameters().size() == 1)

    auto rhs = process(context, llvm, functioncall.arglist.get().arguments[0].assign.get());

    if (::llvm::isa<::llvm::AllocaInst>(lhs))
    {
        ::llvm::AllocaInst* allocaInst = ::llvm::dyn_cast<::llvm::AllocaInst>(lhs);
        lhs = llvm.builder().CreateLoad(allocaInst);
    }

    switch (functioncall.type->parameters()[0]->typeId())
    {
        case Type::TypeId::BOOLEAN: return llvm.builder().CreateAnd(lhs, rhs);
//        case Type::TypeId::INTEGER8: return llvm.builder().CreateICmpEQ(lhs, rhs);
//        case Type::TypeId::INTEGER16: return llvm.builder().CreateICmpEQ(lhs, rhs);
//        case Type::TypeId::INTEGER32: return llvm.builder().CreateICmpEQ(lhs, rhs);
//        case Type::TypeId::INTEGER: return llvm.builder().CreateICmpEQ(lhs, rhs);
//        case Type::TypeId::INTEGER64: return llvm.builder().CreateICmpEQ(lhs, rhs);
//        case Type::TypeId::UINTEGER8: return llvm.builder().CreateICmpEQ(lhs, rhs);
//        case Type::TypeId::UINTEGER16: return llvm.builder().CreateICmpEQ(lhs, rhs);
//        case Type::TypeId::UINTEGER32: return llvm.builder().CreateICmpEQ(lhs, rhs);
//        case Type::TypeId::UINTEGER: return llvm.builder().CreateICmpEQ(lhs, rhs);
//        case Type::TypeId::UINTEGER64: return llvm.builder().CreateICmpEQ(lhs, rhs);
//        case Type::TypeId::DOUBLE: return llvm.builder().CreateFCmpUEQ(lhs, rhs);

        default:
            throw InvalidArgumentException("");
    }
}

::llvm::Value* createPrimitiveOr(Context& context, Llvm& llvm, const Functioncall& functioncall)
{
    Scope& scope = context.scope();

    auto lhs = scope.value();

    ICE_SCRIPT_ASSERT(functioncall.arglist.get().arguments.size() == 1)
    ICE_SCRIPT_ASSERT(functioncall.type->parameters().size() == 1)

    auto rhs = process(context, llvm, functioncall.arglist.get().arguments[0].assign.get());

    if (::llvm::isa<::llvm::AllocaInst>(lhs))
    {
        ::llvm::AllocaInst* allocaInst = ::llvm::dyn_cast<::llvm::AllocaInst>(lhs);
        lhs = llvm.builder().CreateLoad(allocaInst);
    }

    switch (functioncall.type->parameters()[0]->typeId())
    {
        case Type::TypeId::BOOLEAN: return llvm.builder().CreateOr(lhs, rhs);
//        case Type::TypeId::INTEGER8: return llvm.builder().CreateICmpEQ(lhs, rhs);
//        case Type::TypeId::INTEGER16: return llvm.builder().CreateICmpEQ(lhs, rhs);
//        case Type::TypeId::INTEGER32: return llvm.builder().CreateICmpEQ(lhs, rhs);
//        case Type::TypeId::INTEGER: return llvm.builder().CreateICmpEQ(lhs, rhs);
//        case Type::TypeId::INTEGER64: return llvm.builder().CreateICmpEQ(lhs, rhs);
//        case Type::TypeId::UINTEGER8: return llvm.builder().CreateICmpEQ(lhs, rhs);
//        case Type::TypeId::UINTEGER16: return llvm.builder().CreateICmpEQ(lhs, rhs);
//        case Type::TypeId::UINTEGER32: return llvm.builder().CreateICmpEQ(lhs, rhs);
//        case Type::TypeId::UINTEGER: return llvm.builder().CreateICmpEQ(lhs, rhs);
//        case Type::TypeId::UINTEGER64: return llvm.builder().CreateICmpEQ(lhs, rhs);
//        case Type::TypeId::DOUBLE: return llvm.builder().CreateFCmpUEQ(lhs, rhs);

        default:
            throw InvalidArgumentException("");
    }
}

::llvm::Value* createPrimitiveCast(Context& context, Llvm& llvm, const Functioncall& functioncall)
{
    Scope& scope = context.scope();

    auto value = scope.value();

    switch (functioncall.type->ownerType()->typeId())
    {
//            case Type::TypeId::BOOLEAN: return createPrimitiveCastFromFloatingPoint(context, llvm, functioncall.type->returnType()->typeId());
        case Type::TypeId::DOUBLE: return createPrimitiveCastFromFloatingPoint(context, llvm, functioncall.type->returnType()->typeId());
        case Type::TypeId::UINTEGER8: return createPrimitiveCastFromUinteger8(context, llvm, functioncall.type->returnType()->typeId());
        case Type::TypeId::UINTEGER16: return createPrimitiveCastFromUinteger16(context, llvm, functioncall.type->returnType()->typeId());
        case Type::TypeId::INTEGER: return createPrimitiveCastFromInteger(context, llvm, functioncall.type->returnType()->typeId());

        default:
            throw InvalidArgumentException("");
    }

    return llvm.builder().CreateIntCast(value, ::llvm::Type::getInt32Ty(llvm.context()), true);
}

::llvm::Value* createPrimitiveImplicitConversion(Context& context, Llvm& llvm, const Functioncall& functioncall)
{
    Scope& scope = context.scope();
    
    auto value = scope.value();
    
    const std::shared_ptr<Type>& from = functioncall.type->ownerType();
    const std::shared_ptr<Type>& to = functioncall.type->returnType();
    
    switch (from->modifier())
    {
        case TypeModifier::VALUE:
            switch (to->modifier())
            {
                // VALUE to VALUE
                case TypeModifier::VALUE:
                    switch (from->typeId())
                    {
                        case Type::TypeId::DOUBLE: return createPrimitiveCastFromFloatingPoint(context, llvm, to->typeId());
                        case Type::TypeId::UINTEGER8: return createPrimitiveCastFromUinteger8(context, llvm, to->typeId());
                        case Type::TypeId::UINTEGER16: return createPrimitiveCastFromUinteger16(context, llvm, to->typeId());
                        case Type::TypeId::INTEGER: return createPrimitiveCastFromInteger(context, llvm, to->typeId());

                        default:
                            throw InvalidArgumentException("");
                    }
                    
                // VALUE to REFERENCE
                case TypeModifier::REFERENCE:
                    // if (from->typeId() == to->typeId()) return createPrimitiveCast(context, llvm, from, to);
                    if (from->typeId() != to->typeId())
                    {
                        switch (from->typeId())
                        {
                            case Type::TypeId::DOUBLE:
                                value = createPrimitiveCastFromFloatingPoint(context, llvm, to->typeId());
                                break;
                                    
                            case Type::TypeId::UINTEGER8:
                                value = createPrimitiveCastFromUinteger8(context, llvm, to->typeId());
                                break;
                                
                            case Type::TypeId::UINTEGER16:
                                value = createPrimitiveCastFromUinteger16(context, llvm, to->typeId());
                                break;
                                
                            case Type::TypeId::INTEGER:
                                value = createPrimitiveCastFromInteger(context, llvm, to->typeId());
                                break;

                            default:
                                throw InvalidArgumentException("");
                        }
                    }
                    
                    return value;
                    
                    // switch (to->typeId())
                    // {
                    //     case Type::TypeId::DOUBLE: return llvm.builder().CreateFPCast(value, ::llvm::Type::getDoublePtrTy(llvm.context()));
                    //     case Type::TypeId::UINTEGER8: return llvm.builder().CreateIntToPtr(value, ::llvm::Type::getInt8PtrTy(llvm.context()));
                    //     case Type::TypeId::UINTEGER16: return llvm.builder().CreateIntToPtr(value, ::llvm::Type::getInt16PtrTy(llvm.context()));
                    //     case Type::TypeId::INTEGER:
                    //     {
                    //         if (value->getType()->isPointerTy()) return value;
                            
                    //         // return llvm.builder().CreateIntToPtr(value, ::llvm::Type::getInt32PtrTy(llvm.context()));
                    //         auto alloca = llvm.builder().CreateAlloca(value->getType(), 0, "");
                    //         auto store = llvm.builder().CreateStore(value, alloca);
                    //         return alloca;
                    //     }

                    //     default:
                    //         throw InvalidArgumentException("");
                    // }
                    
                default:
                    throw InvalidArgumentException("");
            }
            
            case TypeModifier::REFERENCE:
                switch (to->modifier())
                {
                    // REFERENCE to VALUE
                    case TypeModifier::VALUE:
                        switch (from->typeId())
                        {
                            case Type::TypeId::DOUBLE: return createPrimitiveCastFromFloatingPoint(context, llvm, to->typeId());
                            case Type::TypeId::UINTEGER8: return createPrimitiveCastFromUinteger8(context, llvm, to->typeId());
                            case Type::TypeId::UINTEGER16: return createPrimitiveCastFromUinteger16(context, llvm, to->typeId());
                            case Type::TypeId::INTEGER: return createPrimitiveCastFromInteger(context, llvm, to->typeId());

                            default:
                                throw InvalidArgumentException("");
                        }
                        
                    // REFERENCE to REFERENCE
                    case TypeModifier::REFERENCE:
                        // if (from->typeId() == to->typeId()) return createPrimitiveCast(context, llvm, from, to);
                        if (from->typeId() != to->typeId())
                        {
                            switch (from->typeId())
                            {
                                case Type::TypeId::DOUBLE:
                                    value = createPrimitiveCastFromFloatingPoint(context, llvm, to->typeId());
                                    break;
                                        
                                case Type::TypeId::UINTEGER8:
                                    value = createPrimitiveCastFromUinteger8(context, llvm, to->typeId());
                                    break;
                                    
                                case Type::TypeId::UINTEGER16:
                                    value = createPrimitiveCastFromUinteger16(context, llvm, to->typeId());
                                    break;
                                    
                                case Type::TypeId::INTEGER:
                                    value = createPrimitiveCastFromInteger(context, llvm, to->typeId());
                                    break;

                                default:
                                    throw InvalidArgumentException("");
                            }
                        }
                        
                        return value;
                        
                        // switch (to->typeId())
                        // {
                        //     case Type::TypeId::DOUBLE: return llvm.builder().CreateFPCast(value, ::llvm::Type::getDoublePtrTy(llvm.context()));
                        //     case Type::TypeId::UINTEGER8: return llvm.builder().CreateIntToPtr(value, ::llvm::Type::getInt8PtrTy(llvm.context()));
                        //     case Type::TypeId::UINTEGER16: return llvm.builder().CreateIntToPtr(value, ::llvm::Type::getInt16PtrTy(llvm.context()));
                        //     case Type::TypeId::INTEGER: 
                        //     {
                        //         // return llvm.builder().CreateIntToPtr(value, ::llvm::Type::getInt32PtrTy(llvm.context()));
                        //         // return llvm.builder().CreateIntToPtr(value, ::llvm::Type::getInt32PtrTy(llvm.context()));
                        //         auto alloca = llvm.builder().CreateAlloca(value->getType(), 0, "");
                        //         auto store = llvm.builder().CreateStore(value, alloca);
                        //         return alloca;
                        //     }

                        //     default:
                        //         throw InvalidArgumentException("");
                        // }
                        
                    default:
                        throw InvalidArgumentException("");
                }
                
                default:
                    throw InvalidArgumentException("");
    }
}

// ::llvm::Value* createPrimitiveImplicitConversion(Context& context, Llvm& llvm, const Functioncall& functioncall)
// {
//     Scope& scope = context.scope();

//     auto value = scope.value();

//     switch (functioncall.type->ownerType()->typeId())
//     {
// //            case Type::TypeId::BOOLEAN: return createPrimitiveCastFromFloatingPoint(context, llvm, functioncall.type->returnType()->typeId());
//         case Type::TypeId::DOUBLE: return createPrimitiveCastFromFloatingPoint(context, llvm, functioncall.type->returnType()->typeId());
//         case Type::TypeId::UINTEGER8: return createPrimitiveCastFromUinteger8(context, llvm, functioncall.type->returnType()->typeId());
//         case Type::TypeId::UINTEGER16: return createPrimitiveCastFromUinteger16(context, llvm, functioncall.type->returnType()->typeId());
//         case Type::TypeId::INTEGER: return createPrimitiveCastFromInteger(context, llvm, functioncall.type->returnType()->typeId());

//         default:
//             throw InvalidArgumentException("");
//     }

//     return llvm.builder().CreateIntCast(value, ::llvm::Type::getInt32Ty(llvm.context()), true);
// }

::llvm::Value* createPrimitivePostfixIncrement(Context& context, Llvm& llvm, const Functioncall& functioncall)
{
    Scope& scope = context.scope();

    auto lhs = scope.value();
    ::llvm::Value* originalLhs = lhs;

    ICE_SCRIPT_ASSERT(functioncall.arglist.get().arguments.size() == 0)
    ICE_SCRIPT_ASSERT(functioncall.type->parameters().size() == 0)

    if (::llvm::isa<::llvm::AllocaInst>(lhs))
    {
        ::llvm::AllocaInst* allocaInst = ::llvm::dyn_cast<::llvm::AllocaInst>(lhs);
        lhs = llvm.builder().CreateLoad(allocaInst);
    }

    ::llvm::Value* newLhs = nullptr;

    switch (functioncall.type->ownerType()->typeId())
    {
//        case Type::TypeId::BOOLEAN: return llvm.builder().CreateICmpEQ(lhs, rhs);
        case Type::TypeId::INTEGER8:
            newLhs = llvm.builder().CreateAdd(lhs, ::llvm::ConstantInt::get(::llvm::Type::getInt8Ty(llvm.context()), 1));
            break;

        case Type::TypeId::INTEGER16:
            newLhs = llvm.builder().CreateAdd(lhs, ::llvm::ConstantInt::get(::llvm::Type::getInt16Ty(llvm.context()), 1));
            break;

        case Type::TypeId::INTEGER32:
            newLhs = llvm.builder().CreateAdd(lhs, ::llvm::ConstantInt::get(::llvm::Type::getInt32Ty(llvm.context()), 1));
            break;

        case Type::TypeId::INTEGER:
            newLhs = llvm.builder().CreateAdd(lhs, ::llvm::ConstantInt::get(::llvm::Type::getInt32Ty(llvm.context()), 1));
            break;

        case Type::TypeId::INTEGER64:
            newLhs = llvm.builder().CreateAdd(lhs, ::llvm::ConstantInt::get(::llvm::Type::getInt64Ty(llvm.context()), 1));
            break;

        case Type::TypeId::UINTEGER8:
            newLhs = llvm.builder().CreateAdd(lhs, ::llvm::ConstantInt::get(::llvm::Type::getInt8Ty(llvm.context()), 1));
            break;

        case Type::TypeId::UINTEGER16:
            newLhs = llvm.builder().CreateAdd(lhs, ::llvm::ConstantInt::get(::llvm::Type::getInt16Ty(llvm.context()), 1));
            break;

        case Type::TypeId::UINTEGER32:
            newLhs = llvm.builder().CreateAdd(lhs, ::llvm::ConstantInt::get(::llvm::Type::getInt32Ty(llvm.context()), 1));
            break;

        case Type::TypeId::UINTEGER:
            newLhs = llvm.builder().CreateAdd(lhs, ::llvm::ConstantInt::get(::llvm::Type::getInt32Ty(llvm.context()), 1));
            break;

        case Type::TypeId::UINTEGER64:
            newLhs = llvm.builder().CreateAdd(lhs, ::llvm::ConstantInt::get(::llvm::Type::getInt64Ty(llvm.context()), 1));
            break;

        case Type::TypeId::DOUBLE:
            newLhs = llvm.builder().CreateFAdd(lhs, ::llvm::ConstantInt::get(::llvm::Type::getDoubleTy(llvm.context()), 1.0));
            break;


        default:
            throw InvalidArgumentException("");
    }

    return llvm.builder().CreateStore(newLhs, originalLhs);
}

::llvm::Value* createPrimitiveOperator(Context& context, Llvm& llvm, const Functioncall& functioncall)
{
    Scope& scope = context.scope();

    auto value = scope.value();

    auto operatorType = std::static_pointer_cast<OperatorType>(functioncall.type);

    switch (operatorType->operatorTypeId())
    {
        case OperatorTypeId::ASSIGN_EQUAL: return createPrimitiveAssignment(context, llvm, functioncall);
        case OperatorTypeId::EQUALS: return createPrimitiveEquals(context, llvm, functioncall);
        case OperatorTypeId::LESS_THAN: return createPrimitiveLessThan(context, llvm, functioncall);
        case OperatorTypeId::ADD: return createPrimitiveAdd(context, llvm, functioncall);
        case OperatorTypeId::SUBTRACT: return createPrimitiveSubtract(context, llvm, functioncall);
        case OperatorTypeId::AND: return createPrimitiveAnd(context, llvm, functioncall);
        case OperatorTypeId::OR: return createPrimitiveOr(context, llvm, functioncall);
        // case OperatorTypeId::IMPLICIT_CONVERSION: return createPrimitiveCast(context, llvm, functioncall);
        case OperatorTypeId::IMPLICIT_CONVERSION: return createPrimitiveImplicitConversion(context, llvm, functioncall);
        case OperatorTypeId::POSTFIX_INCREMENT: return createPrimitivePostfixIncrement(context, llvm, functioncall);

        default:
            throw InvalidArgumentException("");
    }
}

std::vector<::llvm::Value*> prepareStack(Context& context, Llvm& llvm, const asg::Functioncall& functioncall, const std::vector<::llvm::Value*>& arguments)
{
    ICE_SCRIPT_ASSERT(functioncall.symbol->parameters().size() == arguments.size());
    ICE_SCRIPT_ASSERT(functioncall.type->parameters().size() == arguments.size());
    
    std::vector<::llvm::Value*> _arguments{};
    
    for (size_t i = 0; i < arguments.size(); ++i)
    {
        auto argument = arguments[i];
        const auto symbol = functioncall.symbol->parameters()[i];
        const auto type = functioncall.type->parameters()[i];
        
        if (type->primitive())
        {
            if (type->modifier() == TypeModifier::REFERENCE)
            {
                _arguments.push_back(argument);
                
                continue;
            }
            else
            {
                if (argument->getType()->isPointerTy())
                {
                    auto alloca = llvm.builder().CreateAlloca(argument->getType()->getContainedType(0), 0, "");
                    auto load = llvm.builder().CreateLoad(argument);
                    auto store = llvm.builder().CreateStore(load, alloca);
                    
                    _arguments.push_back(alloca);
                    
                    continue;
                }
                else
                {
                    auto alloca = llvm.builder().CreateAlloca(argument->getType(), 0, "");
                    // auto load = llvm.builder().CreateLoad(argument);
                    auto store = llvm.builder().CreateStore(argument, alloca);
                    
                    _arguments.push_back(alloca);
                    
                    continue;
                }
            }
        }
        else if (type->typeId() == Type::TypeId::CLASS)
        {
            const auto& classType = std::dynamic_pointer_cast<ClassType>(type);
            
            const auto symbolKey = resolveSymbolKey(classType);
            
            const auto& classSymbol = context.symbolTable().findClassByKey(symbolKey);
            
            if (classType->modifier() == TypeModifier::VALUE)
            {
                // const std::vector<std::shared_ptr<Type>>& parameterTypes = {
                    
                // };
                
                const auto constReferenceClassType = context.typeTable().find(classType, classType->qualifiers() | TypeQualifier::TypeQualifierFlags::CONSTANT, TypeModifier::REFERENCE);
                // const auto nonConstClassType = context.typeTable().find(functioncall.type, functioncall.type->qualifiers() & ~TypeQualifier::TypeQualifierFlags::CONSTANT, functioncall.type->modifier());
                
                ICE_SCRIPT_ASSERT(constReferenceClassType);
                
                auto copyConstructorSymbols = classSymbol->constructors().findByParameterTypes({constReferenceClassType});
                
                ICE_SCRIPT_ASSERT(copyConstructorSymbols.size() == 1);
                
                const auto& copyConstructorSymbol = copyConstructorSymbols[0];
                
                auto& function = context.llvmSymbolTable().getFunctionByKey(copyConstructorSymbol->key());
                
                ::llvm::AllocaInst* alloca = nullptr;
                if (argument->getType()->isPointerTy())
                {
                    alloca = llvm.builder().CreateAlloca(argument->getType()->getContainedType(0), 0, "");
                }
                else
                {
                    alloca = llvm.builder().CreateAlloca(argument->getType(), 0, "");
                }
                
                // std::vector<::llvm::Value*> arguments = {alloca, argument};
                ::llvm::ArrayRef<::llvm::Value*> arguments = {alloca, argument};
                // function.dump();
                
                // for (const auto& v : function.args())
                // {
                //     v.dump();
                //     v.getType()->dump();
                //     std::cout << "HIMOM 1: " << v.getType() << std::endl;
                //     // v->print({std::cout}, true)
                // }
                
                // for (const auto v : arguments)
                // {
                //     v->dump();
                //     v->getType()->dump();
                //     std::cout << "HIMOM: " << v->getType() << std::endl;
                //     // v->getType()->print(std::cout, true)
                // }
                
                llvm.builder().CreateCall(&function, arguments);
                
                _arguments.push_back(alloca);
                    
                continue;
            }
        }
    }
    
    return _arguments;
}

void unprepareStack(Context& context, Llvm& llvm, const asg::Functioncall& functioncall, const std::vector<::llvm::Value*>& arguments)
{
    
}

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Functioncall& functioncall)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(functioncall).name())

    Scope& scope = context.scope();

    auto value = scope.value();

    if (functioncall.type->typeId() == Type::TypeId::OPERATOR)
    // if (functioncall.symbol->type()->typeId() == Type::TypeId::OPERATOR)
    {
//        auto operatorType = std::static_pointer_cast<OperatorType>(functioncall.type);

        if (functioncall.type->ownerType()->primitive())// && functioncall.type->returnType()->primitive())
        // if (functioncall.symbol->type()->ownerType()->primitive())// && functioncall.type->returnType()->primitive())
        {
            return createPrimitiveOperator(context, llvm, functioncall);
//            return createPrimitiveCast(context, llvm, functioncall);
        }
    }

    auto& function = context.llvmSymbolTable().getFunctionByKey(functioncall.symbol->key());

    auto arguments = process(context, llvm, functioncall.arglist.get());
    
    arguments = prepareStack(context, llvm, functioncall, arguments);
    
    if (functioncall.type->isConstructor())
    {
        if (value) arguments.insert(arguments.begin(), value);
    }
    
    // std::cout << "ASDF" << std::endl;
    // function.dump();
    // for (const auto v : arguments)
    // {
    //     std::cout << "params" << std::endl;
    //     v->dump();
    // }
    
    auto call = llvm.builder().CreateCall(&function, arguments);
    
    unprepareStack(context, llvm, functioncall, arguments);
    
    return call;
}

}}}}