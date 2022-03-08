#include "generator/llvm/detail/visitors/TypeVisitor.hpp"

#include "generator/llvm/detail/generators/ScoperatoreGenerator.hpp"
#include "generator/llvm/detail/generators/DatatypeGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

TypeVisitorResultType TypeVisitor::operator()(const asg::Scoperatore& scoperatore)
{
    return process(*logger_, *context_, *llvm_, scoperatore);
}

TypeVisitorResultType TypeVisitor::operator()(const asg::Datatype& datatype)
{
    return process(*logger_, *context_, *llvm_, datatype);
}


}}}}