#ifndef ICE_SCRIPT_SYMBOL_SYMBOLS_HPP
#define ICE_SCRIPT_SYMBOL_SYMBOLS_HPP

#include "symbol/Symbol.hpp"
#include "symbol/AbstractSymbolContainer.hpp"

namespace ice_script
{
 
class Symbols : public AbstractSymbolContainer<Symbol>
{
public:
    Symbols() = default;
};
    
}

#endif /* ICE_SCRIPT_SYMBOL_SYMBOLS_HPP */
