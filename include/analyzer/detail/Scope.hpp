#ifndef ICE_SCRIPT_ANALYZER_SCOPE_HPP
#define ICE_SCRIPT_ANALYZER_SCOPE_HPP

#include <string>
#include <memory>
#include <vector>

#include "symbol/SymbolTable.hpp"

#include "detail/Assert.hpp"

#include "exceptions/RuntimeException.hpp"

namespace ice_script { namespace analyzer { namespace detail {

enum class ScopeType
{
    UNKNOWN,
    GLOBAL,
    CLASS,
    FUNCTION
};

class Scope
{
public:
    Scope(Scope* parent = nullptr) : parent_(parent), symbolTable_(std::make_unique<SymbolTable>((parent ? &parent->symbolTable() : nullptr)))
    {
        type_ = parent ? parent->type() : ScopeType::GLOBAL;

        expectedTypes_.push_back(std::make_unique<std::vector<std::shared_ptr<Type>>>());
    }

//    Scope(TypeTable& typeTable, Scope* parent = nullptr) : parent_(parent), typeTable_(&typeTable)
//    {
//
//    }

    Scope* parent()
    {
        return parent_;
    }

    const Scope* parent() const
    {
        return parent_;
    }

    const std::string& name() const
    {
        return name_;
    }

    void setName(std::string name)
    {
        name_ = std::move(name);
    }
    
    std::string fullyQualifiedName() const
    {
        const std::string part = parent_ ? parent_->fullyQualifiedName() : "::";
        
        if (type_ == ScopeType::FUNCTION) return part;
        
        return part + name_;
    }

    ScopeType type() const
    {
        return type_;
    }

    void setType(const ScopeType type)
    {
        type_ = type;
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

    SymbolTable& symbolTable()
    {
        return *symbolTable_;
    }

    const SymbolTable& symbolTable() const
    {
        return *symbolTable_;
    }

//    TypeTable& typeTable()
//    {
//        return &typeTable_;
//    }

    const std::shared_ptr<Symbol>& valueSymbol() const
    {
        return valueSymbol_;
    }

    void setValueSymbol(std::shared_ptr<Symbol> valueSymbol)
    {
        valueSymbol_ = std::move(valueSymbol);
    }

    const std::shared_ptr<Type>& valueType() const
    {
        return valueType_;
    }

    void setValueType(std::shared_ptr<Type> valueType)
    {
        valueType_ = std::move(valueType);
    }

    void pushExpectedTypes(std::vector<std::shared_ptr<Type>> expectedTypes)
    {
        expectedTypes_.push_back(std::make_unique<std::vector<std::shared_ptr<Type>>>(std::move(expectedTypes)));
    }

    void popExpectedTypes()
    {
        if (expectedTypes_.size() == 1) throw RuntimeException("");

        expectedTypes_.pop_back();
    }

    const std::vector<std::shared_ptr<Type>>& expectedTypes() const
    {
        ICE_SCRIPT_ASSERT(!expectedTypes_.empty());

        return *expectedTypes_.back();
    }

private:
    Scope* parent_;
    std::string name_;
    ScopeType type_;
    std::vector<std::unique_ptr<Scope>> children_;
//    TypeTable* typeTable_;
    std::unique_ptr<SymbolTable> symbolTable_;
    std::shared_ptr<Symbol> valueSymbol_{};
    std::shared_ptr<Type> valueType_{};
    std::vector<std::unique_ptr<std::vector<std::shared_ptr<Type>>>> expectedTypes_{};

};

}}}

#endif //ICE_SCRIPT_ANALYZER_SCOPE_HPP
