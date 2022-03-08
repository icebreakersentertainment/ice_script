#ifndef ICE_SCRIPT_ANALYZER_TYPERESOLVER_HPP
#define ICE_SCRIPT_ANALYZER_TYPERESOLVER_HPP

#include "ast/TypeNode.hpp"
#include "ast/PrimtypeNode.hpp"

#include "asg/Type.hpp"
#include "asg/Expressionvalue.hpp"
#include "asg/Expressionpostoperator.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

std::shared_ptr<asg::Type> resolve(logger::ILogger& logger, Context& context, const ast::TypeNode& node);
std::shared_ptr<asg::FunctionType> resolveFunctionType(logger::ILogger& logger, Context& context, const ast::TypeNode& node);

std::shared_ptr<asg::Type> resolveType(logger::ILogger& logger, Context& context, const asg::Expressionvalue& expressionvalue);
std::shared_ptr<asg::Type> resolveType(logger::ILogger& logger, Context& context, const asg::Expressionpostoperator& expressionpostoperator);

}}}

#endif //ICE_SCRIPT_ANALYZER_TYPERESOLVER_HPP
