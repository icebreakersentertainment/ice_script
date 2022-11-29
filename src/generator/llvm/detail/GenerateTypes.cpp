#include <memory>
#include <string>

#include "generator/llvm/detail/GenerateTypes.hpp"

#include "asg/Asg.hpp"

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "detail/Assert.hpp"
#include "type/Type.hpp"
#include "type/TypeQualifier.hpp"
#include "llvm/IR/DerivedTypes.h"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

::llvm::Type* toLlvmType(Context& context, Llvm& llvm, const std::shared_ptr<Type>& type);

inline ::llvm::Type* createClassType(Context& context, Llvm& llvm, const std::shared_ptr<ClassType>& type)
{
    auto classType = context.typeTable().find(type, type->qualifiers(), TypeModifier::VALUE);
    
    ICE_SCRIPT_ASSERT(classType)
    
    auto llvmType = context.llvmTypeTable().findClassByKey(classType->key());
    
    if (!llvmType)
    {
        std::vector<::llvm::Type*> elements{};

        for (const auto& memberVariable : type->memberVariables())
        {
            auto llvmType = toLlvmType(context, llvm, memberVariable);

            elements.push_back(llvmType);
        }

        llvmType = ::llvm::StructType::create(llvm.context(), elements, type->name());

        // if (type == classType) return llvmType;
    }
    
    if (type->modifier() == TypeModifier::REFERENCE)
    {
        return ::llvm::PointerType::get(llvmType, 0);
    }
    
    return llvmType;
}

inline ::llvm::PointerType* createValueArrayType(Context& context, Llvm& llvm, const std::shared_ptr<ArrayType>& type)
{
    auto arrayType = context.typeTable().find(type, type->qualifiers(), TypeModifier::VALUE);
    
    ICE_SCRIPT_ASSERT(arrayType)
    
    return ::llvm::PointerType::getInt8PtrTy(llvm.context());
}

inline ::llvm::PointerType* createReferenceType(Context& context, Llvm& llvm, const std::shared_ptr<ArrayType>& type)
{
    auto arrayValueType = context.typeTable().find(type, TypeQualifier::NONE, TypeModifier::VALUE);
    
    ICE_SCRIPT_ASSERT(arrayValueType)
    
    auto llvmType = context.llvmTypeTable().findArrayByKey(arrayValueType->key());
    
    return ::llvm::PointerType::get(llvmType, 0);
}

inline ::llvm::PointerType* createPointerType(Context& context, Llvm& llvm, const std::shared_ptr<ArrayType>& type)
{
    auto arrayValueType = context.typeTable().find(type, type->qualifiers(), TypeModifier::VALUE);
    
    ICE_SCRIPT_ASSERT(arrayValueType)
    
    auto llvmType = context.llvmTypeTable().findArrayByKey(arrayValueType->key());
    
    return ::llvm::PointerType::get(llvmType, 0);
}

inline ::llvm::StructType* createValueClassType(Context& context, Llvm& llvm, const std::shared_ptr<ClassType>& type)
{
    auto classType = context.typeTable().find(type, type->qualifiers(), TypeModifier::VALUE);
    
    ICE_SCRIPT_ASSERT(classType)
    
    std::vector<::llvm::Type*> elements{};

    for (const auto& memberVariable : type->memberVariables())
    {
        auto llvmType = toLlvmType(context, llvm, memberVariable);

        elements.push_back(llvmType);
    }

    return ::llvm::StructType::create(llvm.context(), elements, type->name());
}

inline ::llvm::PointerType* createReferenceType(Context& context, Llvm& llvm, const std::shared_ptr<ClassType>& type)
{
    auto classValueType = context.typeTable().find(type, TypeQualifier::NONE, TypeModifier::VALUE);
    
    ICE_SCRIPT_ASSERT(classValueType)
    
    auto llvmType = context.llvmTypeTable().findClassByKey(classValueType->key());

    auto pointerType = ::llvm::PointerType::get(llvmType, 0);

    return pointerType;
}

