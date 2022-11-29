#include <memory>
#include <stdint.h>

#include "generator/llvm/detail/generators/VariableaccessGenerator.hpp"
#include "symbol/ClassSymbol.hpp"
#include "type/TypeModifier.hpp"

#include "detail/Assert.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Variableaccess& variableaccess)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(variableaccess).name())

    Scope& scope = context.scope();

    auto argument = scope.findArgument(variableaccess.symbol->name());

    if (argument) return argument;

    auto allocaInst = scope.findValue(variableaccess.symbol->name());
    
    if (allocaInst) return allocaInst;
    
    if (variableaccess.symbol->ownerSymbol())
    {
        if (variableaccess.symbol->ownerSymbol()->type()->typeId() == Type::TypeId::CLASS)
        {
            const auto ownerType = context.typeTable().find(variableaccess.symbol->ownerSymbol()->type(), variableaccess.type->qualifiers(), TypeModifier::VALUE);
            
            ICE_SCRIPT_ASSERT(ownerType);
            
            auto type = &context.llvmTypeTable().getClassByKey(ownerType->key());
            
            auto pointer = scope.value();
            
            if (!pointer) pointer = scope.findArgument("this");
            
            ICE_SCRIPT_ASSERT(pointer);
            
            const auto& classSymbol = std::dynamic_pointer_cast<ClassSymbol>(variableaccess.symbol->ownerSymbol());
            
            const auto it = std::find_if(classSymbol->memberVariables().begin(), classSymbol->memberVariables().end(), [&](const auto& memberVariable) {
                return memberVariable == variableaccess.symbol;
            });
            
            ICE_SCRIPT_ASSERT(it != classSymbol->memberVariables().end());

            const int32_t ordinal = it - classSymbol->memberVariables().begin();
            
            auto zero = ::llvm::ConstantInt::get(llvm.context(), ::llvm::APInt(64, 0, true));
            auto index = ::llvm::ConstantInt::get(llvm.context(), ::llvm::APInt(32, ordinal, true));
            
            auto basicBlock = scope.basicBlock();
            
            return ::llvm::GetElementPtrInst::Create(type, pointer, {zero, index}, "", basicBlock);
        }
    }
    
    return &scope.getValue(variableaccess.symbol->name());
}

}}}}