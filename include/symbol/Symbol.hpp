#ifndef ICE_SCRIPT_ANALYZER_SYMBOL_HPP
#define ICE_SCRIPT_ANALYZER_SYMBOL_HPP

#include <string>
#include <memory>

#include <boost/algorithm/string/predicate.hpp>

#include "type/Type.hpp"

#include "detail/ToStringUtils.hpp"

namespace ice_script
{

class Symbol
{
public:
    Symbol()
    {}

    Symbol(const std::string& name) : name_(name)
    {}

    virtual ~Symbol() = default;

    friend std::ostream& operator<<(std::ostream& os, const Symbol& symbol)
    {
        os << "(" << boost::typeindex::type_id<Symbol>().pretty_name() << ")["
        << "name: " << symbol.name_
        << ", type: " << symbol.type_
        << "]";

        return os;
    }

    friend std::string toString(const Symbol& symbol)
    {
        using namespace std::string_literals;

        return "(Symbol)[\n"s
            + "\tname: "s + symbol.name_
            + ",\n\ttype: " + detail::toString(symbol.type_)
            + "\n]";
    }

    const std::string& name() const
    {
        return name_;
    }

    void setName(std::string name)
    {
        name_ = std::move(name);
    }
    
    const std::string& fullyQualifiedScopeName() const
    {
        return fullyQualifiedScopeName_;
    }

    void setFullyQualifiedScopeName(std::string fullyQualifiedScopeName)
    {
        fullyQualifiedScopeName_ = std::move(fullyQualifiedScopeName);
    }
    
    virtual const std::string& key() const
    {
        // if (!key_.empty()) return key_;
        
        key_ = detail::format(
            "%s%s",
            fullyQualifiedScopeName_,
            boost::algorithm::ends_with(fullyQualifiedScopeName_, "::") ? name_ : "::" + name_
        );
        
        return key_;
        // return name_;
    }

    std::shared_ptr<Type> type()
    {
        return type_;
    }

    const std::shared_ptr<Type>& type() const
    {
        return type_;
    }

    void setType(std::shared_ptr<Type> type)
    {
        type_ = std::move(type);
    }
    
    const std::shared_ptr<Symbol>& ownerSymbol() const
    {
        return ownerSymbol_;
    }

    void setOwnerSymbol(std::shared_ptr<Symbol> ownerSymbol)
    {
        ownerSymbol_ = std::move(ownerSymbol);
    }
    
    void setGlobal(const bool global)
    {
        global_ = global;
    }
    
    bool global() const
    {
        return global_;
    }

protected:
    std::string name_;
    std::string fullyQualifiedScopeName_;
    mutable std::string key_;
    std::shared_ptr<Type> type_;
    std::shared_ptr<Symbol> ownerSymbol_;
    bool global_ = false;

};

}

#endif //ICE_SCRIPT_ANALYZER_SYMBOL_HPP
