#include "generator/llvm/detail/visitors/SwitchVisitor.hpp"

#include "generator/llvm/detail/generators/AssignGenerator.hpp"
#include "generator/llvm/detail/generators/CaseGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

SwitchVisitorResultType SwitchVisitor::operator()(const asg::Assign& assign)
{
    return process(*logger_, *context_, *llvm_, assign);
}

SwitchVisitorResultType SwitchVisitor::operator()(const asg::Case& caseStatement)
{
    return process(*logger_, *context_, *llvm_, caseStatement);
}


}}}}