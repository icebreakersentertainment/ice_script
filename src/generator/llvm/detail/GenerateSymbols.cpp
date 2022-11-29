#include <memory>
#include <string>

#include <llvm/IR/DerivedTypes.h>

#include "generator/llvm/detail/GenerateSymbols.hpp"

#include "asg/Asg.hpp"

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "type/Type.hpp"
#include "type/TypeQualifier.hpp"
#include "symbol/OperatorSymbol.hpp"
#include "symbol/ArraySymbol.hpp"

#include "detail/Format.hpp"
#include "detail/Assert.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using ice_script::detail::format;

std::string mangle(const std::shared_ptr<Type>& type)
{
    return type->name();
}

std::string mangle(const std::shared_ptr<OperatorSymbol>& operatorSymbol)
{
    const std::string templateString = "%s operator%s(%s)%s";
    
    const bool constant = operatorSymbol->type()->qualifiers() & TypeQualifier::CONSTANT;    
    const auto mangledReturnTypeName = mangle(operatorSymbol->ownerSymbol()->type());
    const auto mangledParameterTypeName = mangle(operatorSymbol->type()->returnType());
    
    std::string operatorTypeSymbol;
    
    switch (operatorSymbol->type()->operatorTypeId())
    {
        case OperatorTypeId::UNKNOWN:
        case OperatorTypeId::VOID_T:
            throw InvalidArgumentException("Operator type id not valid.");
        
        // Prefixed Unary Operators
        case OperatorTypeId::PREFIX_NEGATE: operatorTypeSymbol = "-"; break;
        case OperatorTypeId::PREFIX_COMPLIMENT: operatorTypeSymbol = "~"; break;
        case OperatorTypeId::PREFIX_INCREMENT: operatorTypeSymbol = "++"; break;
        case OperatorTypeId::PREFIX_DECREMENT: operatorTypeSymbol = "--"; break;
        
        // Postfix Unary Operators
        case OperatorTypeId::POSTFIX_INCREMENT: operatorTypeSymbol = "++"; break;
        case OperatorTypeId::POSTFIX_DECREMENT: operatorTypeSymbol = "--"; break;
        
        // Comparison Operators
        case OperatorTypeId::EQUALS: operatorTypeSymbol = "="; break;
        case OperatorTypeId::NOT_EQUALS: operatorTypeSymbol = "!="; break;
        case OperatorTypeId::LESS_THAN: operatorTypeSymbol = "<"; break;
        case OperatorTypeId::LESS_THAN_OR_EQUALS: operatorTypeSymbol = "<="; break;
        case OperatorTypeId::GREATER_THAN: operatorTypeSymbol = ">"; break;
        case OperatorTypeId::GREATER_THAN_OR_EQUALS: operatorTypeSymbol = ">="; break;
        // TODO: Do we want to implement these?
        // case OperatorTypeId::IS: return "IS";
        // case OperatorTypeId::IS_NOT: return "IS_NOT";

        // Assignment Operators
        case OperatorTypeId::ASSIGN_EQUAL: operatorTypeSymbol = "="; break;
        case OperatorTypeId::ASSIGN_ADD: operatorTypeSymbol = "=+"; break;
        case OperatorTypeId::ASSIGN_SUBTRACT: operatorTypeSymbol = "=-"; break;
        case OperatorTypeId::ASSIGN_MULTIPLY: operatorTypeSymbol = "=*"; break;
        case OperatorTypeId::ASSIGN_DIVIDE: operatorTypeSymbol = "=/"; break;
        case OperatorTypeId::ASSIGN_MODULOS: operatorTypeSymbol = "=%"; break;
        case OperatorTypeId::ASSIGN_EXPONENT: operatorTypeSymbol = "=**"; break;
        case OperatorTypeId::ASSIGN_AND: operatorTypeSymbol = "=&"; break;
        case OperatorTypeId::ASSIGN_OR: operatorTypeSymbol = "=|"; break;
        case OperatorTypeId::ASSIGN_XOR: operatorTypeSymbol = "=^"; break;
        case OperatorTypeId::ASSIGN_LEFT_SHIFT: operatorTypeSymbol = "=<<"; break;
        case OperatorTypeId::ASSIGN_RIGHT_SHIFT: operatorTypeSymbol = "=>>"; break;
        case OperatorTypeId::ASSIGN_ARITHMETIC_RIGHT_SHIFT: operatorTypeSymbol = "=>>>"; break;

        // Bitwise Operators
        // TODO: Do we need this here?
        // case OperatorTypeId::BITWISE_COMPLEMENT: operatorTypeSymbol = "~"; break;
        case OperatorTypeId::BITWISE_AND: operatorTypeSymbol = "&"; break;
        case OperatorTypeId::BITWISE_OR: operatorTypeSymbol = "|"; break;
        case OperatorTypeId::BITWISE_XOR: operatorTypeSymbol = "^"; break;
        case OperatorTypeId::BITWISE_LEFT_SHIFT: operatorTypeSymbol = "<<"; break;
        case OperatorTypeId::BITWISE_RIGHT_SHIFT: operatorTypeSymbol = ">>"; break;
        case OperatorTypeId::BITWISE_ARITHMETIC_RIGHT_SHIFT: operatorTypeSymbol = ">>>"; break;

        // Math Operators
        // TODO: Do we need these here?
        case OperatorTypeId::ADD: operatorTypeSymbol = "+"; break;
        case OperatorTypeId::SUBTRACT: operatorTypeSymbol = "-"; break;
        case OperatorTypeId::MULTIPLY: operatorTypeSymbol = "*"; break;
        case OperatorTypeId::DIVIDE: operatorTypeSymbol = "/"; break;
        case OperatorTypeId::MODULOS: operatorTypeSymbol = "%"; break;
        case OperatorTypeId::EXPONENT: operatorTypeSymbol = "**"; break;

        // Logic Operators
        case OperatorTypeId::AND: operatorTypeSymbol = "&&"; break;
        case OperatorTypeId::OR: operatorTypeSymbol = "||"; break;
        case OperatorTypeId::XOR: operatorTypeSymbol = "^^"; break;
        case OperatorTypeId::NOT: operatorTypeSymbol = "!"; break;
        
        // Index operators
        case OperatorTypeId::INDEX: operatorTypeSymbol = "[]"; break;
        
        // Functor operator
        case OperatorTypeId::CALL: operatorTypeSymbol = "()"; break;
        
        // Type conversion operators
        case OperatorTypeId::EXPLICIT_CONVERSION: operatorTypeSymbol = ""; break;
        case OperatorTypeId::IMPLICIT_CONVERSION: operatorTypeSymbol = ""; break;

        default:
            throw InvalidArgumentException("Operator type id not valid.");
    }
    
    return format(templateString, mangledReturnTypeName, operatorTypeSymbol, mangledParameterTypeName, constant ? " const" : "");
}

