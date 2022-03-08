#ifndef ICE_SCRIPT_ANALYZER_CONTEXT_HPP
#define ICE_SCRIPT_ANALYZER_CONTEXT_HPP

#include <string>
#include <memory>

#include "analyzer/Symbol.hpp"
#include "analyzer/SymbolTable.hpp"
#include "analyzer/TypeTable.hpp"
#include "analyzer/Scope.hpp"

#include "analyzer/AnalyzerUtilities.hpp"

#include "exceptions/TypeNotFoundException.hpp"
#include "exceptions/DuplicateTypeException.hpp"

namespace ice_script { namespace analyzer {

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

    TypeTable& typeTable()
    {
        return typeTable_;
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
    TypeTable typeTable_;
};

}}

#endif //ICE_SCRIPT_ANALYZER_CONTEXT_HPP
