#ifndef ICE_SCRIPT_ASG_TYPE_HPP
#define ICE_SCRIPT_ASG_TYPE_HPP

#include <string>
#include <vector>
#include <memory>

#include "asg/Scoperatore.hpp"
#include "asg/Datatype.hpp"

#include "asg/OperatorTypeId.hpp"

namespace ice_script { namespace asg {

class OperatorType;

//struct Type
//{
//    std::string value;
//};

class Type
{
public:
    enum class TypeId
    {
        VOID_T = 0,
        INTEGER8,
        INTEGER16,
        INTEGER32,
        INTEGER,
        INTEGER64,
        UINTEGER8,
        UINTEGER16,
        UINTEGER32,
        UINTEGER,
        UINTEGER64,
        FLOAT,
        DOUBLE,

        FUNCTION,
    };

    Type() = default;

    explicit Type(const TypeId typeId) : typeId_(typeId)
    {

    }

    virtual ~Type() = default;

    TypeId typeId() const
    {
        return typeId_;
    }

    const std::string& name() const
    {
        return name_;
    }

    void setName(std::string name)
    {
        name_ = std::move(name);
    }

    std::vector<std::shared_ptr<OperatorType>> findOperators(const OperatorTypeId operatorTypeId);

    void setOperators(std::vector<std::shared_ptr<OperatorType>> operators);

protected:
    // TYPE          ::= ['const'] SCOPE DATATYPE ['<' TYPE {',' TYPE} '>'] { ('[' ']') | ('@' ['const']) }
    TypeId typeId_;
    std::string name_;
    bool isConst_;
    std::vector<std::shared_ptr<OperatorType>> operators_;
//    Scope scope;
//    DataType dataType;
//    TypeNodeTemplates templates;
//    std::vector<
//            boost::variant<std::string, boost::tuple<std::string, boost::optional<std::string>>>
//    > bracketsOrAtOptionalConst;
};

}}

#endif //ICE_SCRIPT_ASG_TYPE_HPP