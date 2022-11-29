#ifndef ICE_SCRIPT_INSERTIONOPERATORUTILS_HPP
#define ICE_SCRIPT_INSERTIONOPERATORUTILS_HPP

#include <unordered_map>

#include <boost/type_index.hpp>

namespace std
{

template<typename T>
inline std::ostream& operator<<(std::ostream& os, const std::shared_ptr<T>& sharedPtr)
{
    if (sharedPtr)
    {
        os << *sharedPtr;
    }
    else
    {
         os << "nullptr";
    }

    return os;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& os, const std::vector<T>& vector)
{
    os << "(" << boost::typeindex::type_id<std::vector<T>>().pretty_name() << ")[";

    for (size_t i = 0; i < vector.size(); ++i)
    {
        if (i > 0) os << ", ";

        os << i << " => " << vector[i];
    }

    os << "]";

    return os;
}

template<typename K, typename V>
inline std::ostream& operator<<(std::ostream& os, const std::unordered_map<K, V>& unorderedMap)
{
    os << "(" << boost::typeindex::type_id<std::unordered_map<K, V>>().pretty_name() << ")[";

    bool first = false;
    for (const auto& it : unorderedMap)
    {
        if (first)
        {
            first = false;
        }
        else if (!first)
        {
            os << ", ";
        }

        os << it.first << " => " << it.second;
    }

    os << "]";

    return os;
}

}

#endif //ICE_SCRIPT_INSERTIONOPERATORUTILS_HPP
