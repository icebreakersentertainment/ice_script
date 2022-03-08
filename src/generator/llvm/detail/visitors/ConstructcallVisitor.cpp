#include "generator/llvm/detail/visitors/ConstructcallVisitor.hpp"

#include "generator/llvm/detail/generators/TypeGenerator.hpp"
#include "generator/llvm/detail/generators/ArglistGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

ConstructcallVisitorResultType ConstructcallVisitor::operator()(const asg::Type& type)
{
    return process(*logger_, *context_, *llvm_, type);
}

ConstructcallVisitorResultType ConstructcallVisitor::operator()(const asg::Arglist& arglist)
{
    return process(*logger_, *context_, *llvm_, arglist);
}


}}}}