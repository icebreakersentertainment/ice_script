#ifndef ICE_SCRIPT_TOSTRINGUTILS_HPP
#define ICE_SCRIPT_TOSTRINGUTILS_HPP

#include <boost/type_index.hpp>

namespace ice_script { namespace detail {

template <typename T>
inline std::string toString(const std::shared_ptr<T>& sharedPtr)
{
    if (!sharedPtr) return "nullptr";
    
    return toString(*sharedPtr);
}

template <typename T>
inline std::string toString(const std::vector<T>& vector)
{
    std::stringstream ss{};

    for (size_t i = 0; i < vector.size(); ++i)
    {
        ss << (i == 0 ? "" : ",\n") << i << " => " << toString(vector[i]);
    }

    return ss.str();
}

template<typename K, typename V>
inline std::string toString(const std::unordered_map<K, V>& unorderedMap)
{
    std::stringstream ss{};

    ss << "(" << boost::typeindex::type_id<std::unordered_map<K, V>>().pretty_name() << ")[\n";

    bool first = false;
    for (const auto& it : unorderedMap)
    {
        if (first)
        {
            first = false;
        }
        else if (!first)
        {
            ss << ",\n";
        }

        ss << "\t" << it.first << " => " << toString(it.second);
    }

    ss << "\n]";

    return ss.str();
}

}}

#endif //ICE_SCRIPT_TOSTRINGUTILS_HPP
