#ifndef ICE_SCRIPT_GENERATOR_CONTEXT_HPP
#define ICE_SCRIPT_GENERATOR_CONTEXT_HPP

#include <memory>
#include <vector>

#include "generator/llvm/Scope.hpp"

namespace ice_script { namespace generator { namespace llvm {

class Context
{
public:
    Context() : rootScope_(std::make_unique<Scope>()), currentScope_(rootScope_.get())
    {

    }

    Scope& scope()
    {
        return *currentScope_;
    }

    Scope& pushScope()
    {
        currentScope_ = &currentScope_->createChild();

        scopes_.push_back(currentScope_);

        return *currentScope_;
    }

    Scope& popScope()
    {
        currentScope_ = currentScope_->parent();

        return *currentScope_;
    }

private:
    std::unique_ptr<Scope> rootScope_;
    std::vector<Scope*> scopes_;
    Scope* currentScope_ = nullptr;
};

}}}

#endif //ICE_SCRIPT_GENERATOR_CONTEXT_HPP
