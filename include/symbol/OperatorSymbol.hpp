#ifndef ICE_SCRIPT_SYMBOL_OPERATORSYMBOL_HPP
#define ICE_SCRIPT_SYMBOL_OPERATORSYMBOL_HPP

#include <string>
#include <memory>

#include <boost/algorithm/string.hpp>

#include <range/v3/view.hpp>
#include <range/v3/view/any_view.hpp>

#include "symbol/Symbol.hpp"
#include "symbol/FunctionSymbol.hpp"
#include "symbol/Symbols.hpp"

#include "type/OperatorType.hpp"

#include "detail/Format.hpp"

namespace ice_script
{

inline std::string toOperatorSymbolKey(const std::string& fullyQualifiedScopeName, const std::string& returnTypeKey, const std::string& className, const std::string& functionName, const std::vector<std::string>& parameterTypeKeys)
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
        "function_%s%s%s",
        fullyQualifiedName,
        returnTypeKey,
        parameters
    );
}

class OperatorSymbol;

inline std::string toOperatorSymbolKey(const OperatorSymbol& operatorSymbol);

class OperatorSymbol : public FunctionSymbol
{
public:
    using FunctionSymbol::FunctionSymbol;
    
    friend std::ostream& operator<<(std::ostream& os, const OperatorSymbol& symbol)
    {
        os << "(OperatorSymbol)["
        << "name: " << symbol.name_
        << ", type: " << symbol.type_
        << ", parameters: " << symbol.parameters_
        << ", returnSymbol: " << symbol.returnSymbol_
        << ", ownerSymbol: " << symbol.ownerSymbol_
        << "]";

        return os;
    }

    friend std::string toString(const OperatorSymbol& symbol)
    {
        using namespace std::string_literals;

        return "(OperatorSymbol)[\n"s
            + "\tname: "s + symbol.name_
            + ",\n\ttype: " + detail::toString(symbol.type_)
            + ",\n\tparameters: " + toString(symbol.parameters_)
            + ",\n\treturnSymbol: " + detail::toString(symbol.returnSymbol_)
            + ",\n\townerSymbol: " + detail::toString(symbol.ownerSymbol_)
            + "\n]";
    }

    std::shared_ptr<OperatorType> type()
    {
        return type_;
    }

    const std::shared_ptr<OperatorType>& type() const
    {
        return type_;
    }

    void setType(std::shared_ptr<OperatorType> type)
    {
        FunctionSymbol::setType(type);
        type_ = std::move(type);
    }
    
    virtual const std::string& key() const
    {
        // if (!key_.empty()) return key_;
        
        key_ = toOperatorSymbolKey(*this);
        
        return key_;
    }
    
protected:
    std::shared_ptr<OperatorType> type_;
    // std::shared_ptr<Symbol> ownerSymbol_;

};

inline std::string toOperatorSymbolKey(const OperatorSymbol& operatorSymbol)
{
    const auto parameterTypeKeys = operatorSymbol.parameters()
        | ranges::views::transform([&](const auto& parameterType) { return parameterType->type()->key(); })
        | ranges::to<std::vector>()
        ;
    
    return toOperatorSymbolKey(
        operatorSymbol.fullyQualifiedScopeName(),
        // operatorSymbol.returnSymbol()->type()->key(),
        operatorSymbol.type()->returnType()->key(),
        (operatorSymbol.ownerSymbol() ? operatorSymbol.ownerSymbol()->name() : ""),
        operatorSymbol.name(),
        parameterTypeKeys
    );
}

}

#endif /* ICE_SCRIPT_SYMBOL_OPERATORSYMBOL_HPP */
