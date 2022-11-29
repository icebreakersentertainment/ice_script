#include "type/Types.hpp"

namespace ice_script
{

template class AbstractTypeContainer<Type>;
// template void AbstractTypeContainer<FunctionType>::add(std::shared_ptr<FunctionType> type);
// template void AbstractTypeContainer<FunctionType>::add(const std::vector<std::shared_ptr<FunctionType>>& types);
// template std::vector<std::shared_ptr<FunctionType>> AbstractTypeContainer<FunctionType>::find(const std::string& name) const;
// template std::shared_ptr<FunctionType> AbstractTypeContainer<FunctionType>::findByKey(const std::string& key) const;
// template const std::vector<std::shared_ptr<FunctionType>>& AbstractTypeContainer<FunctionType>::getAll() const;

}

#include "type/AbstractTypeContainer.inl"