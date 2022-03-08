#ifndef ICE_SCRIPT_GENERATOR_NAMESPACEVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_NAMESPACEVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

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

        NamespaceVisitorResultType operator()(const asg::Identifier& identifier);
    NamespaceVisitorResultType operator()(const asg::Script& script);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_NAMESPACEVISITOR_HPP
