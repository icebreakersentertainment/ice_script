#ifndef ICE_SCRIPT_GENERATOR_LLVMUTILITIES_HPP
#define ICE_SCRIPT_GENERATOR_LLVMUTILITIES_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "detail/Format.hpp"
#include "exceptions/RuntimeException.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

// inline ::llvm::Type* toLlvmType(::llvm::LLVMContext& context, const Type& type)
inline ::llvm::Type* toLlvmType(Context& context, Llvm& llvm, const Type& type)
{
//     switch (type.typeId())
//     {
//         case Type::TypeId::VOID_T: return ::llvm::Type::getVoidTy(context);
        
//         case Type::TypeId::INTEGER8:
//             if (type->)
//             return ::llvm::Type::getInt8Ty(context);
//         case Type::TypeId::INTEGER16: return ::llvm::Type::getInt16Ty(context);
//         case Type::TypeId::INTEGER32: return ::llvm::Type::getInt32Ty(context);
//         case Type::TypeId::INTEGER: return ::llvm::Type::getInt32Ty(context);
//         case Type::TypeId::INTEGER64: return ::llvm::Type::getInt64Ty(context);
//         case Type::TypeId::UINTEGER8: return ::llvm::Type::getInt8Ty(context);
//         case Type::TypeId::UINTEGER16: return ::llvm::Type::getInt16Ty(context);
//         case Type::TypeId::UINTEGER32: return ::llvm::Type::getInt32Ty(context);
//         case Type::TypeId::UINTEGER: return ::llvm::Type::getInt32Ty(context);
//         case Type::TypeId::UINTEGER64: return ::llvm::Type::getInt64Ty(context);
//         case Type::TypeId::FLOAT: return ::llvm::Type::getFloatTy(context);
//         case Type::TypeId::DOUBLE: return ::llvm::Type::getDoubleTy(context);
//         case Type::TypeId::CLASS: return ::llvm::StructType::getTypeByName(context, type.name());
// //        case Type::TypeId::FUNCTION: return ::llvm::Type::getDoubleTy(context);
// //        case Type::TypeId::OPERATOR: return ::llvm::Type::getDoubleTy(context);

//         default:
//             throw RuntimeException(ice_script::detail::format("Unknown type id '%s'", type.typeId()));
//     }
    switch (type.typeId())
    {
        case Type::TypeId::VOID_T:
            return ::llvm::Type::getVoidTy(llvm.context());
            
        case Type::TypeId::INTEGER8:
            if (type.modifier() == TypeModifier::REFERENCE) return ::llvm::Type::getInt8PtrTy(llvm.context());
            
            return ::llvm::Type::getInt8Ty(llvm.context());
            
        case Type::TypeId::INTEGER16:
            if (type.modifier() == TypeModifier::REFERENCE) return ::llvm::Type::getInt16PtrTy(llvm.context());
            
            return ::llvm::Type::getInt16Ty(llvm.context());
            
        case Type::TypeId::INTEGER32:
            if (type.modifier() == TypeModifier::REFERENCE) return ::llvm::Type::getInt32PtrTy(llvm.context());
            
            return ::llvm::Type::getInt32Ty(llvm.context());
            
        case Type::TypeId::INTEGER:
            if (type.modifier() == TypeModifier::REFERENCE) return ::llvm::Type::getInt32PtrTy(llvm.context());
            
            return ::llvm::Type::getInt32Ty(llvm.context());
            
        case Type::TypeId::INTEGER64:
            if (type.modifier() == TypeModifier::REFERENCE) return ::llvm::Type::getInt64PtrTy(llvm.context());
            
            return ::llvm::Type::getInt64Ty(llvm.context());
            
        case Type::TypeId::UINTEGER8:
            if (type.modifier() == TypeModifier::REFERENCE) return ::llvm::Type::getInt8PtrTy(llvm.context());
            
            return ::llvm::Type::getInt8Ty(llvm.context());
            
        case Type::TypeId::UINTEGER16:
            if (type.modifier() == TypeModifier::REFERENCE) return ::llvm::Type::getInt16PtrTy(llvm.context());
            
            return ::llvm::Type::getInt16Ty(llvm.context());
            
        case Type::TypeId::UINTEGER32:
            if (type.modifier() == TypeModifier::REFERENCE) return ::llvm::Type::getInt32PtrTy(llvm.context());
            
            return ::llvm::Type::getInt32Ty(llvm.context());
            
        case Type::TypeId::UINTEGER:
            if (type.modifier() == TypeModifier::REFERENCE) return ::llvm::Type::getInt32PtrTy(llvm.context());
            
            return ::llvm::Type::getInt32Ty(llvm.context());
            
        case Type::TypeId::UINTEGER64:
            if (type.modifier() == TypeModifier::REFERENCE) return ::llvm::Type::getInt64PtrTy(llvm.context());
            
            return ::llvm::Type::getInt64Ty(llvm.context());
            
        case Type::TypeId::FLOAT:
            if (type.modifier() == TypeModifier::REFERENCE) return ::llvm::Type::getFloatPtrTy(llvm.context());
            
            return ::llvm::Type::getFloatTy(llvm.context());
            
        case Type::TypeId::DOUBLE:
            if (type.modifier() == TypeModifier::REFERENCE) return ::llvm::Type::getDoublePtrTy(llvm.context());
            
            return ::llvm::Type::getDoubleTy(llvm.context());
            
        case Type::TypeId::ARRAY:
            return &context.llvmTypeTable().getArrayByKey(type.key());
        
        case Type::TypeId::CLASS:
            return &context.llvmTypeTable().getClassByKey(type.key());
        
//        case Type::TypeId::FUNCTION: return ::llvm::Type::getDoubleTy(context);
//        case Type::TypeId::OPERATOR: return ::llvm::Type::getDoubleTy(context);

        default:
            throw RuntimeException(ice_script::detail::format("Unknown type id '%s'", type.typeId()));
    }
}

// inline std::vector<::llvm::Type*> createParameterTypeList(::llvm::LLVMContext& context, const std::vector<asg::Variable>& parameters)
// {
//     std::vector<::llvm::Type*> parameterList{};

//     for (const auto& parameter : parameters)
//     {
// //        const auto& type = parameter.type;
// //        const auto& typeMod = parameter.get<1>().get();
// //        const auto& identifier = parameter.get<2>();
// //        const auto& expression = parameter.get<3>();

// //        auto param = Type::getInt64Ty(llvm_->context());
// //        auto paramType = llvmType(type);

// //        auto paramType = ::llvm::Type::getInt64Ty(context);

//         auto paramType = toLlvmType(context, *parameter.type);

//         parameterList.push_back(paramType);
//     }

//     return parameterList;
// }

}}}}

#endif //ICE_SCRIPT_GENERATOR_LLVMUTILITIES_HPP
