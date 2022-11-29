#include "type/ArrayType.hpp"

namespace ice_script
{

std::string toArrayTypeKey(const ArrayType& arrayType)
{
    return toArrayTypeKey(arrayType.qualifiers(), arrayType.type()->key(), arrayType.dimensions(), arrayType.modifier());
}

}