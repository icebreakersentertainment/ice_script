#include <llvm/ADT/APFloat.h>
#include <stdint.h>
#include <type_traits>
#include <string>

#include <llvm/IR/Instructions.h>
#include <llvm/IR/Operator.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/Constants.h>

#include "generator/llvm/detail/GenerateDefaultDefinitions.hpp"
#include "generator/llvm/detail/LlvmUtilities.hpp"

#include "symbol/ArraySymbol.hpp"
#include "type/TypeModifier.hpp"
#include "type/TypeQualifier.hpp"


namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ::llvm;

struct TypeValue
{
    std::shared_ptr<Type> type;
    ::llvm::Value* value;
    
    operator ::llvm::Value*() const
    {
        return value;
    }
};

::llvm::Value* createPrimitiveCast(Context& context, Llvm& llvm, const std::shared_ptr<Type>& type, const TypeValue& value)
{
    if (type == value.type) return value;
    
    Value* loaded = value;
    if (value.value->getType()->isPointerTy())
    {
        loaded = llvm.builder().CreateLoad(value);
    }

    switch (value.type->typeId())
    {
        case Type::TypeId::UINTEGER8:
            switch (type->typeId())
            {
                case Type::TypeId::BOOLEAN: return llvm.builder().CreateICmpEQ(loaded, ConstantInt::get(::llvm::Type::getInt8Ty(llvm.context()), 0));
                case Type::TypeId::INTEGER8: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt8Ty(llvm.context()), false);
                case Type::TypeId::INTEGER16: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt16Ty(llvm.context()), false);
                case Type::TypeId::INTEGER32: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), false);
                case Type::TypeId::INTEGER: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), false);
                case Type::TypeId::INTEGER64: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt64Ty(llvm.context()), false);
                // case Type::TypeId::UINTEGER8: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt8Ty(llvm.context()), false);
                case Type::TypeId::UINTEGER16: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt16Ty(llvm.context()), false);
                case Type::TypeId::UINTEGER32: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), false);
                case Type::TypeId::UINTEGER: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), false);
                case Type::TypeId::UINTEGER64: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt64Ty(llvm.context()), false);
                case Type::TypeId::FLOAT: return llvm.builder().CreateUIToFP(loaded, ::llvm::Type::getFloatTy(llvm.context()));
                case Type::TypeId::DOUBLE: return llvm.builder().CreateUIToFP(loaded, ::llvm::Type::getDoubleTy(llvm.context()));

                default:
                    throw InvalidArgumentException("");
            }
            
        case Type::TypeId::UINTEGER16:
            switch (type->typeId())
            {
                case Type::TypeId::BOOLEAN: return llvm.builder().CreateICmpEQ(loaded, ConstantInt::get(::llvm::Type::getInt16Ty(llvm.context()), 0));
                case Type::TypeId::INTEGER8: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt8Ty(llvm.context()), false);
                case Type::TypeId::INTEGER16: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt16Ty(llvm.context()), false);
                case Type::TypeId::INTEGER32: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), false);
                case Type::TypeId::INTEGER: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), false);
                case Type::TypeId::INTEGER64: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt64Ty(llvm.context()), false);
                case Type::TypeId::UINTEGER8: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt8Ty(llvm.context()), false);
                // case Type::TypeId::UINTEGER16: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt16Ty(llvm.context()), false);
                case Type::TypeId::UINTEGER32: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), false);
                case Type::TypeId::UINTEGER: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), false);
                case Type::TypeId::UINTEGER64: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt64Ty(llvm.context()), false);
                case Type::TypeId::FLOAT: return llvm.builder().CreateUIToFP(loaded, ::llvm::Type::getFloatTy(llvm.context()));
                case Type::TypeId::DOUBLE: return llvm.builder().CreateUIToFP(loaded, ::llvm::Type::getDoubleTy(llvm.context()));

                default:
                    throw InvalidArgumentException("");
            }
            
        case Type::TypeId::UINTEGER32:
        case Type::TypeId::UINTEGER:
            switch (type->typeId())
            {
                case Type::TypeId::BOOLEAN: return llvm.builder().CreateICmpEQ(loaded, ConstantInt::get(::llvm::Type::getInt32Ty(llvm.context()), 0));
                case Type::TypeId::INTEGER8: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt8Ty(llvm.context()), false);
                case Type::TypeId::INTEGER16: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt16Ty(llvm.context()), false);
                case Type::TypeId::INTEGER32: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), false);
                case Type::TypeId::INTEGER: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), false);
                case Type::TypeId::INTEGER64: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt64Ty(llvm.context()), false);
                case Type::TypeId::UINTEGER8: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt8Ty(llvm.context()), false);
                case Type::TypeId::UINTEGER16: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt16Ty(llvm.context()), false);
                // case Type::TypeId::UINTEGER32: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), false);
                // case Type::TypeId::UINTEGER: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), false);
                case Type::TypeId::UINTEGER64: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt64Ty(llvm.context()), false);
                case Type::TypeId::FLOAT: return llvm.builder().CreateUIToFP(loaded, ::llvm::Type::getFloatTy(llvm.context()));
                case Type::TypeId::DOUBLE: return llvm.builder().CreateUIToFP(loaded, ::llvm::Type::getDoubleTy(llvm.context()));

                default:
                    throw InvalidArgumentException("");
            }
            
        case Type::TypeId::UINTEGER64:
            switch (type->typeId())
            {
                case Type::TypeId::BOOLEAN: return llvm.builder().CreateICmpEQ(loaded, ConstantInt::get(::llvm::Type::getInt64Ty(llvm.context()), 0));
                case Type::TypeId::INTEGER8: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt8Ty(llvm.context()), false);
                case Type::TypeId::INTEGER16: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt16Ty(llvm.context()), false);
                case Type::TypeId::INTEGER32: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), false);
                case Type::TypeId::INTEGER: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), false);
                case Type::TypeId::INTEGER64: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt64Ty(llvm.context()), false);
                case Type::TypeId::UINTEGER8: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt8Ty(llvm.context()), false);
                case Type::TypeId::UINTEGER16: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt16Ty(llvm.context()), false);
                case Type::TypeId::UINTEGER32: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), false);
                case Type::TypeId::UINTEGER: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), false);
                // case Type::TypeId::UINTEGER64: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt64Ty(llvm.context()), false);
                case Type::TypeId::FLOAT: return llvm.builder().CreateUIToFP(loaded, ::llvm::Type::getFloatTy(llvm.context()));
                case Type::TypeId::DOUBLE: return llvm.builder().CreateUIToFP(loaded, ::llvm::Type::getDoubleTy(llvm.context()));

                default:
                    throw InvalidArgumentException("");
            }
            
        case Type::TypeId::INTEGER8:
            switch (type->typeId())
            {
                case Type::TypeId::BOOLEAN: return llvm.builder().CreateICmpEQ(loaded, ConstantInt::get(::llvm::Type::getInt8Ty(llvm.context()), 0, true));
                // case Type::TypeId::INTEGER8: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt8Ty(llvm.context()), true);
                case Type::TypeId::INTEGER16: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt16Ty(llvm.context()), true);
                case Type::TypeId::INTEGER32: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), true);
                case Type::TypeId::INTEGER: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), true);
                case Type::TypeId::INTEGER64: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt64Ty(llvm.context()), true);
                case Type::TypeId::UINTEGER8: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt8Ty(llvm.context()), true);
                case Type::TypeId::UINTEGER16: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt16Ty(llvm.context()), true);
                case Type::TypeId::UINTEGER32: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), true);
                case Type::TypeId::UINTEGER: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), true);
                case Type::TypeId::UINTEGER64: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt64Ty(llvm.context()), true);
                case Type::TypeId::FLOAT: return llvm.builder().CreateSIToFP(loaded, ::llvm::Type::getFloatTy(llvm.context()));
                case Type::TypeId::DOUBLE: return llvm.builder().CreateSIToFP(loaded, ::llvm::Type::getDoubleTy(llvm.context()));

                default:
                    throw InvalidArgumentException("");
            }
            
        case Type::TypeId::INTEGER16:
            switch (type->typeId())
            {
                case Type::TypeId::BOOLEAN: return llvm.builder().CreateICmpEQ(loaded, ConstantInt::get(::llvm::Type::getInt16Ty(llvm.context()), 0, true));
                case Type::TypeId::INTEGER8: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt8Ty(llvm.context()), true);
                // case Type::TypeId::INTEGER16: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt16Ty(llvm.context()), true);
                case Type::TypeId::INTEGER32: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), true);
                case Type::TypeId::INTEGER: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), true);
                case Type::TypeId::INTEGER64: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt64Ty(llvm.context()), true);
                case Type::TypeId::UINTEGER8: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt8Ty(llvm.context()), true);
                case Type::TypeId::UINTEGER16: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt16Ty(llvm.context()), true);
                case Type::TypeId::UINTEGER32: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), true);
                case Type::TypeId::UINTEGER: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), true);
                case Type::TypeId::UINTEGER64: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt64Ty(llvm.context()), true);
                case Type::TypeId::FLOAT: return llvm.builder().CreateSIToFP(loaded, ::llvm::Type::getFloatTy(llvm.context()));
                case Type::TypeId::DOUBLE: return llvm.builder().CreateSIToFP(loaded, ::llvm::Type::getDoubleTy(llvm.context()));

                default:
                    throw InvalidArgumentException("");
            }
            
        case Type::TypeId::INTEGER32:
        case Type::TypeId::INTEGER:
            switch (type->typeId())
            {
                case Type::TypeId::BOOLEAN: return llvm.builder().CreateICmpEQ(loaded, ConstantInt::get(::llvm::Type::getInt32Ty(llvm.context()), 0, true));
                case Type::TypeId::INTEGER8: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt8Ty(llvm.context()), true);
                case Type::TypeId::INTEGER16: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt16Ty(llvm.context()), true);
                // case Type::TypeId::INTEGER32: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), true);
                // case Type::TypeId::INTEGER: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), true);
                case Type::TypeId::INTEGER64: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt64Ty(llvm.context()), true);
                case Type::TypeId::UINTEGER8: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt8Ty(llvm.context()), true);
                case Type::TypeId::UINTEGER16: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt16Ty(llvm.context()), true);
                case Type::TypeId::UINTEGER32: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), true);
                case Type::TypeId::UINTEGER: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), true);
                case Type::TypeId::UINTEGER64: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt64Ty(llvm.context()), true);
                case Type::TypeId::FLOAT: return llvm.builder().CreateSIToFP(loaded, ::llvm::Type::getFloatTy(llvm.context()));
                case Type::TypeId::DOUBLE: return llvm.builder().CreateSIToFP(loaded, ::llvm::Type::getDoubleTy(llvm.context()));

                default:
                    throw InvalidArgumentException("");
            }
            
        case Type::TypeId::INTEGER64:
            switch (type->typeId())
            {
                case Type::TypeId::BOOLEAN: return llvm.builder().CreateICmpEQ(loaded, ConstantInt::get(::llvm::Type::getInt64Ty(llvm.context()), 0, true));
                case Type::TypeId::INTEGER8: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt8Ty(llvm.context()), true);
                case Type::TypeId::INTEGER16: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt16Ty(llvm.context()), true);
                case Type::TypeId::INTEGER32: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), true);
                case Type::TypeId::INTEGER: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), true);
                // case Type::TypeId::INTEGER64: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt64Ty(llvm.context()), true);
                case Type::TypeId::UINTEGER8: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt8Ty(llvm.context()), true);
                case Type::TypeId::UINTEGER16: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt16Ty(llvm.context()), true);
                case Type::TypeId::UINTEGER32: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), true);
                case Type::TypeId::UINTEGER: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt32Ty(llvm.context()), true);
                case Type::TypeId::UINTEGER64: return llvm.builder().CreateIntCast(loaded, ::llvm::Type::getInt64Ty(llvm.context()), true);
                case Type::TypeId::FLOAT: return llvm.builder().CreateSIToFP(loaded, ::llvm::Type::getFloatTy(llvm.context()));
                case Type::TypeId::DOUBLE: return llvm.builder().CreateSIToFP(loaded, ::llvm::Type::getDoubleTy(llvm.context()));

                default:
                    throw InvalidArgumentException("");
            }
            
        case Type::TypeId::FLOAT:
            switch (type->typeId())
            {
                case Type::TypeId::BOOLEAN: return llvm.builder().CreateFCmpOEQ(loaded, ConstantFP::get(::llvm::Type::getFloatTy(llvm.context()), 0.0));
                case Type::TypeId::INTEGER8: return llvm.builder().CreateFPToSI(loaded, ::llvm::Type::getInt8Ty(llvm.context()));
                case Type::TypeId::INTEGER16: return llvm.builder().CreateFPToSI(loaded, ::llvm::Type::getInt16Ty(llvm.context()));
                case Type::TypeId::INTEGER32: return llvm.builder().CreateFPToSI(loaded, ::llvm::Type::getInt32Ty(llvm.context()));
                case Type::TypeId::INTEGER: return llvm.builder().CreateFPToSI(loaded, ::llvm::Type::getInt32Ty(llvm.context()));
                case Type::TypeId::INTEGER64: return llvm.builder().CreateFPToSI(loaded, ::llvm::Type::getInt64Ty(llvm.context()));
                case Type::TypeId::UINTEGER8: return llvm.builder().CreateFPToUI(loaded, ::llvm::Type::getInt8Ty(llvm.context()));
                case Type::TypeId::UINTEGER16: return llvm.builder().CreateFPToUI(loaded, ::llvm::Type::getInt16Ty(llvm.context()));
                case Type::TypeId::UINTEGER32: return llvm.builder().CreateFPToUI(loaded, ::llvm::Type::getInt32Ty(llvm.context()));
                case Type::TypeId::UINTEGER: return llvm.builder().CreateFPToUI(loaded, ::llvm::Type::getInt32Ty(llvm.context()));
                case Type::TypeId::UINTEGER64: return llvm.builder().CreateFPToUI(loaded, ::llvm::Type::getInt64Ty(llvm.context()));
                // case Type::TypeId::FLOAT: return llvm.builder().CreateFPTrunc(loaded, ::llvm::Type::getFloatTy(llvm.context()));
                case Type::TypeId::DOUBLE: return llvm.builder().CreateFPExt(loaded, ::llvm::Type::getDoubleTy(llvm.context()));

                default:
                    throw InvalidArgumentException("");
            }
            
        case Type::TypeId::DOUBLE:
            switch (type->typeId())
            {
                case Type::TypeId::BOOLEAN: return llvm.builder().CreateFCmpOEQ(loaded, ConstantFP::get(::llvm::Type::getDoubleTy(llvm.context()), 0.0));
                case Type::TypeId::INTEGER8: return llvm.builder().CreateFPToSI(loaded, ::llvm::Type::getInt8Ty(llvm.context()));
                case Type::TypeId::INTEGER16: return llvm.builder().CreateFPToSI(loaded, ::llvm::Type::getInt16Ty(llvm.context()));
                case Type::TypeId::INTEGER32: return llvm.builder().CreateFPToSI(loaded, ::llvm::Type::getInt32Ty(llvm.context()));
                case Type::TypeId::INTEGER: return llvm.builder().CreateFPToSI(loaded, ::llvm::Type::getInt32Ty(llvm.context()));
                case Type::TypeId::INTEGER64: return llvm.builder().CreateFPToSI(loaded, ::llvm::Type::getInt64Ty(llvm.context()));
                case Type::TypeId::UINTEGER8: return llvm.builder().CreateFPToUI(loaded, ::llvm::Type::getInt8Ty(llvm.context()));
                case Type::TypeId::UINTEGER16: return llvm.builder().CreateFPToUI(loaded, ::llvm::Type::getInt16Ty(llvm.context()));
                case Type::TypeId::UINTEGER32: return llvm.builder().CreateFPToUI(loaded, ::llvm::Type::getInt32Ty(llvm.context()));
                case Type::TypeId::UINTEGER: return llvm.builder().CreateFPToUI(loaded, ::llvm::Type::getInt32Ty(llvm.context()));
                case Type::TypeId::UINTEGER64: return llvm.builder().CreateFPToUI(loaded, ::llvm::Type::getInt64Ty(llvm.context()));
                case Type::TypeId::FLOAT: return llvm.builder().CreateFPTrunc(loaded, ::llvm::Type::getFloatTy(llvm.context()));
                // case Type::TypeId::DOUBLE: return llvm.builder().CreateFPExt(loaded, ::llvm::Type::getDoubleTy(llvm.context()));

                default:
                    throw InvalidArgumentException("");
            }
            
        default:
            throw InvalidArgumentException("");
    }

    return nullptr;
}

