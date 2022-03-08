#include "generator/llvm/detail/visitors/NamespaceVisitor.hpp"

#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/ScriptGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

NamespaceVisitorResultType NamespaceVisitor::operator()(const asg::Identifier& identifier)
{
    return process(*logger_, *context_, *llvm_, identifier);
}

NamespaceVisitorResultType NamespaceVisitor::operator()(const asg::Script& script)
{
    return process(*logger_, *context_, *llvm_, script);
}


}}}}