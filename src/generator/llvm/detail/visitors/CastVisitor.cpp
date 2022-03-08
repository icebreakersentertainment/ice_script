#include "generator/llvm/detail/visitors/CastVisitor.hpp"

#include "generator/llvm/detail/generators/TypeGenerator.hpp"
#include "generator/llvm/detail/generators/AssignGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

CastVisitorResultType CastVisitor::operator()(const asg::Type& type)
{
    return process(*logger_, *context_, *llvm_, type);
}

CastVisitorResultType CastVisitor::operator()(const asg::Assign& assign)
{
    return process(*logger_, *context_, *llvm_, assign);
}


}}}}