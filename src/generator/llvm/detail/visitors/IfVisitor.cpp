#include "generator/llvm/detail/visitors/IfVisitor.hpp"

#include "generator/llvm/detail/generators/AssignGenerator.hpp"
#include "generator/llvm/detail/generators/StatementGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

IfVisitorResultType IfVisitor::operator()(const asg::Assign& assign)
{
    return process(*logger_, *context_, *llvm_, assign);
}

IfVisitorResultType IfVisitor::operator()(const asg::Statement& statement)
{
    return process(*logger_, *context_, *llvm_, statement);
}


}}}}