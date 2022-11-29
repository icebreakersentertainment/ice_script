#ifndef ICE_SCRIPT_ANALYZER_SCRIPTNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_SCRIPTNODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/ImportNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/EnumNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/TypedefNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ClassNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/MixinNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/InterfaceNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/FuncdefNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/VirtpropNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/VarNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/FuncNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/NamespaceNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ScriptNodeVisitorResultType = boost::variant<
        asg::Import,
        asg::Enumeration,
        Typedefinition,
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

    ScriptNodeVisitorResultType operator()(const ast::ImportNode& node)
    {
        return process(*context_, node);
    }

    ScriptNodeVisitorResultType operator()(const ast::EnumNode& node)
    {
        return process(*context_, node);
    }

    ScriptNodeVisitorResultType operator()(const ast::TypedefNode& node)
    {
        return process(*context_, node);
    }

    ScriptNodeVisitorResultType operator()(const ast::ClassNode& node)
    {
        return process(*context_, node);
    }

    ScriptNodeVisitorResultType operator()(const ast::MixinNode& node)
    {
        return process(*context_, node);
    }

    ScriptNodeVisitorResultType operator()(const ast::InterfaceNode& node)
    {
        return process(*context_, node);
    }

    ScriptNodeVisitorResultType operator()(const ast::FuncdefNode& node)
    {
        return process(*context_, node);
    }

    ScriptNodeVisitorResultType operator()(const ast::VirtpropNode& node)
    {
        return process(*context_, node);
    }

    ScriptNodeVisitorResultType operator()(const ast::VarNode& node)
    {
        return process(*context_, node);
    }

    ScriptNodeVisitorResultType operator()(const ast::FuncNode& node)
    {
        return process(*context_, node);
    }

    ScriptNodeVisitorResultType operator()(const ast::NamespaceNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_SCRIPTNODEVISITOR_HPP