Value* createPrimitivePostfixIncrement(Context& context, Llvm& llvm, const TypeValue& lhs)
{
    ICE_SCRIPT_ASSERT(lhs.type->primitive());

    Value* lhsValue = lhs;
    if (isa<AllocaInst>(lhsValue))
    {
        lhsValue = llvm.builder().CreateLoad(lhsValue);
    }

    Value* value = nullptr;

    switch (lhs.type->typeId())
    {
//        case Type::TypeId::BOOLEAN: return llvm.builder().CreateICmpEQ(lhs, rhs);
        case Type::TypeId::INTEGER8:
            value = llvm.builder().CreateAdd(lhsValue, ConstantInt::get(::llvm::Type::getInt8Ty(llvm.context()), 1));
            break;

        case Type::TypeId::INTEGER16:
            value = llvm.builder().CreateAdd(lhsValue, ConstantInt::get(::llvm::Type::getInt16Ty(llvm.context()), 1));
            break;

        case Type::TypeId::INTEGER32:
            value = llvm.builder().CreateAdd(lhsValue, ConstantInt::get(::llvm::Type::getInt32Ty(llvm.context()), 1));
            break;

        case Type::TypeId::INTEGER:
            value = llvm.builder().CreateAdd(lhsValue, ConstantInt::get(::llvm::Type::getInt32Ty(llvm.context()), 1));
            break;

        case Type::TypeId::INTEGER64:
            value = llvm.builder().CreateAdd(lhsValue, ConstantInt::get(::llvm::Type::getInt64Ty(llvm.context()), 1));
            break;

        case Type::TypeId::UINTEGER8:
            value = llvm.builder().CreateAdd(lhsValue, ConstantInt::get(::llvm::Type::getInt8Ty(llvm.context()), 1));
            break;

        case Type::TypeId::UINTEGER16:
            value = llvm.builder().CreateAdd(lhsValue, ConstantInt::get(::llvm::Type::getInt16Ty(llvm.context()), 1));
            break;

        case Type::TypeId::UINTEGER32:
            value = llvm.builder().CreateAdd(lhsValue, ConstantInt::get(::llvm::Type::getInt32Ty(llvm.context()), 1));
            break;

        case Type::TypeId::UINTEGER:
            value = llvm.builder().CreateAdd(lhsValue, ConstantInt::get(::llvm::Type::getInt32Ty(llvm.context()), 1));
            break;

        case Type::TypeId::UINTEGER64:
            value = llvm.builder().CreateAdd(lhsValue, ConstantInt::get(::llvm::Type::getInt64Ty(llvm.context()), 1));
            break;

        case Type::TypeId::DOUBLE:
            value = llvm.builder().CreateFAdd(lhsValue, ConstantInt::get(::llvm::Type::getDoubleTy(llvm.context()), 1.0));
            break;


        default:
            throw InvalidArgumentException("");
    }

    // auto load = llvm.builder().CreateLoad(value);
    
    // return llvm.builder().CreateStore(load, lhs);
    return llvm.builder().CreateStore(value, lhs);
}