inline ::llvm::PointerType* createPointerType(Context& context, Llvm& llvm, const std::shared_ptr<ClassType>& type)
{
    auto classValueType = context.typeTable().find(type, type->qualifiers(), TypeModifier::VALUE);
    
    ICE_SCRIPT_ASSERT(classValueType)
    
    auto llvmType = context.llvmTypeTable().findClassByKey(classValueType->key());

    auto pointerType = ::llvm::PointerType::get(llvmType, 0);

    return pointerType;
}

inline ::llvm::Type* toLlvmType(Context& context, Llvm& llvm, const std::shared_ptr<Type>& type)
{
    switch (type->typeId())
    {
        case Type::TypeId::VOID_T:
            return ::llvm::Type::getVoidTy(llvm.context());
            
        case Type::TypeId::BOOLEAN:
            if (type->modifier() == TypeModifier::REFERENCE || type->modifier() == TypeModifier::POINTER) return ::llvm::Type::getInt1PtrTy(llvm.context());
            
            return ::llvm::Type::getInt1Ty(llvm.context());
        
        case Type::TypeId::INTEGER8:
            if (type->modifier() == TypeModifier::REFERENCE || type->modifier() == TypeModifier::POINTER) return ::llvm::Type::getInt8PtrTy(llvm.context());
            
            return ::llvm::Type::getInt8Ty(llvm.context());
            
        case Type::TypeId::INTEGER16:
            if (type->modifier() == TypeModifier::REFERENCE || type->modifier() == TypeModifier::POINTER) return ::llvm::Type::getInt16PtrTy(llvm.context());
            
            return ::llvm::Type::getInt16Ty(llvm.context());
            
        case Type::TypeId::INTEGER32:
            if (type->modifier() == TypeModifier::REFERENCE || type->modifier() == TypeModifier::POINTER) return ::llvm::Type::getInt32PtrTy(llvm.context());
            
            return ::llvm::Type::getInt32Ty(llvm.context());
            
        case Type::TypeId::INTEGER:
            if (type->modifier() == TypeModifier::REFERENCE || type->modifier() == TypeModifier::POINTER) return ::llvm::Type::getInt32PtrTy(llvm.context());
            
            return ::llvm::Type::getInt32Ty(llvm.context());
            
        case Type::TypeId::INTEGER64:
            if (type->modifier() == TypeModifier::REFERENCE || type->modifier() == TypeModifier::POINTER) return ::llvm::Type::getInt64PtrTy(llvm.context());
            
            return ::llvm::Type::getInt64Ty(llvm.context());
            
        case Type::TypeId::UINTEGER8:
            if (type->modifier() == TypeModifier::REFERENCE || type->modifier() == TypeModifier::POINTER) return ::llvm::Type::getInt8PtrTy(llvm.context());
            
            return ::llvm::Type::getInt8Ty(llvm.context());
            
        case Type::TypeId::UINTEGER16:
            if (type->modifier() == TypeModifier::REFERENCE || type->modifier() == TypeModifier::POINTER) return ::llvm::Type::getInt16PtrTy(llvm.context());
            
            return ::llvm::Type::getInt16Ty(llvm.context());
            
        case Type::TypeId::UINTEGER32:
            if (type->modifier() == TypeModifier::REFERENCE || type->modifier() == TypeModifier::POINTER) return ::llvm::Type::getInt32PtrTy(llvm.context());
            
            return ::llvm::Type::getInt32Ty(llvm.context());
            
        case Type::TypeId::UINTEGER:
            if (type->modifier() == TypeModifier::REFERENCE || type->modifier() == TypeModifier::POINTER) return ::llvm::Type::getInt32PtrTy(llvm.context());
            
            return ::llvm::Type::getInt32Ty(llvm.context());
            
        case Type::TypeId::UINTEGER64:
            if (type->modifier() == TypeModifier::REFERENCE || type->modifier() == TypeModifier::POINTER) return ::llvm::Type::getInt64PtrTy(llvm.context());
            
            return ::llvm::Type::getInt64Ty(llvm.context());
            
        case Type::TypeId::FLOAT:
            if (type->modifier() == TypeModifier::REFERENCE || type->modifier() == TypeModifier::POINTER) return ::llvm::Type::getFloatPtrTy(llvm.context());
            
            return ::llvm::Type::getFloatTy(llvm.context());
            
        case Type::TypeId::DOUBLE:
            if (type->modifier() == TypeModifier::REFERENCE || type->modifier() == TypeModifier::POINTER) return ::llvm::Type::getDoublePtrTy(llvm.context());
            
            return ::llvm::Type::getDoubleTy(llvm.context());
            
        case Type::TypeId::ARRAY:
        {
            auto llvmType = context.llvmTypeTable().findByKey(type->key());
            
            if (llvmType) return llvmType;
            
            const auto arrayType = std::dynamic_pointer_cast<ArrayType>(type);
            
            ICE_SCRIPT_ASSERT(arrayType);

            if (arrayType->modifier() == TypeModifier::VALUE)
            {
                auto llvmArrayType = createValueArrayType(context, llvm, arrayType);
                
                context.llvmTypeTable().addValueType(arrayType, llvmArrayType);
                
                return llvmArrayType;
            }
            else if (arrayType->modifier() == TypeModifier::REFERENCE)
            {
                auto referenceType = createReferenceType(context, llvm, arrayType);
                
                context.llvmTypeTable().addReferenceType(arrayType, referenceType);
                
                return referenceType;
            }
            else if (arrayType->modifier() == TypeModifier::POINTER)
            {
                auto pointerType = createPointerType(context, llvm, arrayType);
                
                context.llvmTypeTable().addPointerType(arrayType, pointerType);
                
                return pointerType;
            }
        }
               
        case Type::TypeId::CLASS:
        {
            auto llvmType = context.llvmTypeTable().findByKey(type->key());
            
            if (llvmType) return llvmType;
            
            const auto classType = std::dynamic_pointer_cast<ClassType>(type);
            
            ICE_SCRIPT_ASSERT(classType);

            if (classType->modifier() == TypeModifier::VALUE)
            {
                auto structType = createValueClassType(context, llvm, classType);
                
                context.llvmTypeTable().add(classType, structType);
                
                return structType;
            }
            else if (classType->modifier() == TypeModifier::REFERENCE)
            {
                auto referenceType = createReferenceType(context, llvm, classType);
                
                context.llvmTypeTable().add(classType, referenceType);
                
                return referenceType;
            }
            else if (classType->modifier() == TypeModifier::POINTER)
            {
                auto pointerType = createPointerType(context, llvm, classType);
                
                context.llvmTypeTable().add(classType, pointerType);
                
                return pointerType;
            }
        }
//        case Type::TypeId::FUNCTION: return ::llvm::Type::getDoubleTy(context);
//        case Type::TypeId::OPERATOR: return ::llvm::Type::getDoubleTy(context);

        default:
            throw RuntimeException(ice_script::detail::format("Unknown type id '%s'", type->typeId()));
    }
}

