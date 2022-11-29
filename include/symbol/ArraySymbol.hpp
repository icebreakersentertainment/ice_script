#ifndef ICE_SCRIPT_SYMBOL_ARRAYSYMBOL_HPP
#define ICE_SCRIPT_SYMBOL_ARRAYSYMBOL_HPP

#include <string>
#include <memory>

#include "symbol/Symbol.hpp"
#include "symbol/Symbols.hpp"
#include "symbol/FunctionSymbol.hpp"
#include "symbol/OperatorSymbols.hpp"
#include "symbol/FunctionSymbols.hpp"
#include "symbol/ConstructorSymbols.hpp"

#include "type/ArrayType.hpp"

namespace ice_script
{

inline std::string toArraySymbolKey(const std::string& fullyQualifiedScopeName, const std::string& name)
{
    return detail::format(
            "array_%s%s",
            fullyQualifiedScopeName,
            boost::algorithm::ends_with(fullyQualifiedScopeName, "::") ? name : "::" + name
        );
}

class ArraySymbol : public Symbol
{
public:
    using Symbol::Symbol;
    
    friend std::ostream& operator<<(std::ostream& os, const ArraySymbol& symbol)
    {
        os << "(" << boost::typeindex::type_id<ArraySymbol>().pretty_name() << ")["
        << "name: " << symbol.name_
        << ", type: " << symbol.type_
        << ", constructors: " << symbol.constructors_
        << "]";

        return os;
    }

    friend std::string toString(const ArraySymbol& symbol)
    {
        using namespace std::string_literals;

        return "(ArraySymbol)[\n"s
            + "\tname: "s + symbol.name_
            + ",\n\ttype: " + detail::toString(symbol.type_)
            + ",\n\tconstructors: " + toString(symbol.constructors_)
            + "\n]";
    }

    std::shared_ptr<ArrayType> type()
    {
        return type_;
    }

    const std::shared_ptr<ArrayType>& type() const
    {
        return type_;
    }

    void setType(std::shared_ptr<ArrayType> type)
    {
        Symbol::setType(type);
        type_ = std::move(type);
    }
    
    virtual const std::string& key() const
    {
        // if (!key_.empty()) return key_;
        
        // key_ = detail::format(
        //     "class_%s%s",
        //     fullyQualifiedScopeName_,
        //     boost::algorithm::ends_with(fullyQualifiedScopeName_, "::") ? name_ : "::" + name_
        // );
        
        key_ = toArraySymbolKey(fullyQualifiedScopeName_, name_);
        
        return key_;
        // return name_;
    }
    
    ConstructorSymbols& constructors()
    {
        return constructors_;
    }
    
    const ConstructorSymbols& constructors() const
    {
        return constructors_;
    }
    
    FunctionSymbols& functions()
    {
        return functions_;
    }
    
    const FunctionSymbols& functions() const
    {
        return functions_;
    }
    
    OperatorSymbols& operators()
    {
        return operators_;
    }
    
    const OperatorSymbols& operators() const
    {
        return operators_;
    }

protected:
    std::shared_ptr<ArrayType> type_;
    ConstructorSymbols constructors_;
    FunctionSymbols functions_;
    OperatorSymbols operators_;

};

}

#endif /* ICE_SCRIPT_SYMBOL_ARRAYSYMBOL_HPP */