auto createPrimitiveLessThan(Context& context, Llvm& llvm, const TypeValue& lhs, const TypeValue& rhs)
{
    ICE_SCRIPT_ASSERT(lhs.type->primitive());
    ICE_SCRIPT_ASSERT(rhs.type->primitive());
    
    Value* lhsValue = lhs;
    if (isa<AllocaInst>(lhsValue))
    {
        lhsValue = llvm.builder().CreateLoad(lhsValue);
    }
    
    switch (lhs.type->typeId())
    {
//        case Type::TypeId::BOOLEAN: return llvm.builder().CreateICmpEQ(lhs, rhs);
        case Type::TypeId::INTEGER8: return llvm.builder().CreateICmpSLT(lhsValue, rhs);
        case Type::TypeId::INTEGER16: return llvm.builder().CreateICmpSLT(lhsValue, rhs);
        case Type::TypeId::INTEGER32: return llvm.builder().CreateICmpSLT(lhsValue, rhs);
        case Type::TypeId::INTEGER: return llvm.builder().CreateICmpSLT(lhsValue, rhs);
        case Type::TypeId::INTEGER64: return llvm.builder().CreateICmpSLT(lhsValue, rhs);
        case Type::TypeId::UINTEGER8: return llvm.builder().CreateICmpULT(lhsValue, rhs);
        case Type::TypeId::UINTEGER16: return llvm.builder().CreateICmpULT(lhsValue, rhs);
        case Type::TypeId::UINTEGER32: return llvm.builder().CreateICmpULT(lhsValue, rhs);
        case Type::TypeId::UINTEGER: return llvm.builder().CreateICmpULT(lhsValue, rhs);
        case Type::TypeId::UINTEGER64: return llvm.builder().CreateICmpULT(lhsValue, rhs);
        case Type::TypeId::DOUBLE: return llvm.builder().CreateFCmpOLT(lhsValue, rhs);

        default:
            throw InvalidArgumentException("");
    }
}

