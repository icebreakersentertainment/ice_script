#ifndef ICE_SCRIPT_TYPE_ABSTRACTTYPECONTAINER_HPP
#define ICE_SCRIPT_TYPE_ABSTRACTTYPECONTAINER_HPP

#include <memory>
#include <vector>
#include <unordered_map>

#include "detail/AbstractContainer.hpp"

namespace ice_script
{

template <typename T>
class AbstractTypeContainer : detail::AbstractContainer<std::shared_ptr<T>>
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
	
    constexpr AbstractTypeContainer() = default;
    
    friend std::ostream& operator<<(std::ostream& os, const AbstractTypeContainer<T>& abstractTypeContainer)
    {
        os << "(AbstractTypeContainer)["
        << "container: " << abstractTypeContainer.container_
        << "]";

        return os;
    }

    friend std::string toString(const AbstractTypeContainer<T>& abstractTypeContainer)
    {
        using namespace std::string_literals;

        return "(AbstractTypeContainer)[\n"s
            + "\tcontainer: " + ice_script::detail::toString(abstractTypeContainer.container_)
            + "\n]";
    }
    
    constexpr void clear() noexcept
    {
        BaseType::clear();
        keyToTypeMap_.clear();
        nameToTypeMap_.clear();
    }
    
    void add(std::shared_ptr<T> type);
    void add(const std::vector<std::shared_ptr<T>>& types);
    
    std::vector<std::shared_ptr<T>> find(const std::string& name) const;
    // std::vector<std::shared_ptr<T>> find(const OperatorTypeId typeId) const;
    
    std::shared_ptr<T> findByKey(const std::string& key) const;
    
    // std::vector<std::shared_ptr<T>> findByParameterTypes(const std::vector<std::shared_ptr<Type>>& parameterTypes) const;
    
    const std::vector<std::shared_ptr<T>>& getAll() const;
    
protected:
    using BaseType::container_;

    std::unordered_map<std::string, std::shared_ptr<T>> keyToTypeMap_;
    std::unordered_map<std::string, std::vector<std::shared_ptr<T>>> nameToTypeMap_;
};
    
}

#endif /* ICE_SCRIPT_TYPE_ABSTRACTTYPECONTAINER_HPP */