std::string mangle(const std::shared_ptr<FunctionSymbol>& functionSymbol)
{
    return functionSymbol->name();
}

std::string mangle(const std::shared_ptr<ClassSymbol>& classSymbol)
{
    return classSymbol->name();
}

std::string mangle(const std::shared_ptr<ArraySymbol>& arraySymbol)
{
    return arraySymbol->name();
}

std::string mangle(const std::shared_ptr<Symbol>& symbol)
{
    return symbol->name();
}

void generateSymbols(Context& context, Llvm& llvm)
{
    LOG_DEBUG((&context.logger()), "Generating symbols for llvm")

    // const auto& functions = context.typeTable().getAllFunctions();
    const auto functionSymbols = context.symbolTable().getAllFunctions();

    for (const auto& functionSymbol : functionSymbols)
    {
        if (functionSymbol->type()->isConstructor() || functionSymbol->type()->isMethod()) continue;
        
        auto llvmFunction = context.llvmSymbolTable().findFunctionByKey(functionSymbol->key());

        if (llvmFunction) continue;

        auto llvmFunctionType = &context.llvmTypeTable().getFunctionByKey(functionSymbol->type()->key());

        llvmFunction = ::llvm::Function::Create(llvmFunctionType, ::llvm::Function::ExternalLinkage, mangle(functionSymbol), &llvm.module());
        
        ICE_SCRIPT_ASSERT(llvmFunction->arg_size() == functionSymbol->parameters().size());
        
        for (size_t i=0; i < llvmFunction->arg_size(); ++i)
        {
            auto argument = llvmFunction->getArg(i);
            
            const auto& parameter = functionSymbol->parameters()[i];
            
            argument->setName(parameter->name());
        }

        // context.llvmTypeTable().add(*function->type(), functionType);
        context.llvmSymbolTable().add(*functionSymbol, llvmFunction);

//        ::llvm::FunctionCallee functionCallee = llvm.module().getOrInsertFunction(function->name(), functionType);
//        functionCallee.getCallee()
    }

    // {
    //     const auto& classes = context.typeTable().getAllClasses();
        
    //     for (const auto& classType : classes)
    //     {
    //         auto llvmType = context.llvmTypeTable().findClassByKey(classType->key());
            
    //         if (llvmType) continue;
            
    //         if (classType->modifier() == TypeModifier::VALUE)
    //         {
    //             auto structType = createValueClassType(context, llvm, classType);
                
    //             context.llvmTypeTable().add(classType, structType);
    //         }
    //         else if (classType->modifier() == TypeModifier::REFERENCE)
    //         {
    //             auto referenceType = createReferenceType(context, llvm, classType);
                
    //             context.llvmTypeTable().add(classType, referenceType);
    //         }
    //         else if (classType->modifier() == TypeModifier::POINTER)
    //         {
    //             auto pointerType = createPointerType(context, llvm, classType);
                
    //             context.llvmTypeTable().add(classType, pointerType);
    //         }
    //     }
    // }
    
    const auto& classSymbols = context.symbolTable().getAllClasses();

    for (const auto& classSymbol : classSymbols)
    {
        auto llvmStruct = context.llvmTypeTable().findClassByKey(classSymbol->type()->key());
        
        ICE_SCRIPT_ASSERT(llvmStruct)

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

        for (const auto& constructorSymbol : classSymbol->constructors())
        {
            // auto llvmFunction = context.llvmTypeTable().findFunctionByKey(constructor->key());
            auto llvmFunction = context.llvmSymbolTable().findFunctionByKey(constructorSymbol->key());

            ICE_SCRIPT_ASSERT(!llvmFunction)

            // std::vector<std::shared_ptr<Type>> parameters{};
            
            // auto classPointerType = context.typeTable().find(classSymbol->type(), classSymbol->type()->qualifiers(), TypeModifier::POINTER);
            
            // ICE_SCRIPT_ASSERT(classPointerType)

            // parameters.push_back(classPointerType);

            // for (const auto& parameter : constructorSymbol->parameters()) parameters.push_back(parameter->type());

            // auto parameterList = createParameterTypeList(context, llvm, parameters);
            // // auto returnType = toLlvmType(context, llvm, constructor->type()->returnType());
            // auto returnType = toLlvmType(context, llvm, context.typeTable().get(Type::TypeId::VOID_T)[0]);

            auto llvmFunctionType = &context.llvmTypeTable().getFunctionByKey(constructorSymbol->type()->key());

            llvmFunction = ::llvm::Function::Create(llvmFunctionType, ::llvm::Function::ExternalLinkage, mangle(constructorSymbol), &llvm.module());
            
            // The first parameter is "this"
            llvmFunction->args().begin()->setName("this");
            
            ICE_SCRIPT_ASSERT(llvmFunction->arg_size() == constructorSymbol->parameters().size() + 1);
            
            for (size_t i=1; i < llvmFunction->arg_size(); ++i)
            {
                auto argument = llvmFunction->getArg(i);
                
                const auto& parameter = constructorSymbol->parameters()[i - 1];
                
                argument->setName(parameter->name());
            }
            
            context.llvmSymbolTable().add(*constructorSymbol, llvmFunction);

    //        ::llvm::FunctionCallee functionCallee = llvm.module().getOrInsertFunction(function->name(), functionType);
    //        functionCallee.getCallee()
        }
        
        for (const auto& functionSymbol : classSymbol->functions())
        {
            // auto llvmFunction = context.llvmTypeTable().findFunctionByKey(constructor->key());
            auto llvmFunction = context.llvmSymbolTable().findFunctionByKey(functionSymbol->key());

            ICE_SCRIPT_ASSERT(!llvmFunction)

            // std::vector<std::shared_ptr<Type>> parameters{};
            
            // auto classPointerType = context.typeTable().find(classSymbol->type(), classSymbol->type()->qualifiers(), TypeModifier::POINTER);
            
            // ICE_SCRIPT_ASSERT(classPointerType)

            // parameters.push_back(classPointerType);

            // for (const auto& parameter : functionSymbol->parameters()) parameters.push_back(parameter->type());

            // auto parameterList = createParameterTypeList(context, llvm, parameters);
            // auto returnType = toLlvmType(context, llvm, functionSymbol->type()->returnType());
            // auto returnType = toLlvmType(context, llvm, context.typeTable().get(Type::TypeId::VOID_T)[0]);

            auto functionType = &context.llvmTypeTable().getFunctionByKey(functionSymbol->type()->key());

            llvmFunction = ::llvm::Function::Create(functionType, ::llvm::Function::ExternalLinkage, mangle(functionSymbol), &llvm.module());
            
            // The first parameter is "this"
            llvmFunction->args().begin()->setName("this");
            
            ICE_SCRIPT_ASSERT(llvmFunction->arg_size() == functionSymbol->parameters().size() + 1);
            
            for (size_t i=1; i < llvmFunction->arg_size(); ++i)
            {
                auto argument = llvmFunction->getArg(i);
                
                const auto& parameter = functionSymbol->parameters()[i - 1];
                
                argument->setName(parameter->name());
            }
            
            context.llvmSymbolTable().add(*functionSymbol, llvmFunction);

    //        ::llvm::FunctionCallee functionCallee = llvm.module().getOrInsertFunction(function->name(), functionType);
    //        functionCallee.getCallee()
        }

//        context.llvmTypeTable().add(*_class, llvmStruct);

//        ::llvm::FunctionCallee functionCallee = llvm.module().getOrInsertFunction(function->name(), functionType);
//        functionCallee.getCallee()
    }
    
    const auto symbols = context.symbolTable().getAll();
    
    for (const auto& symbol : symbols)
    {
        if (!symbol->global()) continue;
        
        auto llvmGlobal = context.llvmSymbolTable().findByKey(symbol->key());
        
        if (llvmGlobal) continue;
        
        // auto llvmType = toLlvmType(context, llvm, symbol->type());
        auto llvmType = &context.llvmTypeTable().getByKey(symbol->type()->key());
        
        llvmGlobal = llvm.module().getOrInsertGlobal(symbol->name(), llvmType);
        
        context.llvmSymbolTable().add(*symbol, llvmGlobal);
    }
    
    // {
    //     const auto& arrays = context.typeTable().getAllArrays();
        
    //     for (const auto& arrayType : arrays)
    //     {
    //         auto llvmType = context.llvmTypeTable().findArrayByKey(arrayType->key());
            
    //         if (llvmType) continue;
            
    //         switch (arrayType->modifier())
    //         {
    //             case TypeModifier::VALUE:
    //                 context.llvmTypeTable().add(arrayType, createValueArrayType(context, llvm, arrayType));
    //                 break;
                    
    //             case TypeModifier::REFERENCE:
    //                 context.llvmTypeTable().add(arrayType, createReferenceType(context, llvm, arrayType));
    //                 break;
                    
    //             case TypeModifier::POINTER:
    //                 context.llvmTypeTable().add(arrayType, createPointerType(context, llvm, arrayType));
    //                 break;
                    
    //             default:
    //                 throw RuntimeException("");
    //         }
    //     }
    // }
    
    const auto& arraySymbols = context.symbolTable().getAllArrays();

    for (const auto& arraySymbol : arraySymbols)
    {
        auto llvmPointer = context.llvmTypeTable().findArrayByKey(arraySymbol->type()->key());
        
        ICE_SCRIPT_ASSERT(llvmPointer)

        for (const auto& constructorSymbol : arraySymbol->constructors())
        {
            // auto llvmFunction = context.llvmTypeTable().findFunctionByKey(constructor->key());
            auto llvmFunction = context.llvmSymbolTable().findFunctionByKey(constructorSymbol->key());

            ICE_SCRIPT_ASSERT(!llvmFunction)

            // std::vector<std::shared_ptr<Type>> parameters{};
            
            // auto arrayPointerType = context.typeTable().find(arraySymbol->type(), arraySymbol->type()->qualifiers(), TypeModifier::POINTER);
            
            // ICE_SCRIPT_ASSERT(arrayPointerType)

            // parameters.push_back(arrayPointerType);

            // for (const auto& parameter : constructorSymbol->parameters()) parameters.push_back(parameter->type());

            // auto parameterList = createParameterTypeList(context, llvm, parameters);
            // // auto returnType = toLlvmType(context, llvm, constructor->type()->returnType());
            // auto returnType = toLlvmType(context, llvm, context.typeTable().get(Type::TypeId::VOID_T)[0]);

            auto llvmFunctionType = &context.llvmTypeTable().getFunctionByKey(constructorSymbol->type()->key());

            llvmFunction = ::llvm::Function::Create(llvmFunctionType, ::llvm::Function::ExternalLinkage, mangle(constructorSymbol), &llvm.module());
            
            // The first parameter is "this"
            llvmFunction->args().begin()->setName("this");
            
            ICE_SCRIPT_ASSERT(llvmFunction->arg_size() == constructorSymbol->parameters().size() + 1);
            
            for (size_t i=1; i < llvmFunction->arg_size(); ++i)
            {
                auto argument = llvmFunction->getArg(i);
                
                const auto& parameter = constructorSymbol->parameters()[i - 1];
                
                argument->setName(parameter->name());
            }
            
            context.llvmSymbolTable().add(*constructorSymbol, llvmFunction);

    //        ::llvm::FunctionCallee functionCallee = llvm.module().getOrInsertFunction(function->name(), functionType);
    //        functionCallee.getCallee()
        }
        
        for (const auto& operatorSymbol : arraySymbol->operators())
        {
            // auto llvmFunction = context.llvmTypeTable().findFunctionByKey(constructor->key());
            auto llvmFunction = context.llvmSymbolTable().findFunctionByKey(operatorSymbol->key());

            ICE_SCRIPT_ASSERT(!llvmFunction)

            // std::vector<std::shared_ptr<Type>> parameters{};
            
            // auto arrayPointerType = context.typeTable().find(arraySymbol->type(), arraySymbol->type()->qualifiers(), TypeModifier::POINTER);
            
            // ICE_SCRIPT_ASSERT(arrayPointerType)

            // parameters.push_back(arrayPointerType);

            // for (const auto& parameter : functionSymbol->parameters()) parameters.push_back(parameter->type());

            // auto parameterList = createParameterTypeList(context, llvm, parameters);
            // auto returnType = toLlvmType(context, llvm, functionSymbol->type()->returnType());
            // // auto returnType = toLlvmType(context, llvm, context.typeTable().get(Type::TypeId::VOID_T)[0]);

            // ::llvm::FunctionType* functionType = ::llvm::FunctionType::get(returnType, parameterList, false);
            auto llvmFunctionType = &context.llvmTypeTable().getFunctionByKey(operatorSymbol->type()->key());

            llvmFunction = ::llvm::Function::Create(llvmFunctionType, ::llvm::Function::ExternalLinkage, mangle(operatorSymbol), &llvm.module());
            
            // The first parameter is "this"
            llvmFunction->args().begin()->setName("this");
            
            ICE_SCRIPT_ASSERT(llvmFunction->arg_size() == operatorSymbol->parameters().size() + 1);
            
            for (size_t i=1; i < llvmFunction->arg_size(); ++i)
            {
                auto argument = llvmFunction->getArg(i);
                
                const auto& parameter = operatorSymbol->parameters()[i - 1];
                
                argument->setName(parameter->name());
            }
            
            context.llvmSymbolTable().add(*operatorSymbol, llvmFunction);

    //        ::llvm::FunctionCallee functionCallee = llvm.module().getOrInsertFunction(function->name(), functionType);
    //        functionCallee.getCallee()
        }
        
        for (const auto& functionSymbol : arraySymbol->functions())
        {
            // auto llvmFunction = context.llvmTypeTable().findFunctionByKey(constructor->key());
            auto llvmFunction = context.llvmSymbolTable().findFunctionByKey(functionSymbol->key());

            ICE_SCRIPT_ASSERT(!llvmFunction)

            // std::vector<std::shared_ptr<Type>> parameters{};
            
            // auto arrayPointerType = context.typeTable().find(arraySymbol->type(), arraySymbol->type()->qualifiers(), TypeModifier::POINTER);
            
            // ICE_SCRIPT_ASSERT(arrayPointerType)

            // parameters.push_back(arrayPointerType);

            // for (const auto& parameter : functionSymbol->parameters()) parameters.push_back(parameter->type());

            // auto parameterList = createParameterTypeList(context, llvm, parameters);
            // auto returnType = toLlvmType(context, llvm, functionSymbol->type()->returnType());
            // // auto returnType = toLlvmType(context, llvm, context.typeTable().get(Type::TypeId::VOID_T)[0]);

            // ::llvm::FunctionType* functionType = ::llvm::FunctionType::get(returnType, parameterList, false);
            auto llvmFunctionType = &context.llvmTypeTable().getFunctionByKey(functionSymbol->type()->key());

            llvmFunction = ::llvm::Function::Create(llvmFunctionType, ::llvm::Function::ExternalLinkage, mangle(functionSymbol), &llvm.module());
            
            // The first parameter is "this"
            llvmFunction->args().begin()->setName("this");
            
            ICE_SCRIPT_ASSERT(llvmFunction->arg_size() == functionSymbol->parameters().size() + 1);
            
            for (size_t i=1; i < llvmFunction->arg_size(); ++i)
            {
                auto argument = llvmFunction->getArg(i);
                
                const auto& parameter = functionSymbol->parameters()[i - 1];
                
                argument->setName(parameter->name());
            }
            
            context.llvmSymbolTable().add(*functionSymbol, llvmFunction);

    //        ::llvm::FunctionCallee functionCallee = llvm.module().getOrInsertFunction(function->name(), functionType);
    //        functionCallee.getCallee()
        }

//        context.llvmTypeTable().add(*_class, llvmStruct);

//        ::llvm::FunctionCallee functionCallee = llvm.module().getOrInsertFunction(function->name(), functionType);
//        functionCallee.getCallee()
    }
}

}}}}