Value* createAllocation(Context& context, Llvm& llvm, const std::shared_ptr<Type>& type, const std::string& name)
{
    auto llvmType = toLlvmType(context, llvm, *type);
    
    auto alloca = llvm.builder().CreateAlloca(llvmType, 0, name);
    
    if (type->typeId() == Type::TypeId::ARRAY)
    {
        const auto& arrayType = std::dynamic_pointer_cast<ArrayType>(type);
        
        ICE_SCRIPT_ASSERT(arrayType);
        
        const auto& optionalDimension = arrayType->dimensions()[0];
        
        const auto length = (optionalDimension ? optionalDimension.get() : 0) * 4;//arraytype->type();
        
        auto size = ConstantInt::get(llvm.context(), APInt(64, length + 8, true));
        
        // ;   %arrayMem = alloca i8, i64 12, align 1
        auto allocaStorage = llvm.builder().CreateAlloca(llvmType->getPointerElementType(), size);
        
        // ;   store i8* %arrayMem, i8** %array, align 1
        llvm.builder().CreateStore(allocaStorage, alloca);
    }
    
    return alloca;
}

auto createCall(Context& context, Llvm& llvm, Function* function, Value* variable)
{
    std::vector<Value*> arguments{variable};
    
    return llvm.builder().CreateCall(function, arguments);
}

