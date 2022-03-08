#include "generator/llvm/detail/visitors/EnumerationVisitor.hpp"

#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

EnumerationVisitorResultType EnumerationVisitor::operator()(const asg::Identifier& identifier)
{
    return process(*logger_, *context_, *llvm_, identifier);
}

EnumerationVisitorResultType EnumerationVisitor::operator()(const asg::Expression& expression)
{
    return process(*logger_, *context_, *llvm_, expression);
}


}}}}