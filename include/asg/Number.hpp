#ifndef ICE_SCRIPT_ASG_NUMBER_HPP
#define ICE_SCRIPT_ASG_NUMBER_HPP

#include "asg/Integer8.hpp"
#include "asg/Integer16.hpp"
#include "asg/Integer32.hpp"
#include "asg/Integer.hpp"
#include "asg/Integer64.hpp"
#include "asg/UInteger8.hpp"
#include "asg/UInteger16.hpp"
#include "asg/UInteger32.hpp"
#include "asg/UInteger.hpp"
#include "asg/UInteger64.hpp"
#include "asg/Float.hpp"
#include "asg/Double.hpp"
#include "asg/LocationInfo.hpp"

#include "detail/monostate.hpp"

namespace ice_script { namespace asg {

using NumberType = boost::variant<
        monostate,
        Integer8,
        Integer16,
        Integer32,
        Integer,
        Integer64,
        UInteger8,
        UInteger16,
        UInteger32,
        UInteger,
        UInteger64,
        Float,
        Double
>;

// NUMBER        ::= single token:  includes integers and real numbers, same as C++
struct Number : LocationInfo
{
    Number() = default;
    Number(NumberType value) : value(std::move(value))
    {

    }

//    std::shared_ptr<Type> type;
    NumberType value;
};

}}

#endif //ICE_SCRIPT_ASG_NUMBER_HPP