Value* getPointerToVariableInArray(Context& context, Llvm& llvm, ::llvm::Type* llvmElementType, Value* llvmArrayValue, const TypeValue& indexValue)
{
    const auto& uInt8Type = context.typeTable().get(Type::TypeId::UINTEGER8)[0];
    const auto& uInt8PointerType = context.typeTable().get(uInt8Type, TypeQualifier::TypeQualifierFlags::NONE, TypeModifier::POINTER);
    
    const auto& uInt64Type = context.typeTable().get(Type::TypeId::UINTEGER64)[0];
    const auto& uInt64PointerType = context.typeTable().get(uInt64Type, TypeQualifier::TypeQualifierFlags::NONE, TypeModifier::POINTER);
    
    auto llvmUint8Type = &context.llvmTypeTable().getByKey(uInt8Type->key());
    auto llvmUint8PointerType = &context.llvmTypeTable().getByKey(uInt8PointerType->key());
    auto llvmUint64PointerType = &context.llvmTypeTable().getByKey(uInt64PointerType->key());
    
    const auto typeSize = llvm.module().getDataLayout().getTypeAllocSize(llvmElementType);
    
    // %arrayPtr = load i8*, i8** %array, align 1
    auto array = llvm.builder().CreateLoad(llvmArrayValue);
    
    auto loadedIndexValue = llvm.builder().CreateLoad(indexValue);
    
    auto cast = createPrimitiveCast(context, llvm, uInt64Type, {indexValue.type, loadedIndexValue});
    
    // auto index = ConstantInt::get(llvm.context(), APInt(64, value, true));
    auto sizeOf = ConstantInt::get(llvm.context(), APInt(64, typeSize, true));
    auto lengthOffset = ConstantInt::get(llvm.context(), APInt(64, 8, true));
    auto indexPart0 = llvm.builder().CreateMul(sizeOf, cast);
    auto index = llvm.builder().CreateAdd(lengthOffset, indexPart0);
    
    auto element = llvm.builder().CreateInBoundsGEP(llvmUint8Type, array, index);
    auto elementCasted = llvm.builder().CreateBitCast(element, llvmElementType->getPointerTo());
    
    return elementCasted;
}

