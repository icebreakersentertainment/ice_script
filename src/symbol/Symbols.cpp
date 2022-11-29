#include "symbol/Symbols.hpp"

namespace ice_script
{

template class AbstractSymbolContainer<Symbol>;
// template void AbstractSymbolContainer<Symbol>::add(std::shared_ptr<Symbol> type);
// template void AbstractSymbolContainer<Symbol>::add(const std::vector<std::shared_ptr<Symbol>>& types);
// template std::vector<std::shared_ptr<Symbol>> AbstractSymbolContainer<Symbol>::find(const std::string& name) const;
// template std::shared_ptr<Symbol> AbstractSymbolContainer<Symbol>::findByKey(const std::string& key) const;
// template const std::vector<std::shared_ptr<Symbol>>& AbstractSymbolContainer<Symbol>::getAll() const;

}

#include "symbol/AbstractSymbolContainer.inl"