inline std::vector<::llvm::Type*> createParameterTypeList(Context& context, Llvm& llvm, const std::vector<std::shared_ptr<Type>>& parameters)
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

        auto paramType = toLlvmType(context, llvm, parameter);
        
        // if (parameter->primitive() && !paramType->isPointerTy())
        if (!paramType->isPointerTy())
        {
            paramType = ::llvm::PointerType::get(paramType, 0);
        }

        parameterList.push_back(paramType);
    }

    return parameterList;
}

void generateTypes(Context& context, Llvm& llvm)
{
    LOG_DEBUG((&context.logger()), "Generating types for llvm")

    const auto& primitiveTypes = context.typeTable().getAllPrimitives();
    // const auto functions = context.symbolTable().getAllFunctions();

    for (const auto& primitiveType : primitiveTypes)
    {
        // auto llvmFunction = context.llvmSymbolTable().findFunctionByKey(primitiveType->key());
        auto llvmPrimitiveType = context.llvmTypeTable().findByKey(primitiveType->key());

        if (llvmPrimitiveType) continue;

        llvmPrimitiveType = toLlvmType(context, llvm, primitiveType);

        // llvmPrimitiveType = ::llvm::FunctionType::get(returnType, parameterList, false);

        // auto llvmFunction = ::llvm::Function::Create(llvmFunctionType, ::llvm::Function::ExternalLinkage, functionType->name(), &llvm.module());
        
        // ICE_SCRIPT_ASSERT(llvmFunction->arg_size() == functionType->parameters().size());
        
        // for (size_t i=0; i < llvmFunctionType->arg_size(); ++i)
        // {
        //     auto argument = llvmFunctionType->getArg(i);
            
        //     const auto& parameter = functionType->parameters()[i];
            
        //     argument->setName(parameter->name());
        // }

        context.llvmTypeTable().add(primitiveType, llvmPrimitiveType);
        // context.llvmSymbolTable().add(*functionType, llvmFunction);

//        ::llvm::FunctionCallee functionCallee = llvm.module().getOrInsertFunction(function->name(), functionType);
//        functionCallee.getCallee()
    }

    const auto& functionTypes = context.typeTable().getAllFunctions();
    // const auto functions = context.symbolTable().getAllFunctions();

    for (const auto& functionType : functionTypes)
    {
        if (functionType->isConstructor() || functionType->isMethod()) continue;
        
        // auto llvmFunction = context.llvmSymbolTable().findFunctionByKey(functionType->key());
        auto llvmFunctionType = context.llvmTypeTable().findFunctionByKey(functionType->key());

        if (llvmFunctionType) continue;

        auto parameterList = createParameterTypeList(context, llvm, functionType->parameters().getAll());
        auto returnType = toLlvmType(context, llvm, functionType->returnType());

        llvmFunctionType = ::llvm::FunctionType::get(returnType, parameterList, false);

        // auto llvmFunction = ::llvm::Function::Create(llvmFunctionType, ::llvm::Function::ExternalLinkage, functionType->name(), &llvm.module());
        
        // ICE_SCRIPT_ASSERT(llvmFunction->arg_size() == functionType->parameters().size());
        
        // for (size_t i=0; i < llvmFunctionType->arg_size(); ++i)
        // {
        //     auto argument = llvmFunctionType->getArg(i);
            
        //     const auto& parameter = functionType->parameters()[i];
            
        //     argument->setName(parameter->name());
        // }

        context.llvmTypeTable().add(functionType, llvmFunctionType);
        // context.llvmSymbolTable().add(*functionType, llvmFunction);

//        ::llvm::FunctionCallee functionCallee = llvm.module().getOrInsertFunction(function->name(), functionType);
//        functionCallee.getCallee()
    }

    const auto& classTypes = context.typeTable().getAllClasses();
    
    for (const auto& classType : classTypes)
    {
        auto llvmClassType = context.llvmTypeTable().findClassByKey(classType->key());
        
        if (llvmClassType) continue;
        
        switch (classType->modifier())
        {
            case TypeModifier::VALUE:
                context.llvmTypeTable().add(classType, createValueClassType(context, llvm, classType));
                break;
                
            case TypeModifier::REFERENCE:
                context.llvmTypeTable().add(classType, createReferenceType(context, llvm, classType));
                break;
                
            case TypeModifier::POINTER:
                context.llvmTypeTable().add(classType, createPointerType(context, llvm, classType));
                break;
                
            default:
                throw RuntimeException("");
        }
    }

    for (const auto& classType : classTypes)
    {
        auto llvmClassType = context.llvmTypeTable().findClassByKey(classType->key());
        
        ICE_SCRIPT_ASSERT(llvmClassType)

        // if (llvmStruct) continue;

        // llvmStruct = createClassType(context, llvm, _class->type());
        
        // context.llvmTypeTable().add(_class->type(), llvmStruct);
        
        // auto classReferenceType = context.typeTable().find(_class->type(), _class->type()->qualifiers(), TypeModifier::REFERENCE);
        // auto classPointerType = context.typeTable().find(_class->type(), _class->type()->qualifiers(), TypeModifier::POINTER);
        // // auto classSmartPointerType = context.typeTable().findSmartPointerType(_class->type());
            
        // ICE_SCRIPT_ASSERT(classReferenceType)
        // ICE_SCRIPT_ASSERT(classPointerType)
        // // ICE_SCRIPT_ASSERT(classSmartPointerType)
        
        // auto llvmStructRef = createReferenceType(context, llvm, classReferenceType);
        // auto llvmStructPtr = createPointerType(context, llvm, classPointerType);
        // // auto llvmStructSmrtPtr = createClassType(context, llvm, *classSmartPointerType);

        // context.llvmTypeTable().add(classReferenceType, llvmStructRef);
        // context.llvmTypeTable().add(classPointerType, llvmStructPtr);
        // // context.llvmTypeTable().add(*classSmartPointerType, llvmStructSmrtPtr);

        for (const auto& constructorType : classType->constructors())
        {
            auto llvmFunctionType = context.llvmTypeTable().findFunctionByKey(constructorType->key());
            // auto llvmFunction = context.llvmSymbolTable().findFunctionByKey(constructorType->key());

            ICE_SCRIPT_ASSERT(!llvmFunctionType)

            std::vector<std::shared_ptr<Type>> parameterTypes{};
            
            auto classPointerType = context.typeTable().find(constructorType, constructorType->qualifiers(), TypeModifier::POINTER);
            
            ICE_SCRIPT_ASSERT(classPointerType)

            parameterTypes.push_back(classPointerType);

            for (const auto& parameterType : constructorType->parameters()) parameterTypes.push_back(parameterType);

            auto parameterList = createParameterTypeList(context, llvm, parameterTypes);
            // auto returnType = toLlvmType(context, llvm, constructor->type()->returnType());
            auto returnType = toLlvmType(context, llvm, context.typeTable().get(Type::TypeId::VOID_T)[0]);

            llvmFunctionType = ::llvm::FunctionType::get(returnType, parameterList, false);

            // llvmFunctionType = ::llvm::Function::Create(llvmFunctionType, ::llvm::Function::ExternalLinkage, constructorType->name(), &llvm.module());
            
            // // The first parameter is "this"
            // llvmFunctionType->args().begin()->setName("this");
            
            // ICE_SCRIPT_ASSERT(llvmFunctionType->arg_size() == constructorType->parameters().size() + 1);
            
            // for (size_t i=1; i < llvmFunctionType->arg_size(); ++i)
            // {
            //     auto argument = llvmFunctionType->getArg(i);
                
            //     const auto& parameter = constructorType->parameters()[i - 1];
                
            //     argument->setName(parameter->name());
            // }
            
            // context.llvmSymbolTable().add(*constructorType, llvmFunctionType);
            context.llvmTypeTable().add(constructorType, llvmFunctionType);

    //        ::llvm::FunctionCallee functionCallee = llvm.module().getOrInsertFunction(function->name(), functionType);
    //        functionCallee.getCallee()
        }
        
    //     for (const auto& function : classType->functions())
    //     {
    //         // auto llvmFunction = context.llvmTypeTable().findFunctionByKey(constructor->key());
    //         auto llvmFunction = context.llvmSymbolTable().findFunctionByKey(function->key());

    //         ICE_SCRIPT_ASSERT(!llvmFunction)

    //         std::vector<std::shared_ptr<Type>> parameters{};
            
    //         auto classPointerType = context.typeTable().find(constructorType, constructorType->qualifiers(), TypeModifier::POINTER);
            
    //         ICE_SCRIPT_ASSERT(classPointerType)

    //         parameters.push_back(classPointerType);

    //         for (const auto& parameter : function->parameters()) parameters.push_back(parameter->type());

    //         auto parameterList = createParameterTypeList(context, llvm, parameters);
    //         auto returnType = toLlvmType(context, llvm, function->type()->returnType());
    //         // auto returnType = toLlvmType(context, llvm, context.typeTable().get(Type::TypeId::VOID_T)[0]);

    //         ::llvm::FunctionType* functionType = ::llvm::FunctionType::get(returnType, parameterList, false);

    //         llvmFunction = ::llvm::Function::Create(functionType, ::llvm::Function::ExternalLinkage, function->name(), &llvm.module());
            
    //         // The first parameter is "this"
    //         llvmFunction->args().begin()->setName("this");
            
    //         ICE_SCRIPT_ASSERT(llvmFunction->arg_size() == function->parameters().size() + 1);
            
    //         for (size_t i=1; i < llvmFunction->arg_size(); ++i)
    //         {
    //             auto argument = llvmFunction->getArg(i);
                
    //             const auto& parameter = function->parameters()[i - 1];
                
    //             argument->setName(parameter->name());
    //         }
            
    //         context.llvmSymbolTable().add(*function, llvmFunction);

    // //        ::llvm::FunctionCallee functionCallee = llvm.module().getOrInsertFunction(function->name(), functionType);
    // //        functionCallee.getCallee()
    //     }

//        context.llvmTypeTable().add(*_class, llvmStruct);

//        ::llvm::FunctionCallee functionCallee = llvm.module().getOrInsertFunction(function->name(), functionType);
//        functionCallee.getCallee()
    }
    
//     const auto symbols = context.symbolTable().getAll();
    
//     for (const auto& symbol : symbols)
//     {
//         if (!symbol->global()) continue;
        
//         auto llvmGlobal = context.llvmSymbolTable().findByKey(symbol->key());
        
//         if (llvmGlobal) continue;
        
//         auto llvmType = toLlvmType(context, llvm, symbol->type());
        
//         llvmGlobal = llvm.module().getOrInsertGlobal(symbol->name(), llvmType);
        
//         context.llvmSymbolTable().add(*symbol, llvmGlobal);
//     }
    
    const auto& arrayTypes = context.typeTable().getAllArrays();
    
    for (const auto& arrayType : arrayTypes)
    {
        auto llvmType = context.llvmTypeTable().findArrayByKey(arrayType->key());
        
        if (llvmType) continue;
        
        switch (arrayType->modifier())
        {
            case TypeModifier::VALUE:
                context.llvmTypeTable().add(arrayType, createValueArrayType(context, llvm, arrayType));
                break;
                
            case TypeModifier::REFERENCE:
                context.llvmTypeTable().add(arrayType, createReferenceType(context, llvm, arrayType));
                break;
                
            case TypeModifier::POINTER:
                context.llvmTypeTable().add(arrayType, createPointerType(context, llvm, arrayType));
                break;
                
            default:
                throw RuntimeException("");
        }
    }
    
    for (const auto& arrayType : arrayTypes)
    {
        auto llvmPointer = context.llvmTypeTable().findArrayByKey(arrayType->key());
        
        ICE_SCRIPT_ASSERT(llvmPointer)

        for (const auto& constructorType : arrayType->constructors())
        {
            auto llvmFunctionType = context.llvmTypeTable().findFunctionByKey(constructorType->key());
            // auto llvmFunction = context.llvmSymbolTable().findFunctionByKey(constructorType->key());

            ICE_SCRIPT_ASSERT(!llvmFunctionType)

            std::vector<std::shared_ptr<Type>> parameterTypes{};
            
            auto arrayPointerType = context.typeTable().find(arrayType, arrayType->qualifiers(), TypeModifier::POINTER);
            
            ICE_SCRIPT_ASSERT(arrayPointerType)

            parameterTypes.push_back(arrayPointerType);

            for (const auto& parameterType : constructorType->parameters()) parameterTypes.push_back(parameterType);

            auto parameterList = createParameterTypeList(context, llvm, parameterTypes);
            // auto returnType = toLlvmType(context, llvm, constructor->type()->returnType());
            auto returnType = toLlvmType(context, llvm, context.typeTable().get(Type::TypeId::VOID_T)[0]);

            llvmFunctionType = ::llvm::FunctionType::get(returnType, parameterList, false);

            // auto llvmFunction = ::llvm::Function::Create(llvmFunctionType, ::llvm::Function::ExternalLinkage, constructorType->name(), &llvm.module());
            
            // // The first parameter is "this"
            // llvmFunction->args().begin()->setName("this");
            
            // ICE_SCRIPT_ASSERT(llvmFunction->arg_size() == constructorType->parameters().size() + 1);
            
            // for (size_t i=1; i < llvmFunction->arg_size(); ++i)
            // {
            //     auto argument = llvmFunction->getArg(i);
                
            //     const auto& parameter = constructorType->parameters()[i - 1];
                
            //     argument->setName(parameter->name());
            // }
            
            // context.llvmSymbolTable().add(*constructorType, llvmFunction);
            context.llvmTypeTable().add(constructorType, llvmFunctionType);

    //        ::llvm::FunctionCallee functionCallee = llvm.module().getOrInsertFunction(function->name(), functionType);
    //        functionCallee.getCallee()
        }
        
        for (const auto& operatorType : arrayType->operators())
        {
            auto llvmFunctionType = context.llvmTypeTable().findFunctionByKey(operatorType->key());
            // auto llvmFunction = context.llvmSymbolTable().findFunctionByKey(constructorType->key());

            ICE_SCRIPT_ASSERT(!llvmFunctionType)

            std::vector<std::shared_ptr<Type>> parameterTypes{};
            
            auto arrayPointerType = context.typeTable().find(arrayType, arrayType->qualifiers(), TypeModifier::POINTER);
            
            ICE_SCRIPT_ASSERT(arrayPointerType)

            parameterTypes.push_back(arrayPointerType);

            for (const auto& parameterType : operatorType->parameters()) parameterTypes.push_back(parameterType);

            auto parameterList = createParameterTypeList(context, llvm, parameterTypes);
            auto returnType = toLlvmType(context, llvm, operatorType->returnType());
            // auto returnType = toLlvmType(context, llvm, context.typeTable().get(Type::TypeId::VOID_T)[0]);

            llvmFunctionType = ::llvm::FunctionType::get(returnType, parameterList, false);

            // auto llvmFunction = ::llvm::Function::Create(llvmFunctionType, ::llvm::Function::ExternalLinkage, constructorType->name(), &llvm.module());
            
            // // The first parameter is "this"
            // llvmFunction->args().begin()->setName("this");
            
            // ICE_SCRIPT_ASSERT(llvmFunction->arg_size() == constructorType->parameters().size() + 1);
            
            // for (size_t i=1; i < llvmFunction->arg_size(); ++i)
            // {
            //     auto argument = llvmFunction->getArg(i);
                
            //     const auto& parameter = constructorType->parameters()[i - 1];
                
            //     argument->setName(parameter->name());
            // }
            
            // context.llvmSymbolTable().add(*constructorType, llvmFunction);
            context.llvmTypeTable().add(operatorType, llvmFunctionType);

    //        ::llvm::FunctionCallee functionCallee = llvm.module().getOrInsertFunction(function->name(), functionType);
    //        functionCallee.getCallee()
        }
        
    //     for (const auto& function : arrayType->functions())
    //     {
    //         // auto llvmFunction = context.llvmTypeTable().findFunctionByKey(constructor->key());
    //         auto llvmFunction = context.llvmSymbolTable().findFunctionByKey(function->key());

    //         ICE_SCRIPT_ASSERT(!llvmFunction)

    //         std::vector<std::shared_ptr<Type>> parameters{};
            
    //         auto arrayPointerType = context.typeTable().find(array->type(), array->type()->qualifiers(), TypeModifier::POINTER);
            
    //         ICE_SCRIPT_ASSERT(arrayPointerType)

    //         parameters.push_back(arrayPointerType);

    //         for (const auto& parameter : function->parameters()) parameters.push_back(parameter->type());

    //         auto parameterList = createParameterTypeList(context, llvm, parameters);
    //         auto returnType = toLlvmType(context, llvm, function->type()->returnType());
    //         // auto returnType = toLlvmType(context, llvm, context.typeTable().get(Type::TypeId::VOID_T)[0]);

    //         ::llvm::FunctionType* functionType = ::llvm::FunctionType::get(returnType, parameterList, false);

    //         llvmFunction = ::llvm::Function::Create(functionType, ::llvm::Function::ExternalLinkage, function->name(), &llvm.module());
            
    //         // The first parameter is "this"
    //         llvmFunction->args().begin()->setName("this");
            
    //         ICE_SCRIPT_ASSERT(llvmFunction->arg_size() == function->parameters().size() + 1);
            
    //         for (size_t i=1; i < llvmFunction->arg_size(); ++i)
    //         {
    //             auto argument = llvmFunction->getArg(i);
                
    //             const auto& parameter = function->parameters()[i - 1];
                
    //             argument->setName(parameter->name());
    //         }
            
    //         context.llvmSymbolTable().add(*function, llvmFunction);

    // //        ::llvm::FunctionCallee functionCallee = llvm.module().getOrInsertFunction(function->name(), functionType);
    // //        functionCallee.getCallee()
    //     }

// //        context.llvmTypeTable().add(*_class, llvmStruct);

// //        ::llvm::FunctionCallee functionCallee = llvm.module().getOrInsertFunction(function->name(), functionType);
// //        functionCallee.getCallee()
    }
}

}}}}