#include "generator/llvm/detail/generators/ConstructcallGenerator.hpp"

#include "generator/llvm/detail/generators/ArglistGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Constructcall& constructcall)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(constructcall).name())

    Scope& scope = context.scope();

    auto value = scope.value();

    auto& function = context.llvmSymbolTable().getFunctionByKey(constructcall.symbol->key());

    std::vector<::llvm::Value*> arguments = process(context, llvm, constructcall.arglist.get());
    
    if (value) arguments.insert(arguments.begin(), value);
    
    return llvm.builder().CreateCall(&function, arguments);
}

}}}}