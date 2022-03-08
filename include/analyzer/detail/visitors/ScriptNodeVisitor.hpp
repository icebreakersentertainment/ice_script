#ifndef ICE_SCRIPT_ANALYZER_SCRIPTNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_SCRIPTNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ScriptNodeVisitorResultType = boost::variant<
            asg::Import,
    asg::Enumeration,
    asg::Typedefinition,
    asg::Class,
    asg::Mixin,
    asg::Interface,
    asg::Functiondefinition,
    asg::Virtualproperatorerty,
    asg::Variable,
    asg::Function,
    asg::Namespace
>;

class ScriptNodeVisitor : public AbstractVisitor<ScriptNodeVisitor, ScriptNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        ScriptNodeVisitorResultType operator()(const ast::ImportNode& node);
    ScriptNodeVisitorResultType operator()(const ast::EnumNode& node);
    ScriptNodeVisitorResultType operator()(const ast::TypedefNode& node);
    ScriptNodeVisitorResultType operator()(const ast::ClassNode& node);
    ScriptNodeVisitorResultType operator()(const ast::MixinNode& node);
    ScriptNodeVisitorResultType operator()(const ast::InterfaceNode& node);
    ScriptNodeVisitorResultType operator()(const ast::FuncdefNode& node);
    ScriptNodeVisitorResultType operator()(const ast::VirtpropNode& node);
    ScriptNodeVisitorResultType operator()(const ast::VarNode& node);
    ScriptNodeVisitorResultType operator()(const ast::FuncNode& node);
    ScriptNodeVisitorResultType operator()(const ast::NamespaceNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_SCRIPTNODEVISITOR_HPP
