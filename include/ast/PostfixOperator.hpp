#ifndef ICE_SCRIPT_POSTFIXOPERATOR_HPP
#define ICE_SCRIPT_POSTFIXOPERATOR_HPP

#include "exceptions/InvalidArgumentException.hpp"

namespace ice_script { namespace ast {

enum class PostfixOperator
{
    UNKNOWN,
    INCREMENT,
    DECREMENT,
};

inline std::string toString(const PostfixOperator postfixOperator)
{
    switch (postfixOperator)
    {
        case PostfixOperator::UNKNOWN: return "UNKNOWN";
        case PostfixOperator::INCREMENT: return "INCREMENT";
        case PostfixOperator::DECREMENT: return "DECREMENT";

        default:
            throw InvalidArgumentException("Postfix operator not valid.");
    }
}

inline std::ostream& operator<<(std::ostream& os, const PostfixOperator postfixOperator)
{
    os << "(" << boost::typeindex::type_id<PostfixOperator>().pretty_name() << ")[" << toString(postfixOperator) << "]";

    return os;
}

}}

#endif //ICE_SCRIPT_POSTFIXOPERATOR_HPP
