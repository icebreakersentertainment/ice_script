#include "generator/llvm/detail/visitors/ReturnVisitor.hpp"

#include "generator/llvm/detail/generators/AssignGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

ReturnVisitorResultType ReturnVisitor::operator()(const asg::Assign& assign)
{
    return process(*logger_, *context_, *llvm_, assign);
}


}}}}