#include "generator/llvm/detail/visitors/MixinVisitor.hpp"

#include "generator/llvm/detail/generators/ClassGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

MixinVisitorResultType MixinVisitor::operator()(const asg::Class& classData)
{
    return process(*logger_, *context_, *llvm_, classData);
}


}}}}