auto getLengthVariable(Context& context, Llvm& llvm, Argument* thisArgument)
{
    const auto& uInt8Type = context.typeTable().get(Type::TypeId::UINTEGER8)[0];
    const auto& uInt8PointerType = context.typeTable().get(uInt8Type, TypeQualifier::TypeQualifierFlags::NONE, TypeModifier::POINTER);
    
    const auto& uInt64Type = context.typeTable().get(Type::TypeId::UINTEGER64)[0];
    const auto& uInt64PointerType = context.typeTable().get(uInt64Type, TypeQualifier::TypeQualifierFlags::NONE, TypeModifier::POINTER);
    
    auto llvmUint8PointerType = &context.llvmTypeTable().getByKey(uInt8PointerType->key());
    auto llvmUint64PointerType = &context.llvmTypeTable().getByKey(uInt64PointerType->key());
    
    // %arrayPtr = load i8*, i8** %array, align 1
    auto lhs = llvm.builder().CreateLoad(thisArgument);
    
    // %arrayLength = bitcast i8* %arrayPtr to i64*
    return llvm.builder().CreateBitCast(lhs, llvmUint64PointerType);

    // auto gepInst = GetElementPtrInst::Create(llvmUint8PointerType, thisArgument, {zero, index});
            
    // auto castInst = CastInst::CreatePointerBitCastOrAddrSpaceCast(gepInst, llvmUint64PointerType);
    
    // return castInst;
//     GetElementPtrInst* getElementPtrInst = dyn_cast<GetElementPtrInst>(load);
// //            auto loadInstruction = llvm_->builder().CreateLoad(allocaInst);
//         load = llvm.builder().CreateLoad(getElementPtrInst);
//         // llvm.builder().CreateStore(loadInstruction, alloca);
}

