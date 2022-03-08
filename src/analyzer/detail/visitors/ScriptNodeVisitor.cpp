#include "analyzer/detail/visitors/ScriptNodeVisitor.hpp"

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

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

ScriptNodeVisitorResultType ScriptNodeVisitor::operator()(const ast::ImportNode& node)
{
    return process(*logger_, *context_, node);
}

ScriptNodeVisitorResultType ScriptNodeVisitor::operator()(const ast::EnumNode& node)
{
    return process(*logger_, *context_, node);
}

ScriptNodeVisitorResultType ScriptNodeVisitor::operator()(const ast::TypedefNode& node)
{
    return process(*logger_, *context_, node);
}

ScriptNodeVisitorResultType ScriptNodeVisitor::operator()(const ast::ClassNode& node)
{
    return process(*logger_, *context_, node);
}

ScriptNodeVisitorResultType ScriptNodeVisitor::operator()(const ast::MixinNode& node)
{
    return process(*logger_, *context_, node);
}

ScriptNodeVisitorResultType ScriptNodeVisitor::operator()(const ast::InterfaceNode& node)
{
    return process(*logger_, *context_, node);
}

ScriptNodeVisitorResultType ScriptNodeVisitor::operator()(const ast::FuncdefNode& node)
{
    return process(*logger_, *context_, node);
}

ScriptNodeVisitorResultType ScriptNodeVisitor::operator()(const ast::VirtpropNode& node)
{
    return process(*logger_, *context_, node);
}

ScriptNodeVisitorResultType ScriptNodeVisitor::operator()(const ast::VarNode& node)
{
    return process(*logger_, *context_, node);
}

ScriptNodeVisitorResultType ScriptNodeVisitor::operator()(const ast::FuncNode& node)
{
    return process(*logger_, *context_, node);
}

ScriptNodeVisitorResultType ScriptNodeVisitor::operator()(const ast::NamespaceNode& node)
{
    return process(*logger_, *context_, node);
}


}}}