#ifndef ICE_SCRIPT_FUNCTIONSYMBOL_HPP
#define ICE_SCRIPT_FUNCTIONSYMBOL_HPP

#include <string>
#include <memory>

#include <boost/algorithm/string.hpp>

#include <range/v3/view.hpp>
#include <range/v3/view/any_view.hpp>

#include "symbol/Symbol.hpp"
#include "symbol/Symbols.hpp"

#include "type/FunctionType.hpp"

#include "detail/Format.hpp"

namespace ice_script
{

inline std::string toFunctionSymbolKey(const std::string& fullyQualifiedScopeName, const std::string& className, const std::string& functionName, const std::vector<std::string>& parameterTypeKeys)
{
    const auto fullyQualifiedName = ice_script::detail::format(
        "%s%s%s%s",
        fullyQualifiedScopeName,
        boost::algorithm::ends_with(fullyQualifiedScopeName, "::") ? "" : "::",
        !className.empty() ? className + "::" : "",
        functionName
    );
    
    const auto parameters = (parameterTypeKeys.empty() ? "" : "_") + boost::algorithm::join(parameterTypeKeys, "_");
    
    return ice_script::detail::format(
        "function_%s%s",
        fullyQualifiedName,
        parameters
    );
}

class FunctionSymbol;

inline std::string toFunctionSymbolKey(const FunctionSymbol& functionSymbol);

class FunctionSymbol : public Symbol
{
public:
    using Symbol::Symbol;
    
    friend std::ostream& operator<<(std::ostream& os, const FunctionSymbol& symbol)
    {
        os << "(" << boost::typeindex::type_id<FunctionSymbol>().pretty_name() << ")["
        << "name: " << symbol.name_
        << ", type: " << symbol.type_
        << ", parameters: " << symbol.parameters_
        << ", returnSymbol: " << symbol.returnSymbol_
        << ", ownerSymbol: " << symbol.ownerSymbol_
        << "]";

        return os;
    }

    friend std::string toString(const FunctionSymbol& symbol)
    {
        using namespace std::string_literals;

        return "(FunctionSymbol)[\n"s
            + "\tname: "s + symbol.name_
            + ",\n\ttype: " + detail::toString(symbol.type_)
            + ",\n\tparameters: " + toString(symbol.parameters_)
            + ",\n\treturnSymbol: " + detail::toString(symbol.returnSymbol_)
            + ",\n\townerSymbol: " + detail::toString(symbol.ownerSymbol_)
            + "\n]";
    }

    std::shared_ptr<FunctionType> type()
    {
        return type_;
    }

    const std::shared_ptr<FunctionType>& type() const
    {
        return type_;
    }

    void setType(std::shared_ptr<FunctionType> type)
    {
        Symbol::setType(type);
        type_ = std::move(type);
    }
    
    virtual const std::string& key() const
    {
        // if (!key_.empty()) return key_;
        
        key_ = toFunctionSymbolKey(*this);
        
        return key_;
    }
    
    Symbols& parameters()
    {
        return parameters_;
    }

    const Symbols& parameters() const
    {
        return parameters_;
    }

    const std::shared_ptr<Symbol>& returnSymbol() const
    {
        return returnSymbol_;
    }

    void setReturnType(std::shared_ptr<Symbol> returnSymbol)
    {
        returnSymbol_ = std::move(returnSymbol);
    }

protected:
    std::shared_ptr<FunctionType> type_;
    // std::vector<std::shared_ptr<Symbol>> parameters_;
    Symbols parameters_;
    std::shared_ptr<Symbol> returnSymbol_;
    // std::shared_ptr<Symbol> ownerSymbol_;

};

inline std::string toFunctionSymbolKey(const FunctionSymbol& functionSymbol)
{
    const auto parameterTypeKeys = functionSymbol.parameters()
        | ranges::views::transform([&](const auto& parameterSymbol) { return parameterSymbol->type()->key(); })
        | ranges::to<std::vector>()
        ;
    
    return toFunctionSymbolKey(
        functionSymbol.fullyQualifiedScopeName(),
        (functionSymbol.ownerSymbol() ? functionSymbol.ownerSymbol()->name() : ""),
        functionSymbol.name(),
        parameterTypeKeys
    );
}

}

#endif //ICE_SCRIPT_FUNCTIONSYMBOL_HPP
