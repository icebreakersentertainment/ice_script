#include "generator/llvm/detail/visitors/FunctioncallVisitor.hpp"

#include "generator/llvm/detail/generators/ScoperatoreGenerator.hpp"
#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/ArglistGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

FunctioncallVisitorResultType FunctioncallVisitor::operator()(const asg::Scoperatore& scoperatore)
{
    return process(*logger_, *context_, *llvm_, scoperatore);
}

FunctioncallVisitorResultType FunctioncallVisitor::operator()(const asg::Identifier& identifier)
{
    return process(*logger_, *context_, *llvm_, identifier);
}

FunctioncallVisitorResultType FunctioncallVisitor::operator()(const asg::Arglist& arglist)
{
    return process(*logger_, *context_, *llvm_, arglist);
}


}}}}