template<
    typename T,
    typename = typename std::enable_if_t<std::is_floating_point_v<T>, T>
>
auto createAssignment(Context& context, Llvm& llvm, Value* llvmValue, const T value)
{
    auto llvmRhs = ConstantFP::get(llvm.context(), APFloat(value));
    auto store = llvm.builder().CreateStore(llvmRhs, llvmValue);
    
    return store;
}

template<
    typename T,
    typename = typename std::enable_if_t<std::is_integral_v<T>, T>,
    typename = typename std::enable_if_t<!std::is_same_v<bool, T>, T>,
    typename = typename std::enable_if_t<!std::is_same_v<char, T>, T>
>
auto createAssignment(Context& context, Llvm& llvm, Value* llvmValue, const T value)
{
    auto llvmRhs = ConstantInt::get(llvm.context(), APInt(sizeof(T) * 8, value, std::is_signed_v<T>));
    auto store = llvm.builder().CreateStore(llvmRhs, llvmValue);
    
    return store;
}

auto createConstant(Context& context, Llvm& llvm, const uint32_t value)
{
    return ConstantInt::get(llvm.context(), APInt(32, value, true));
}

void createForLoop(Context& context, Llvm& llvm, const uint32_t value, std::function<void(const TypeValue&)> body)
{
    const auto& uInt32Type = context.typeTable().get(Type::TypeId::UINTEGER32)[0];
    
    auto allocation = createAllocation(context, llvm, uInt32Type, "i");
    
    auto function = llvm.builder().GetInsertBlock()->getParent();
    
    auto loop = BasicBlock::Create(llvm.context(), "loop", function);
    auto loopBody = BasicBlock::Create(llvm.context(), "loop_body");
    auto loopEpilogue = BasicBlock::Create(llvm.context(), "loop_epilogue");
    auto loopDone = BasicBlock::Create(llvm.context(), "loop_done");
    
    llvm.builder().CreateBr(loop);

    llvm.builder().SetInsertPoint(loop);
    
    auto loopLimit = createConstant(context, llvm, value);
    
    auto lessThan = createPrimitiveLessThan(context, llvm, {uInt32Type, allocation}, {uInt32Type, loopLimit});
    
    auto branchInstruction = llvm.builder().CreateCondBr(lessThan, loopBody, loopDone);
    
    function->getBasicBlockList().push_back(loopBody);
    llvm.builder().SetInsertPoint(loopBody);
    
    body({uInt32Type, allocation});
    
    llvm.builder().CreateBr(loopEpilogue);

    function->getBasicBlockList().push_back(loopEpilogue);
    llvm.builder().SetInsertPoint(loopEpilogue);
    
    auto postfixIncrement = createPrimitivePostfixIncrement(context, llvm, {uInt32Type, allocation});

    llvm.builder().CreateBr(loop);

    function->getBasicBlockList().push_back(loopDone);
    llvm.builder().SetInsertPoint(loopDone);
}

auto getConstructorSymbol(const std::shared_ptr<Type>& type)
{
    return std::make_shared<FunctionSymbol>();
}

