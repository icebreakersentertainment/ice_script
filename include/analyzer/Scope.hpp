#ifndef ICE_SCRIPT_ANALYZER_SCOPE_HPP
#define ICE_SCRIPT_ANALYZER_SCOPE_HPP

#include <string>
#include <memory>
#include <vector>

#include "analyzer/SymbolTable.hpp"

#include "exceptions/RuntimeException.hpp"

namespace ice_script { namespace analyzer {

enum class ScopeType
{
    GLOBAL,
    CLASS,
    FUNCTION
};

class Scope
{
public:
    Scope(Scope* parent = nullptr) : parent_(parent), symbolTable_(std::make_unique<SymbolTable>())
    {
        type_ = parent ? parent->type() : ScopeType::GLOBAL;
    }

//    Scope(TypeTable& typeTable, Scope* parent = nullptr) : parent_(parent), typeTable_(&typeTable)
//    {
//
//    }

    Scope* parent()
    {
        return parent_;
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

//    TypeTable& typeTable()
//    {
//        return &typeTable_;
//    }

    void pushExpectedTypes(std::vector<std::shared_ptr<asg::Type>> expectedTypes)
    {
        expectedTypes_.push_back(std::move(expectedTypes));
    }

    void popExpectedTypes()
    {
        if (expectedTypes_.size() == 1) throw RuntimeException("");

        expectedTypes_.pop_back();
    }

    const std::vector<std::shared_ptr<asg::Type>>& expectedTypes() const
    {
        return expectedTypes_.back();
    }

private:
    Scope* parent_;
    ScopeType type_;
    std::vector<std::unique_ptr<Scope>> children_;
//    TypeTable* typeTable_;
    std::unique_ptr<SymbolTable> symbolTable_;
    std::vector<std::vector<std::shared_ptr<asg::Type>>> expectedTypes_ = {{}};

};

}}

#endif //ICE_SCRIPT_ANALYZER_SCOPE_HPP
