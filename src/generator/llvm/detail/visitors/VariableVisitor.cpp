#include "generator/llvm/detail/visitors/VariableVisitor.hpp"

#include "generator/llvm/detail/generators/InitlistGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionGenerator.hpp"
#include "generator/llvm/detail/generators/ArglistGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

VariableVisitorResultType VariableVisitor::operator()(const asg::Initlist& initlist)
{
    return process(*logger_, *context_, *llvm_, initlist);
}

VariableVisitorResultType VariableVisitor::operator()(const asg::Expression& expression)
{
    return process(*logger_, *context_, *llvm_, expression);
}

VariableVisitorResultType VariableVisitor::operator()(const asg::Arglist& arglist)
{
    return process(*logger_, *context_, *llvm_, arglist);
}

}}}}