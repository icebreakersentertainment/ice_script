#ifndef ICE_SCRIPT_SYMBOL_OPERATORSYMBOLS_HPP
#define ICE_SCRIPT_SYMBOL_OPERATORSYMBOLS_HPP

#include <memory>
#include <vector>
// #include <unordered_map>

#include "symbol/OperatorSymbol.hpp"

namespace ice_script
{
 
class OperatorSymbols : public AbstractSymbolContainer<OperatorSymbol>
{
public:
    OperatorSymbols() = default;
    
    std::vector<std::shared_ptr<OperatorSymbol>> find(const OperatorTypeId operatorTypeId) const;
    
    std::vector<std::shared_ptr<OperatorSymbol>> findByParameterTypes(const std::vector<std::shared_ptr<Type>>& parameterTypes) const;
    
// private:
//     std::unordered_map<std::string, std::shared_ptr<T>> operatorTypeIdToSymbolMap_;
};
    
}

#endif /* ICE_SCRIPT_SYMBOL_OPERATORSYMBOLS_HPP */
