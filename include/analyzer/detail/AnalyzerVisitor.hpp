#ifndef ICE_SCRIPT_ANALYZER_ANALYZERVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_ANALYZERVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "symbol/SymbolTable.hpp"
#include "analyzer/detail/Scope.hpp"
#include "analyzer/detail/Context.hpp"

#include "detail/monostate.hpp"

namespace ice_script { namespace analyzer { namespace detail {

class AnalyzerVisitor : public boost::static_visitor<asg::Node>
{
public:
    AnalyzerVisitor(Context& context, Scope& scope, SymbolTable& symbolTable)
            :
            context_(&context),
            scope_(&scope),
            symbolTable_(&symbolTable)
    {

    }

    asg::Node operator()(const monostate& node)
    {
        ICE_SCRIPT_ASSERT(false);

        return "";
    }
    
    asg::Node operator()(const std::string& string)
    {
        std::cout << "wtf string: " << string << std::endl;

        return "";
    }

    asg::Node operator()(const boost::spirit::qi::unused_type& unusedType)
    {
        std::cout << "wtf: " << typeid(unusedType).name() << std::endl;

        return "";
    }

    template<
            typename T,
            typename = typename std::enable_if<std::is_base_of<ast::LocationInfo, T>::value, T>::type
    >
    asg::Node operator()(const boost::recursive_wrapper <T>& node)
    {
        return operator()(node.get());
    }

    template<
            typename T,
            typename = typename std::enable_if<std::is_base_of<ast::LocationInfo, T>::value, T>::type
    >
    asg::Node operator()(const T& node)
    {
        LOG_DEBUG((&context_->logger()), "Analyzing %s", typeid(node).name())

        return "";
    }


    asg::Node operator()(const boost::variant<monostate, boost::recursive_wrapper<ast::InitlistNode>, boost::recursive_wrapper<ast::ExprNode>>& node)
    {
        return boost::apply_visitor(*this, node);
    }

    asg::Node operator()(const ast::ArglistNode& node);
    asg::Node operator()(const ast::AssignNode& node);
    asg::Node operator()(const ast::AssignopNode& node);
    asg::Node operator()(const ast::BitopNode& node);
    asg::Node operator()(const ast::BitsNode& node);
    asg::Node operator()(const ast::BreakNode& node);
    asg::Node operator()(const ast::CaseNode& node);
    asg::Node operator()(const ast::CastNode& node);
    asg::Node operator()(const ast::ClassNode& node);
    asg::Node operator()(const ast::CompopNode& node);
    asg::Node operator()(const ast::ConditionNode& node);
    asg::Node operator()(const ast::ConstructcallNode& node);
    asg::Node operator()(const ast::ContinueNode& node);
    asg::Node operator()(const ast::DatatypeNode& node);
    asg::Node operator()(const ast::DowhileNode& node);
    asg::Node operator()(const ast::EnumNode& node);
    asg::Node operator()(const ast::ExprNode& node);
    asg::Node operator()(const ast::ExpropNode& node);
    asg::Node operator()(const ast::ExprpostopNode& node);
    asg::Node operator()(const ast::ExprpreopNode& node);
    asg::Node operator()(const ast::ExprstatNode& node);
    asg::Node operator()(const ast::ExprtermNode& node);
    asg::Node operator()(const ast::ExprvalueNode& node);
    asg::Node operator()(const ast::ForNode& node);
    asg::Node operator()(const ast::FuncNode& node);
    asg::Node operator()(const ast::FuncattrNode& node);
    asg::Node operator()(const ast::FunccallNode& node);
    asg::Node operator()(const ast::FuncdefNode& node);
    asg::Node operator()(const ast::IdentifierNode& node);
    asg::Node operator()(const ast::IfNode& node);
    asg::Node operator()(const ast::ImportNode& node);
    asg::Node operator()(const ast::InitlistNode& node);
    asg::Node operator()(const ast::InterfaceNode& node);
    asg::Node operator()(const ast::IntfmthdNode& node);
    asg::Node operator()(const ast::LambdaNode& node);
    asg::Node operator()(const ast::LiteralNode& node);
    asg::Node operator()(const ast::LogicopNode& node);
    asg::Node operator()(const ast::MathopNode& node);
    asg::Node operator()(const ast::MixinNode& node);
    asg::Node operator()(const ast::NamespaceNode& node);
    asg::Node operator()(const ast::NumberNode& node);
    asg::Node operator()(const ast::ParamlistNode& node);
    asg::Node operator()(const ast::PrimtypeNode& node);
    asg::Node operator()(const ast::ReturnNode& node);
    asg::Node operator()(const ast::ScopeNode& node);
    asg::Node operator()(const ast::ScriptNode& node);
    asg::Node operator()(const ast::StatblockNode& node);
    asg::Node operator()(const ast::StatementNode& node);
    asg::Node operator()(const ast::StringNode& node);
    asg::Node operator()(const ast::SwitchNode& node);
    asg::Node operator()(const ast::TryNode& node);
    asg::Node operator()(const ast::TypeNode& node);
    asg::Node operator()(const ast::TypedefNode& node);
    asg::Node operator()(const ast::TypemodNode& node);
    asg::Node operator()(const ast::VarNode& node);
    asg::Node operator()(const ast::VaraccessNode& node);
    asg::Node operator()(const ast::VirtpropNode& node);
    asg::Node operator()(const ast::WhileNode& node);

private:
    Context* context_;
    Scope* scope_;
    SymbolTable* symbolTable_;

    boost::variant<asg::Initlist, boost::recursive_wrapper<asg::Expression>, asg::Constructcall> resolve(const ast::InitListOrExprOrArgListType& initListOrExprOrArgList);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_ANALYZERVISITOR_HPP
