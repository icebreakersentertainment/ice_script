#ifndef ICE_SCRIPT_OPERATORTYPE_HPP
#define ICE_SCRIPT_OPERATORTYPE_HPP

#include <vector>
#include <memory>

#include <boost/algorithm/string.hpp>

#include "type/FunctionType.hpp"
#include "type/OperatorTypeId.hpp"

namespace ice_script
{

inline std::string toOperatorTypeKey(const std::string& returnTypeKey, const OperatorTypeId operatorTypeId, const std::string& classTypeKey, const std::vector<std::string>& parameterTypeKeys)
{
    const auto parameters = boost::algorithm::join(parameterTypeKeys, "_");
    
    return ice_script::detail::format(
        "%s_%s_%s%s",
        returnTypeKey,
        "operator_" + boost::algorithm::to_lower_copy(toString(operatorTypeId)),
        !classTypeKey.empty() ? classTypeKey + "_" : "",
        parameters
    );
}

class OperatorType;

std::string toOperatorTypeKey(const OperatorType& operatorType);

class OperatorType : public FunctionType
{
public:
    OperatorType(const OperatorTypeId operatorTypeId);
    
    OperatorType(const OperatorType& other) : FunctionType(other)
    {
        operatorTypeId_ = other.operatorTypeId_;
    }
    
    const std::string& key() const override
    {
        // if (!key_.empty()) return key_;
        
        key_ = toOperatorTypeKey(*this);
        
        return key_;
    }

    bool isMethod() const override
    {
        return true;
    }

    OperatorTypeId operatorTypeId() const
    {
        return operatorTypeId_;
    }

protected:
    OperatorTypeId operatorTypeId_;

};

}

#endif //ICE_SCRIPT_OPERATORTYPE_HPP
