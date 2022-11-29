#include "type/TypeTable.hpp"

#include "exceptions/TypeNotFoundException.hpp"
#include "exceptions/DuplicateTypeException.hpp"

#include "analyzer/detail/AnalyzerUtilities.hpp"

#include "detail/Assert.hpp"
#include "detail/InsertionOperators.hpp"
#include "detail/ToStringUtils.hpp"

namespace ice_script
{

using namespace ice_script::asg;

std::string toString(const TypeTable& typeTable)
{
    using namespace std::string_literals;

    return "(TypeTable)[\n"s
        + "\ttypeMap: "s + detail::toString(typeTable.typeMap_)
        + ",\n\tclassTypeMap: " + detail::toString(typeTable.classTypeMap_)
        + ",\n\tfunctionTypeMap: " + detail::toString(typeTable.functionTypeMap_)
        + ",\n\toperatorTypeMap: " + detail::toString(typeTable.operatorTypeMap_)
        + "\n]";
}

std::ostream& operator<<(std::ostream& os, const TypeTable& typeTable)
{
    os << "(" << boost::typeindex::type_id<TypeTable>().pretty_name() << ")["
        << "typeMap: " << typeTable.typeMap_
        << ", classTypeMap: " << typeTable.classTypeMap_
        << ", operatorTypeMap: " << typeTable.operatorTypeMap_
        << "]";

    return os;
}

}