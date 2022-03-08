#include "generator/llvm/detail/visitors/AssignVisitor.hpp"

#include "generator/llvm/detail/generators/ConditionGenerator.hpp"
#include "generator/llvm/detail/generators/AssignoperatorGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

AssignVisitorResultType AssignVisitor::operator()(const asg::Condition& condition)
{
    return process(*logger_, *context_, *llvm_, condition);
}

AssignVisitorResultType AssignVisitor::operator()(const asg::Assignoperator& assignoperator)
{
    return process(*logger_, *context_, *llvm_, assignoperator);
}


}}}}