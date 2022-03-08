#ifndef ICE_SCRIPT_OPERATORTYPE_HPP
#define ICE_SCRIPT_OPERATORTYPE_HPP

#include <vector>
#include <memory>

#include "asg/FunctionType.hpp"
#include "asg/OperatorTypeId.hpp"

namespace ice_script { namespace asg {

class OperatorType : public FunctionType
{
public:
    OperatorType(const OperatorTypeId operatorTypeId);

    OperatorTypeId operatorTypeId() const
    {
        return operatorTypeId_;
    }

protected:
    OperatorTypeId operatorTypeId_;

};

}}

#endif //ICE_SCRIPT_OPERATORTYPE_HPP