void generateConstructor(Context& context, Llvm& llvm, const std::shared_ptr<ArraySymbol>& arraySymbol, const std::shared_ptr<FunctionSymbol>& constructor)
{
    auto function = &context.llvmSymbolTable().getFunctionByKey(constructor->key());
    
    auto basicBlock = BasicBlock::Create(llvm.context(), "entry", function);    
    
    llvm.builder().SetInsertPoint(basicBlock);
    
    auto thisArgument = function->getArg(0);
    
    const auto& parameters = constructor->type()->parameters().getAll();
    
    const auto& constReferenceType = context.typeTable().find(constructor->ownerSymbol()->type(), TypeQualifier::CONSTANT, TypeModifier::REFERENCE);
    
    auto llvmElementType = &context.llvmTypeTable().getByKey(arraySymbol->type()->type()->key());
    
    const auto& optionalDimensions = arraySymbol->type()->dimensions()[0];
    
    if (parameters.empty())
    {
        // Default constructor
        if (!optionalDimensions)
        {
            /*
                T(uint8* this)
                {
                    uint64* length = (uint64*)this;
                    uint8* data = this + (4 x sizeof(uint8);
                    
                    *length = 0;
                }
                
                T[](T[]* this)
                {
                    this.length = 0;
                }
            */
            
            
            auto lengthVariable = getLengthVariable(context, llvm, thisArgument);
            auto assign = createAssignment(context, llvm, lengthVariable, 0);
        }
        else if (optionalDimensions)
        {
            /*
                T(uint8* this)
                {
                    uint64 length = (uint64*)this;
                    uint8* data = this + (4 x sizeof(uint8);
                    
                    *length = dimensions;
                    
                    for (int i=0; i < *length; ++i)
                    {
                        T* object = (T*)data;
                        
                        T(object);
                        
                        data += sizeof(T);
                    }
                }
                
                T[x](T[x]* this)
                {
                    this.length = x;
                    
                    for (int i=0; i < this.length; ++i)
                    {
                        this[i] = T();
                    }
                }
            */
            
            auto lengthVariable = getLengthVariable(context, llvm, thisArgument);
            auto assign = createAssignment(context, llvm, lengthVariable, static_cast<uint64_t>(optionalDimensions.get()));
            
            createForLoop(context, llvm, optionalDimensions.get(), [&](const auto& iTypeValue) {
                auto variable = getPointerToVariableInArray(context, llvm, llvmElementType, thisArgument, iTypeValue);
                
                if (arraySymbol->type()->type()->primitive())
                {
                    createAssignment(context, llvm, variable, 0);
                }
                else
                {
                    const auto& constructorSymbol = getConstructorSymbol(arraySymbol->type()->type());
                    
                    auto function = &context.llvmSymbolTable().getFunctionByKey(constructorSymbol->key());
                    
                    createCall(context, llvm, function, variable);
                }
            });
            
            // Assign assign = createAssignment(logger, typeTable, symbolTable, arraySymbol->lengthSymbol(), optionalDimensions.get());
            
            // function.body.get().values.push_back(Statement{Expressionstat{assign}});
            
            // For forLoop = createForLoop(logger, typeTable, symbolTable, "i", optionalDimensions.get(), );
            
            // function.body.get().values.push_back(forLoop);
        }
        
        
        
        
        
        // for (const auto& variable : classData.variables)
        // {
        //     if (variable.get().value.type() == typeid(Initlist))
        //     {
        //         // const auto& initlist = boost::get<Initlist>(variable.get().value);
        //     }
        //     else if (variable.get().value.type() == typeid(Expression))
        //     {
        //         const auto& expression = boost::get<Expression>(variable.get().value);
                
        //         auto assign = createAssignment(logger, typeTable, symbolTable, classData.symbol, variable.get().symbol, expression);
                
        //         function.body.get().values.push_back(Statement{Expressionstat{assign}});
        //     }
        //     else if (variable.get().value.type() == typeid(Arglist))
        //     {
        //         // const auto& arglist = boost::get<Arglist>(variable.get().value);
        //     }
        //     else
        //     {
        //         throw RuntimeException("");
        //     }
            
        //     // function.body.get().values.push_back(variable.get());
        // }
        
        // function.body = statblock;
    }
    else if (parameters.size() == 1 && parameters[0] == constReferenceType)
    {
        // Copy constructor
        // Statblock statblock{};
        
        // const auto& classSymbol = std::dynamic_pointer_cast<ClassSymbol>(constructor->ownerSymbol());
        
        // // auto otherSymbol = std::make_shared<Symbol>("other");
    
        // // otherSymbol->setType(constructor->ownerSymbol()->type());
        
        // for (const auto& memberVariable : classSymbol->memberVariables())
        // {
        //     // auto assign = createCopyAssignment(context, classData.symbol, constructor->parameters()[0], memberVariable);
        //     auto assign = createCopyAssignment(context, classData.symbol, constructor->parameters()[0], memberVariable);
        //     function.body.get().values.push_back(Statement{Expressionstat{assign}});
        // }
        
        // function.body = statblock;
    }
    else
    {
        // TODO?
        throw RuntimeException("");
    }
    
    llvm.builder().CreateRetVoid();
    
    // return function;
}

void generateDefaultDefinitions(Context& context, Llvm& llvm)
{
    LOG_DEBUG((&context.logger()), "Adding default definitions");
    
    for (const auto& arraySymbol : context.symbolTable().getAllArrays())
    {
        for (const auto& constructorSymbol : arraySymbol->constructors())
        {
            generateConstructor(context, llvm, arraySymbol, constructorSymbol);
        }
    }
}

}}}}
