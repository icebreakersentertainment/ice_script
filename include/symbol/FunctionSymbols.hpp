#ifndef ICE_SCRIPT_SYMBOL_FUNCTIONSYMBOLS_HPP
#define ICE_SCRIPT_SYMBOL_FUNCTIONSYMBOLS_HPP

#include <memory>
#include <vector>

#include "symbol/FunctionSymbol.hpp"
#include "symbol/AbstractSymbolContainer.hpp"

namespace ice_script
{
 
class FunctionSymbols : public AbstractSymbolContainer<FunctionSymbol>
{
public:
    FunctionSymbols() = default;
    
    std::vector<std::shared_ptr<FunctionSymbol>> findByParameterTypes(const std::vector<std::shared_ptr<Type>>& parameterTypes) const;
};
    
}

#endif /* ICE_SCRIPT_SYMBOL_FUNCTIONSYMBOLS_HPP */
