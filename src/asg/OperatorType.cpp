#include "asg/OperatorType.hpp"

namespace ice_script { namespace asg {

OperatorType::OperatorType(const OperatorTypeId operatorTypeId) : operatorTypeId_(operatorTypeId)
{
    typeId_ = Type::TypeId::FUNCTION;
}

}}