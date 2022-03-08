#include "generator/llvm/detail/visitors/DowhileVisitor.hpp"

#include "generator/llvm/detail/generators/StatementGenerator.hpp"
#include "generator/llvm/detail/generators/AssignGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

DowhileVisitorResultType DowhileVisitor::operator()(const asg::Statement& statement)
{
    return process(*logger_, *context_, *llvm_, statement);
}

DowhileVisitorResultType DowhileVisitor::operator()(const asg::Assign& assign)
{
    return process(*logger_, *context_, *llvm_, assign);
}


}}}}