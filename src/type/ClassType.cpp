#include "type/ClassType.hpp"

#include "detail/ToStringUtils.hpp"

namespace ice_script
{

std::ostream& operator<<(std::ostream& os, const ClassType& classType)
{
    os << "(ClassType)[name: " + classType.name() + ", typeId: " + toString(classType.typeId()) << "]";

    return os;
}

std::string toString(const ClassType& classType)
{
    return toString(static_cast<const Type&>(classType))
        + ", memberVariables: [" + toString(classType.memberVariables()) + "]"
        + ", constructors: [" + toString(classType.constructors()) + "]"
//        + ", returnType: [" + toString(*classType.returnType()) + "]"
//        + ", parameters: {" + toString(classType.parameters()) + "}"
        ;
}

}