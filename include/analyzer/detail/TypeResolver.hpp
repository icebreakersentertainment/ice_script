#ifndef ICE_SCRIPT_ANALYZER_TYPERESOLVER_HPP
#define ICE_SCRIPT_ANALYZER_TYPERESOLVER_HPP

#include "ast/TypeNode.hpp"
#include "ast/PrimtypeNode.hpp"

#include "type/Type.hpp"
#include "asg/Expressionvalue.hpp"
#include "asg/Expressionpostoperator.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

std::shared_ptr<Type> resolve(Context& context, const ast::TypeNode& node);
std::shared_ptr<FunctionType> resolveFunctionType(Context& context, const ast::TypeNode& node);

std::shared_ptr<Type> resolveType(Context& context, const asg::Assign& assign);
std::shared_ptr<Type> resolveType(Context& context, const asg::Condition& condition);
std::shared_ptr<Type> resolveType(Context& context, const asg::Expression& expression);
std::shared_ptr<Type> resolveType(Context& context, const asg::Expressionterm& expressionterm);
std::shared_ptr<Type> resolveType(Context& context, const asg::Expressionvalue& expressionvalue);
std::shared_ptr<Type> resolveType(Context& context, const asg::Expressionpostoperator& expressionpostoperator);
std::shared_ptr<Type> resolveType(Context& context, const asg::ExprpreopsExprvalueExprpostops& exprpreopsExprvalueExprpostops);

}}}

#endif //ICE_SCRIPT_ANALYZER_TYPERESOLVER_HPP
