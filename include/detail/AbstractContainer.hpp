#ifndef ICE_SCRIPT_DETAIL_ABSTRACTCONTAINER_HPP
#define ICE_SCRIPT_DETAIL_ABSTRACTCONTAINER_HPP

#include <vector>

#include <boost/stl_interfaces/iterator_interface.hpp>

#include "detail/ToStringUtils.hpp"
#include "detail/Assert.hpp"

namespace ice_script { namespace detail {

template <typename T>
class AbstractContainerIterator;

template <typename T>
class AbstractContainerConstIterator;

template <class T>
class AbstractContainer
{
public:
    constexpr AbstractContainer() = default;
    
    virtual ~AbstractContainer() = default;
    
    friend std::ostream& operator<<(std::ostream& os, const AbstractContainer<T>& abstractContainer)
    {
        os << "(AbstractContainer)["
        << "container: " << abstractContainer.container_
        << "]";

        return os;
    }

    friend std::string toString(const AbstractContainer<T>& abstractContainer)
    {
        using namespace std::string_literals;

        return "(AbstractContainer)[\n"s
            + "\tcontainer: " + ice_script::detail::toString(abstractContainer.container_)
            + "\n]";
    }
    
    constexpr size_t size() const noexcept
	{
		return container_.size();
	}
    
    constexpr bool empty() const noexcept
	{
		return container_.empty();
	}
    
    constexpr void clear() noexcept
    {
        container_.clear();
    }
    
    constexpr T& operator[](const size_t index)
	{
        ICE_SCRIPT_ASSERT(container_.size() > index);
        return container_[index];
	}
    
    constexpr const T& operator[](const size_t index) const
	{
        ICE_SCRIPT_ASSERT(container_.size() > index);
        return container_[index];
	}
	
	/* Iterator stuff */
	using iterator = AbstractContainerIterator<T>;
	using const_iterator = AbstractContainerConstIterator<T>;
	
	friend class AbstractContainerIterator<T>;
	friend class AbstractContainerConstIterator<T>;
	
	constexpr iterator begin() noexcept
	{
		return iterator(*this, 0);
	}
 
	constexpr iterator end() noexcept
	{
		return iterator(*this, container_.size());
	}
	
	constexpr const_iterator begin() const noexcept
	{
		return const_iterator(*this, 0);
	}
 
	constexpr const_iterator end() const noexcept
	{
		return const_iterator(*this, container_.size());
	}
	
	constexpr const_iterator cbegin() const noexcept
	{
		return const_iterator(*this, 0);
	}
 
	constexpr const_iterator cend() const noexcept
	{
		return const_iterator(*this, container_.size());
	}
    
protected:
    std::vector<T> container_;
};

template <typename T>
class AbstractContainerIterator : public boost::stl_interfaces::iterator_interface<AbstractContainerIterator<T>, std::forward_iterator_tag, T>
{
public:
    using base_type = boost::stl_interfaces::iterator_interface<AbstractContainerIterator<T>, std::forward_iterator_tag, T>;
    using base_type::operator++;
	
	constexpr AbstractContainerIterator() = default;
	
	constexpr AbstractContainerIterator(AbstractContainer<T>& container, size_t index) noexcept
		:
		container_(&container), index_(index)
	{
		
	}
	
	constexpr AbstractContainerIterator(const AbstractContainerIterator<T>& other) noexcept
		:
		container_(other.container_), index_(other.index_)
	{
		
	}
	
	constexpr AbstractContainerIterator(AbstractContainerIterator<T>&& other) noexcept
		:
		container_(other.container_), index_(other.index_)
	{
		
	}
	
	AbstractContainerIterator<T>& operator=(const AbstractContainerIterator<T>& other) = default;
	
	constexpr bool operator==(const AbstractContainerIterator<T>& other) const noexcept
	{
		return other.index_ == index_;
	}
	
	constexpr T& operator*() const
	{
		return (*container_)[index_];
	}
	
	constexpr T* operator->() const
	{
		return &(*container_)[index_];
	}
	
	constexpr AbstractContainerIterator<T>& operator++() noexcept
	{
        ++index_;
		
		return *this;
	}
	
	constexpr typename base_type::difference_type operator-(const AbstractContainerIterator<T>& other) const noexcept
	{
		return index_ - other.index_;
	}
    
private:
	AbstractContainer<T>* container_;
    size_t index_ = 0;
};

template <typename T>
class AbstractContainerConstIterator : public boost::stl_interfaces::iterator_interface<AbstractContainerConstIterator<T>, std::forward_iterator_tag, T>
{
public:
    using base_type = boost::stl_interfaces::iterator_interface<AbstractContainerConstIterator<T>, std::forward_iterator_tag, T>;
    using base_type::operator++;
	
	constexpr AbstractContainerConstIterator() = default;
	
	constexpr AbstractContainerConstIterator(const AbstractContainer<T>& container, size_t index) noexcept
		:
		container_(&container), index_(index)
	{
		
	}
	
	constexpr AbstractContainerConstIterator(const AbstractContainerConstIterator<T>& other) noexcept
		:
		container_(other.container_), index_(other.index_)
	{
		
	}
	
	constexpr AbstractContainerConstIterator(AbstractContainerConstIterator<T>&& other) noexcept
		:
		container_(other.container_), index_(other.index_)
	{
		
	}
	
	AbstractContainerConstIterator<T>& operator=(const AbstractContainerConstIterator<T>& other) = default;
	
	constexpr bool operator==(const AbstractContainerConstIterator<T>& other) const noexcept
	{
		return other.index_ == index_;
	}
	
	constexpr const T& operator*() const
	{
		return (*container_)[index_];
	}
	
	constexpr const T* operator->() const
	{
		return &(*container_)[index_];
	}
	
	constexpr AbstractContainerConstIterator<T>& operator++() noexcept
	{
        ++index_;
		
		return *this;
	}
	
	constexpr typename base_type::difference_type operator-(const AbstractContainerIterator<T>& other) const noexcept
	{
		return index_ - other.index_;
	}
    
private:
	const AbstractContainer<T>* container_;
    size_t index_ = 0;
};

// static_assert(std::forward_iterator<node_iterator>, ""), or nothing in
// C++17 and earlier.
BOOST_STL_INTERFACES_STATIC_ASSERT_CONCEPT(AbstractContainerIterator, std::forward_iterator)
BOOST_STL_INTERFACES_STATIC_ASSERT_CONCEPT(AbstractContainerConstIterator, std::forward_iterator)

}}

#endif /* ICE_SCRIPT_DETAIL_ABSTRACTCONTAINER_HPP */
