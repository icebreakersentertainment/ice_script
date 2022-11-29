#ifndef ICE_SCRIPT_GENERATOR_NAMESPACEVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_NAMESPACEVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/ScriptGenerator.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using NamespaceVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class NamespaceVisitor : public AbstractVisitor<NamespaceVisitor, NamespaceVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    NamespaceVisitorResultType operator()(const asg::Identifier& identifier)
    {
        return process(*context_, *llvm_, identifier);
    }

    NamespaceVisitorResultType operator()(const asg::Script& script)
    {
        return process(*context_, *llvm_, script);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_NAMESPACEVISITOR_HPP
