#include "generator/llvm/detail/visitors/StatblockVisitor.hpp"

#include "generator/llvm/detail/generators/VariableGenerator.hpp"
#include "generator/llvm/detail/generators/StatementGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

StatblockVisitorResultType StatblockVisitor::operator()(const asg::Variable& variable)
{
    return process(*logger_, *context_, *llvm_, variable);
}

StatblockVisitorResultType StatblockVisitor::operator()(const asg::Statement& statement)
{
    return process(*logger_, *context_, *llvm_, statement);
}


}}}}