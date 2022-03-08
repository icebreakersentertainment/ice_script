#include "analyzer/AnalyzerVisitor.hpp"

#include "analyzer/detail/visitors/ExprvalueNodeVisitor.hpp"

#include "analyzer/detail/analyzers/ArglistNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/AssignopNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/BitopNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/BitsNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/BreakNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/CaseNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/CastNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ClassNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/CompopNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ConditionNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ConstructcallNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ContinueNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/DatatypeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/DowhileNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/EnumNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExpropNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprpostopNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprpreopNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprstatNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprtermNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprvalueNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ForNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/FuncNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/FuncattrNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/FunccallNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/FuncdefNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IfNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ImportNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/InitlistNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/InterfaceNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IntfmthdNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/LambdaNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/LiteralNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/LogicopNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/MathopNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/MixinNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/NamespaceNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/NumberNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ParamlistNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/PrimtypeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ReturnNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ScopeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ScriptNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StatblockNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StatementNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StringNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/SwitchNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/TryNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/TypeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/TypedefNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/TypemodNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/VarNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/VaraccessNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/VirtpropNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/WhileNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer {

using namespace ice_script::ast;
using namespace ice_script::asg;
using namespace ice_script::analyzer::detail;

boost::variant<Initlist, boost::recursive_wrapper<Expression>, Constructcall> AnalyzerVisitor::resolve(const ast::InitListOrExprOrArgListType& initListOrExprOrArgList)
{
    Scope& scope = context_->scope();

//        const auto& scopeNode = node.scopeNode;

    return Expression();
}

asg::Node AnalyzerVisitor::operator()(const ast::ScriptNode& node)
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    Scope& scope = context_->scope();

    return "";
}

asg::Node AnalyzerVisitor::operator()(const ast::ClassNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::TypedefNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::NamespaceNode& node)
{
    return process(*logger_, *context_, node);
}

// FUNC          ::= {'shared' | 'external'} ['private' | 'protected'] [((TYPE ['&']) | '~')] IDENTIFIER PARAMLIST ['const'] FUNCATTR (';' | STATBLOCK)
asg::Node AnalyzerVisitor::operator()(const ast::FuncNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::InterfaceNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::VarNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::ImportNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::EnumNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::FuncdefNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::VirtpropNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::MixinNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::IntfmthdNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::StatblockNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::ParamlistNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::TypemodNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::TypeNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::InitlistNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::ScopeNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::DatatypeNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::PrimtypeNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::FuncattrNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::StatementNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::SwitchNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::BreakNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::ForNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::WhileNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::DowhileNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::IfNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::ContinueNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::ExprstatNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::TryNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::ReturnNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::CaseNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::ExprNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::ExprtermNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::ExprvalueNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::ConstructcallNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::ExprpreopNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::ExprpostopNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::CastNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::LambdaNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::LiteralNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::FunccallNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::VaraccessNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::ArglistNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::AssignNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::ConditionNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::ExpropNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::BitopNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::MathopNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::CompopNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::LogicopNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::AssignopNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::IdentifierNode& node)
{
    std::cout << typeid(node).name() << std::endl;

    return "";
}

asg::Node AnalyzerVisitor::operator()(const ast::NumberNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::StringNode& node)
{
    return process(*logger_, *context_, node);
}

asg::Node AnalyzerVisitor::operator()(const ast::BitsNode& node)
{
    return process(*logger_, *context_, node);
}

}}