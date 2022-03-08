#ifndef ICE_SCRIPT_GENERATOR_LLVMUTILITIES_HPP
#define ICE_SCRIPT_GENERATOR_LLVMUTILITIES_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "detail/Format.hpp"
#include "exceptions/RuntimeException.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

inline ::llvm::Type* toLlvmType(::llvm::LLVMContext& context, const asg::Type& type)
{
    switch (type.typeId())
    {
        case asg::Type::TypeId::INTEGER8: return ::llvm::Type::getInt8Ty(context);
        case asg::Type::TypeId::INTEGER16: return ::llvm::Type::getInt16Ty(context);
        case asg::Type::TypeId::INTEGER32: return ::llvm::Type::getInt32Ty(context);
        case asg::Type::TypeId::INTEGER: return ::llvm::Type::getInt32Ty(context);
        case asg::Type::TypeId::INTEGER64: return ::llvm::Type::getInt64Ty(context);
        case asg::Type::TypeId::UINTEGER8: return ::llvm::Type::getInt8Ty(context);
        case asg::Type::TypeId::UINTEGER16: return ::llvm::Type::getInt16Ty(context);
        case asg::Type::TypeId::UINTEGER32: return ::llvm::Type::getInt32Ty(context);
        case asg::Type::TypeId::UINTEGER: return ::llvm::Type::getInt32Ty(context);
        case asg::Type::TypeId::UINTEGER64: return ::llvm::Type::getInt64Ty(context);
        case asg::Type::TypeId::FLOAT: return ::llvm::Type::getFloatTy(context);
        case asg::Type::TypeId::DOUBLE: return ::llvm::Type::getDoubleTy(context);

        default:
            throw RuntimeException(ice_script::detail::format("Unknown type id '%s'", static_cast<uint32_t>(type.typeId())));
    }
}

inline std::vector<::llvm::Type*> createParameterTypeList(::llvm::LLVMContext& context, const std::vector<asg::Variable>& parameters)
{
    std::vector<::llvm::Type*> parameterList{};

    for (const auto& parameter : parameters)
    {
//        const auto& type = parameter.type;
//        const auto& typeMod = parameter.get<1>().get();
//        const auto& identifier = parameter.get<2>();
//        const auto& expression = parameter.get<3>();

//        auto param = Type::getInt64Ty(llvm_->context());
//        auto paramType = llvmType(type);

//        auto paramType = ::llvm::Type::getInt64Ty(context);

        auto paramType = toLlvmType(context, *parameter.type);

        parameterList.push_back(paramType);
    }

    return parameterList;
}

}}}}

#endif //ICE_SCRIPT_GENERATOR_LLVMUTILITIES_HPP
