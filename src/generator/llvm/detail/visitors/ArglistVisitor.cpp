#include "generator/llvm/detail/visitors/ArglistVisitor.hpp"

#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/AssignGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

ArglistVisitorResultType ArglistVisitor::operator()(const asg::Identifier& identifier)
{
    return process(*logger_, *context_, *llvm_, identifier);
}

ArglistVisitorResultType ArglistVisitor::operator()(const asg::Assign& assign)
{
    return process(*logger_, *context_, *llvm_, assign);
}


}}}}