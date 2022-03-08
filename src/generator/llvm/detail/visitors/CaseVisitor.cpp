#include "generator/llvm/detail/visitors/CaseVisitor.hpp"

#include "generator/llvm/detail/generators/ExpressionGenerator.hpp"
#include "generator/llvm/detail/generators/StatementGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

CaseVisitorResultType CaseVisitor::operator()(const asg::Expression& expression)
{
    return process(*logger_, *context_, *llvm_, expression);
}

CaseVisitorResultType CaseVisitor::operator()(const asg::Statement& statement)
{
    return process(*logger_, *context_, *llvm_, statement);
}


}}}}