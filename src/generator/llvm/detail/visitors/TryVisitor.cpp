#include "generator/llvm/detail/visitors/TryVisitor.hpp"

#include "generator/llvm/detail/generators/StatblockGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

TryVisitorResultType TryVisitor::operator()(const asg::Statblock& statblock)
{
    return process(*logger_, *context_, *llvm_, statblock);
}


}}}}