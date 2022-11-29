#ifndef ICE_SCRIPT_SYMBOL_ABSTRACTSYMBOLCONTAINER_HPP
#define ICE_SCRIPT_SYMBOL_ABSTRACTSYMBOLCONTAINER_HPP

#include <memory>
#include <vector>
#include <unordered_map>

#include "detail/AbstractContainer.hpp"

namespace ice_script
{

template <typename T>
class AbstractSymbolContainer : detail::AbstractContainer<std::shared_ptr<T>>
{
public:
    using BaseType = detail::AbstractContainer<std::shared_ptr<T>>;
    
    // using BaseType::operator<<;
    // using BaseType::toString;
    using BaseType::size;
    using BaseType::empty;
    using BaseType::operator[];
    using typename BaseType::iterator;
    using typename BaseType::const_iterator;
	using BaseType::begin;
	using BaseType::end;
    using BaseType::cbegin;
	using BaseType::cend;
	
    constexpr AbstractSymbolContainer() = default;
    
    friend std::ostream& operator<<(std::ostream& os, const AbstractSymbolContainer<T>& abstractSymbolContainer)
    {
        os << "(AbstractSymbolContainer)["
        << "container: " << abstractSymbolContainer.container_
        << "]";

        return os;
    }

    friend std::string toString(const AbstractSymbolContainer<T>& abstractSymbolContainer)
    {
        using namespace std::string_literals;

        return "(AbstractSymbolContainer)[\n"s
            + "\tcontainer: " + ice_script::detail::toString(abstractSymbolContainer.container_)
            + "\n]";
    }
    
    constexpr void clear() noexcept
    {
        BaseType::clear();
        keyToSymbolMap_.clear();
        nameToSymbolMap_.clear();
    }
    
    void add(std::shared_ptr<T> symbol);
    void add(const std::vector<std::shared_ptr<T>>& symbols);
    
    std::vector<std::shared_ptr<T>> find(const std::string& name) const;
    // std::vector<std::shared_ptr<T>> find(const OperatorTypeId typeId) const;
    
    std::shared_ptr<T> findByKey(const std::string& key) const;
    
    // std::vector<std::shared_ptr<T>> findByParameterTypes(const std::vector<std::shared_ptr<Type>>& parameterTypes) const;
    
    const std::vector<std::shared_ptr<T>>& getAll() const;
    
protected:
    using BaseType::container_;
    
    std::unordered_map<std::string, std::shared_ptr<T>> keyToSymbolMap_;
    std::unordered_map<std::string, std::vector<std::shared_ptr<T>>> nameToSymbolMap_;
};
    
}

#endif /* ICE_SCRIPT_SYMBOL_ABSTRACTSYMBOLCONTAINER_HPP */
