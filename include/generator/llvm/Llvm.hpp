#ifndef ICE_SCRIPT_GENERATOR_LLVM_HPP
#define ICE_SCRIPT_GENERATOR_LLVM_HPP

#include <string>
#include <memory>

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

namespace ice_script { namespace generator { namespace llvm {

class Llvm
{
public:
    Llvm()
    :
            context_(std::make_unique<::llvm::LLVMContext>()),
            module_(std::make_unique<::llvm::Module>("my cool jit", *context_)),
            builder_(std::make_unique<::llvm::IRBuilder<>>(*context_))
    {

    }

    ::llvm::LLVMContext& context()
    {
        return *context_;
    }

    ::llvm::Module& module()
    {
        return *module_;
    }

    ::llvm::IRBuilder<>& builder()
    {
        return *builder_;
    }

private:
    std::unique_ptr<::llvm::LLVMContext> context_;
    std::unique_ptr<::llvm::Module> module_;
    std::unique_ptr<::llvm::IRBuilder<>> builder_;
};

}}}

#endif //ICE_SCRIPT_GENERATOR_LLVM_HPP
