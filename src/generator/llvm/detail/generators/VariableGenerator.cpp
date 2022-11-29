#include "generator/llvm/detail/generators/VariableGenerator.hpp"

#include "generator/llvm/detail/visitors/VariableVisitor.hpp"

#include "generator/llvm/detail/LlvmUtilities.hpp"
#include "llvm/IR/GlobalVariable.h"
#include <memory>

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ::llvm;
using namespace ice_script::asg;

::llvm::Value* createAllocation(Context& context, Llvm& llvm, const std::shared_ptr<Symbol>& symbol)
{
    auto llvmType = toLlvmType(context, llvm, *symbol->type());
    
    // ;   %array = alloca i8*, align 1
    auto alloca = llvm.builder().CreateAlloca(llvmType, 0, symbol->name());
    
    if (symbol->type()->typeId() == Type::TypeId::ARRAY)
    {
        const auto& arrayType = std::dynamic_pointer_cast<ArrayType>(symbol->type());
        
        ICE_SCRIPT_ASSERT(arrayType);
        
        const auto& optionalDimension = arrayType->dimensions()[0];
        
        const auto length = (optionalDimension ? optionalDimension.get() : 0) * 4;//arraySymbol->type()->type();
        
        auto size = ::llvm::ConstantInt::get(llvm.context(), ::llvm::APInt(64, length + 8, true));
        
        // ;   %arrayMem = alloca i8, i64 12, align 1
        auto allocaStorage = llvm.builder().CreateAlloca(llvmType->getPointerElementType(), size);
        
        // ;   store i8* %arrayMem, i8** %array, align 1
        llvm.builder().CreateStore(allocaStorage, alloca);
    }
    
    return alloca;
}

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Variable& variable)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(variable).name())

    Scope& scope = context.scope();
    
    auto llvmValue = context.llvmSymbolTable().findByKey(variable.symbol->key());
    
    if (llvmValue)
    {
        // scope.add(variable.name, *llvmValue);
    }
    else
    {
        auto type = toLlvmType(context, llvm, *variable.symbol->type());
        auto allocation = createAllocation(context, llvm, variable.symbol);
        // auto alloca = llvm.builder().CreateAlloca(type, 0, variable.name);
        // auto alloca = llvm.builder().CreateAlloca(type, 0, variable.name);
        
        scope.add(variable.name, *allocation);
        
        llvmValue = allocation;
    }

    scope.set(llvmValue);

    VariableVisitor visitor{context, llvm};
    auto value = boost::apply_visitor(visitor, variable.value);

    Value* v = boost::get<Value*>(value);
    
    auto lhs = llvmValue;
    
    while (lhs->getType()->isPointerTy() && lhs->getType()->getNumContainedTypes() >= 1 && lhs->getType()->getContainedType(0)->isPointerTy() && !v->getType()->isPointerTy())
    {
        lhs = llvm.builder().CreateLoad(lhs);
    }

    if (value.type() == typeid(Value*))
    {
        if (lhs->getType()->isPointerTy() && v->getType()->isPointerTy())
        {
            auto _v = v;
            if (_v->getType()->getPointerElementType()->isPointerTy())
            {
                _v = llvm.builder().CreateLoad(_v);
            }
            else if (!lhs->getType()->getPointerElementType()->isPointerTy())
            {
                _v = llvm.builder().CreateLoad(_v);
            }
            
            llvm.builder().CreateStore(_v, lhs);
        }
        else
        if (isa<AllocaInst>(v))
        {
            AllocaInst* a = dyn_cast<AllocaInst>(v);
            auto loadInstruction = llvm.builder().CreateLoad(a);
            llvm.builder().CreateStore(loadInstruction, lhs);
        }
        else if (::llvm::isa<::llvm::GetElementPtrInst>(v))
        {
            ::llvm::GetElementPtrInst* getElementPtrInst = ::llvm::dyn_cast<::llvm::GetElementPtrInst>(v);
            auto loadInstruction = llvm.builder().CreateLoad(getElementPtrInst);
            llvm.builder().CreateStore(loadInstruction, lhs);
        }
        else if (isa<ConstantInt>(v))
        {
            if (isa<GlobalVariable>(llvmValue))
            {
                auto g = dyn_cast<GlobalVariable>(llvmValue);
                g->setInitializer(dyn_cast<ConstantInt>(v));
            }
            else
            {
                llvm.builder().CreateStore(v, lhs);
            }
        }
        else if (v->getType()->isVoidTy())
        {
            
        }
        else
        {
            llvm.builder().CreateStore(v, lhs);
        }
    }
    else// if (value.type() == typeid(monostate))
    {
        std::cout << "OOF" << std::endl;
    }
    
    scope.set(static_cast<Value*>(nullptr));

    return nullptr;
}

}}}}