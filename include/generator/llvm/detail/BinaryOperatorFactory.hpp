#ifndef ICE_SCRIPT_BINARYOPERATORFACTORY_HPP
#define ICE_SCRIPT_BINARYOPERATORFACTORY_HPP

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "exceptions/RuntimeException.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

class BinaryOperatorFactory
{
public:
    BinaryOperatorFactory(logger::ILogger& logger, Context& context, Llvm& llvm) : logger_(&logger), context_(&context), llvm_(&llvm)
    {

    }

    ::llvm::Value* create(::llvm::Value* lhs, ::llvm::Value* rhs)
    {
        if (::llvm::isa<::llvm::AllocaInst>(lhs))
        {
            ::llvm::AllocaInst* allocaInst = ::llvm::dyn_cast<::llvm::AllocaInst>(lhs);
//            auto loadInstruction = llvm_->builder().CreateLoad(allocaInst);
            lhs = llvm_->builder().CreateLoad(allocaInst);
        }

        if (::llvm::isa<::llvm::AllocaInst>(rhs))
        {
            ::llvm::AllocaInst* allocaInst = ::llvm::dyn_cast<::llvm::AllocaInst>(rhs);
//            auto loadInstruction = llvm_->builder().CreateLoad(allocaInst);
            rhs = llvm_->builder().CreateLoad(allocaInst);
        }

//        return llvm_->builder().CreateAdd(lhs, rhs, "addtmp");

        if (lhs->getType()->isIntegerTy()) return llvm_->builder().CreateAdd(lhs, rhs);
        if (lhs->getType()->isFloatTy()) return llvm_->builder().CreateFAdd(lhs, rhs);
        if (lhs->getType()->isDoubleTy()) return llvm_->builder().CreateFAdd(lhs, rhs);

        throw RuntimeException("");
    }
private:
    logger::ILogger* logger_;
    Context* context_;
    Llvm* llvm_;
};

}}}}

#endif //ICE_SCRIPT_BINARYOPERATORFACTORY_HPP
