#ifndef ICE_SCRIPT_GENERATOR_SCOPE_HPP
#define ICE_SCRIPT_GENERATOR_SCOPE_HPP

#include <string>
#include <vector>
#include <unordered_map>

#include <llvm/ADT/APFloat.h>
#include <llvm/ADT/STLExtras.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>

#include "detail/Format.hpp"
#include "exceptions/DuplicateFunctionException.hpp"
#include "exceptions/DuplicateArgumentException.hpp"
#include "exceptions/DuplicateAllocaInstException.hpp"
#include "exceptions/AllocaInstNotFoundException.hpp"
#include "exceptions/DuplicateBasicBlockException.hpp"

namespace ice_script { namespace generator { namespace llvm {

class Scope
{
public:
    Scope(Scope* parent = nullptr) : parent_(parent)
    {

    }

    Scope* parent()
    {
        return parent_;
    }

    Scope& createChild()
    {
        children_.push_back(std::make_unique<Scope>(this));

        return *children_.back();
    }

    std::vector<Scope*> children()
    {
        std::vector<Scope*> children{};

        for (const auto& child : children_)
        {
            children.push_back(child.get());
        }

        return children;
    }

    void add(const std::string& name, ::llvm::Function& function)
    {
        const auto it = functions_.find(name);
        if (it != functions_.end())
        {
            throw DuplicateFunctionException(detail::format("Function '%s' already exists", name));
        }

        functions_[name] = &function;
    }

    void add(const std::string& name, ::llvm::Argument& argument)
    {
        const auto it = arguments_.find(name);
        if (it != arguments_.end())
        {
            throw DuplicateArgumentException(detail::format("Argument '%s' already exists", name));
        }

        arguments_[name] = &argument;
    }

    void add(const std::string& name, ::llvm::AllocaInst& allocaInst)
    {
        const auto it = allocaInsts_.find(name);
        if (it != allocaInsts_.end())
        {
            throw DuplicateAllocaInstException(detail::format("AllocaInst '%s' already exists", name));
        }

        allocaInsts_[name] = &allocaInst;
    }

    ::llvm::AllocaInst& getAllocaInst(const std::string& name)
    {
        const auto it = allocaInsts_.find(name);
        if (it == allocaInsts_.end())
        {
            throw AllocaInstNotFoundException(detail::format("AllocaInst '%s' not found", name));
        }

        return *it->second;
    }

    void add(const std::string& name, ::llvm::BasicBlock& basicBlock)
    {
        const auto it = basicBlocks_.find(name);
        if (it != basicBlocks_.end())
        {
            throw DuplicateBasicBlockException(detail::format("BasicBlock '%s' already exists", name));
        }

        basicBlocks_[name] = &basicBlock;
    }

    void set(::llvm::Value* value)
    {
        value_ = value;
    }

    void set(::llvm::Function* function)
    {
        function_ = function;
    }

    void set(::llvm::BasicBlock* basicBlock)
    {
        basicBlock_ = basicBlock;
    }

    ::llvm::Value* value()
    {
        return value_;
    }

    ::llvm::Function* function()
    {
        return function_;
    }

    ::llvm::BasicBlock* basicBlock()
    {
        return basicBlock_;
    }

private:
    Scope* parent_;
    std::vector<std::unique_ptr<Scope>> children_;
    ::llvm::Value* value_ = nullptr;
    ::llvm::Function* function_ = nullptr;
    ::llvm::BasicBlock* basicBlock_ = nullptr;
    std::unordered_map<std::string, ::llvm::Function*> functions_;
    std::unordered_map<std::string, ::llvm::Argument*> arguments_;
    std::unordered_map<std::string, ::llvm::AllocaInst*> allocaInsts_;
    std::unordered_map<std::string, ::llvm::BasicBlock*> basicBlocks_;
};

}}}

#endif //ICE_SCRIPT_GENERATOR_SCOPE_HPP
