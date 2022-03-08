#include "generator/llvm/detail/visitors/InitlistVisitor.hpp"

#include "generator/llvm/detail/generators/AssignGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

InitlistVisitorResultType InitlistVisitor::operator()(const asg::Assign& assign)
{
    return process(*logger_, *context_, *llvm_, assign);
}


}}}}