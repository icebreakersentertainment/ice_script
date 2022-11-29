#ifndef ICE_SCRIPT_CLASSSYMBOL_HPP
#define ICE_SCRIPT_CLASSSYMBOL_HPP

#include <string>
#include <memory>

#include "symbol/Symbol.hpp"
#include "symbol/Symbols.hpp"
#include "symbol/FunctionSymbol.hpp"
#include "symbol/OperatorSymbols.hpp"
#include "symbol/FunctionSymbols.hpp"
#include "symbol/ConstructorSymbols.hpp"

#include "type/ClassType.hpp"

namespace ice_script
{

inline std::string toClassSymbolKey(const std::string& fullyQualifiedScopeName, const std::string& name)
{
    return detail::format(
            "class_%s%s",
            fullyQualifiedScopeName,
            boost::algorithm::ends_with(fullyQualifiedScopeName, "::") ? name : "::" + name
        );
}

class ClassSymbol : public Symbol
{
public:
    using Symbol::Symbol;
    
    friend std::ostream& operator<<(std::ostream& os, const ClassSymbol& symbol)
    {
        os << "(" << boost::typeindex::type_id<ClassSymbol>().pretty_name() << ")["
        << "name: " << symbol.name_
        << ", type: " << symbol.type_
        << ", memberVariables: " << symbol.memberVariables_
        << ", constructors: " << symbol.constructors_
        << ", functions: " << symbol.functions_
        << "]";

        return os;
    }

    friend std::string toString(const ClassSymbol& symbol)
    {
        using namespace std::string_literals;

        return "(ClassSymbol)[\n"s
            + "\tname: "s + symbol.name_
            + ",\n\ttype: " + detail::toString(symbol.type_)
            + ",\n\tmemberVariables: " + toString(symbol.memberVariables_)
            + ",\n\tconstructors: " + toString(symbol.constructors_)
            + ",\n\tfunctions: " + toString(symbol.functions_)
            + "\n]";
    }

    std::shared_ptr<ClassType> type()
    {
        return type_;
    }

    const std::shared_ptr<ClassType>& type() const
    {
        return type_;
    }

    void setType(std::shared_ptr<ClassType> type)
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
        
        key_ = toClassSymbolKey(fullyQualifiedScopeName_, name_);
        
        return key_;
        // return name_;
    }
    
    Symbols& memberVariables()
    {
        return memberVariables_;
    }
    
    const Symbols& memberVariables() const
    {
        return memberVariables_;
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
    std::shared_ptr<ClassType> type_;
    Symbols memberVariables_;
    ConstructorSymbols constructors_;
    FunctionSymbols functions_;
    OperatorSymbols operators_;

};

}

#endif //ICE_SCRIPT_CLASSSYMBOL_HPP
