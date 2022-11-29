#ifndef ICE_SCRIPT_DETAIL_SYMBOLKEYRESOLVER_HPP
#define ICE_SCRIPT_DETAIL_SYMBOLKEYRESOLVER_HPP

#include <string>

// #include "type/OperatorType.hpp"
#include "type/ArrayType.hpp"
#include "type/ClassType.hpp"
// #include "symbol/FunctionSymbol.hpp"
#include "symbol/ArraySymbol.hpp"
#include "symbol/ClassSymbol.hpp"

#include "detail/Format.hpp"

namespace ice_script { namespace detail {

// inline std::string resolveSymbolKey(const std::shared_ptr<OperatorType>& type)
// {
//     std::vector<std::string> parameterTypeKeys{};
//     for (const auto& parameter : type->parameters()) parameterTypeKeys.push_back(parameter->key());
    
//     return toFunctionSymbolKey(
//         type->fullyQualifiedScopeName(),
//         // (ownerSymbol ? ownerSymbol->name() : ""),
//         (type->ownerType() ? type->ownerType()->name() : ""),
//         type->name(),
//         parameterTypeKeys
//     );
// }

inline std::string resolveSymbolKey(const std::shared_ptr<ArrayType>& type)
{
    return toArraySymbolKey(type->fullyQualifiedScopeName(), type->name());
}

inline std::string resolveSymbolKey(const std::shared_ptr<ClassType>& type)
{
    return toClassSymbolKey(type->fullyQualifiedScopeName(), type->name());
}

}}

#endif /* ICE_SCRIPT_DETAIL_SYMBOLKEYRESOLVER_HPP */
