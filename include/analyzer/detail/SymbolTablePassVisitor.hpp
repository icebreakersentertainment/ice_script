#ifndef ICE_SCRIPT_SYMBOLTABLEPASSVISITOR_HPP
#define ICE_SCRIPT_SYMBOLTABLEPASSVISITOR_HPP

#include <string>

#include "analyzer/detail/Context.hpp"
#include "ast/Ast.hpp"
#include "ast/Root.hpp"
#include "ast/ScriptNode.hpp"
#include "ast/FuncattrNode.hpp"
#include "ast/TypedefNode.hpp"
#include "ast/TypeNode.hpp"
#include "ast/LiteralNode.hpp"
#include "ast/ExpropNode.hpp"
#include "ast/DatatypeNode.hpp"

#include "symbol/ClassSymbol.hpp"
#include "symbol/SymbolTable.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

class SymbolTablePassContext : public Context
{
public:
    using Context::Context;

    std::shared_ptr<FunctionSymbol> functionSymbol()
    {
        return functionSymbol_;
    }

    std::shared_ptr<ClassSymbol> classSymbol()
    {
        return classSymbol_;
    }

    void set(std::shared_ptr<FunctionSymbol> functionSymbol)
    {
        functionSymbol_ = std::move(functionSymbol);
    }

    void set(std::shared_ptr<ClassSymbol> classSymbol)
    {
        classSymbol_ = std::move(classSymbol);
    }

protected:
    std::shared_ptr<ClassSymbol> classSymbol_;
    std::shared_ptr<FunctionSymbol> functionSymbol_;
};

class SymbolTablePassVisitor : public AbstractVisitor<SymbolTablePassVisitor, void>
{
public:
    SymbolTablePassVisitor(logger::ILogger& logger, TypeTable& typeTable, SymbolTable& symbolTable) : AbstractVisitor(), logger_(&logger), typeTable_(&typeTable), symbolTable_(&symbolTable)
    {
        context_ = std::make_unique<SymbolTablePassContext>(logger, typeTable);
    }

    using AbstractVisitor::operator();

    void operator()(const std::string& string) const
    {
        LOG_DEBUG(logger_, "Analyzing %s", typeid(string).name())
    }

    void operator()(const ast::Ast& ast) const;
    void operator()(const ast::Root& node) const;
    void operator()(const ast::ScriptNode& node) const;
    void operator()(const ast::ClassNode& node) const;
    void operator()(const ast::TypedefNode& node) const;
    void operator()(const ast::NamespaceNode& node) const;
    void operator()(const ast::FuncNode& node) const;
    void operator()(const ast::InterfaceNode& node) const;
    void operator()(const ast::VarNode& node) const;
    void operator()(const ast::ImportNode& node) const;
    void operator()(const ast::EnumNode& node) const;
    void operator()(const ast::FuncdefNode& node) const;
    void operator()(const ast::VirtpropNode& node) const;
    void operator()(const ast::MixinNode& node) const;
    void operator()(const ast::IntfmthdNode& node) const;
    void operator()(const ast::StatblockNode& node) const;
    void operator()(const ast::ParamlistNode& node) const;
    void operator()(const ast::TypemodNode& node) const;
    void operator()(const ast::TypeNode& node) const;
    void operator()(const ast::InitlistNode& node) const;
    void operator()(const ast::ScopeNode& node) const;
    void operator()(const ast::DatatypeNode& node) const;
    void operator()(const ast::PrimtypeNode& node) const;
    void operator()(const ast::FuncattrNode& node) const;
    void operator()(const ast::StatementNode& node) const;
    void operator()(const ast::SwitchNode& node) const;
    void operator()(const ast::BreakNode& node) const;
    void operator()(const ast::ForNode& node) const;
    void operator()(const ast::WhileNode& node) const;
    void operator()(const ast::DowhileNode& node) const;
    void operator()(const ast::IfNode& node) const;
    void operator()(const ast::ContinueNode& node) const;
    void operator()(const ast::ExprstatNode& node) const;
    void operator()(const ast::TryNode& node) const;
    void operator()(const ast::ReturnNode& node) const;
    void operator()(const ast::CaseNode& node) const;
    void operator()(const ast::ExprNode& node) const;
    void operator()(const ast::ExprtermNode& node) const;
    void operator()(const ast::ExprvalueNode& node) const;
    void operator()(const ast::ConstructcallNode& node) const;
    void operator()(const ast::ExprpreopNode& node) const;
    void operator()(const ast::ExprpostopNode& node) const;
    void operator()(const ast::CastNode& node) const;
    void operator()(const ast::LambdaNode& node) const;
    void operator()(const ast::LiteralNode& node) const;
    void operator()(const ast::FunccallNode& node) const;
    void operator()(const ast::VaraccessNode& node) const;
    void operator()(const ast::ArglistNode& node) const;
    void operator()(const ast::AssignNode& node) const;
    void operator()(const ast::ConditionNode& node) const;
    void operator()(const ast::ExpropNode& node) const;
    void operator()(const ast::BitopNode& node) const;
    void operator()(const ast::MathopNode& node) const;
    void operator()(const ast::CompopNode& node) const;
    void operator()(const ast::LogicopNode& node) const;
    void operator()(const ast::AssignopNode& node) const;
    void operator()(const ast::IdentifierNode& node) const;
    void operator()(const ast::NumberNode& node) const;
    void operator()(const ast::StringNode& node) const;
    void operator()(const ast::BitsNode& node) const;
    void operator()(const ast::BoolNode& node) const;
    void operator()(const ast::NullNode& node) const;
    void operator()(const ast::VoidNode& node) const;

    // TODO
    // void operator()(const ast::OptionalIdentifierAssignVectorTupleOptionalIdentifierAssignType& node) const;
    // TODO
    void operator()(const boost::recursive_wrapper<ast::AssignNode>& node) const;
    // TODO
    void operator()(const ast::PostfixOperator& node) const;
    // TODO
    void operator()(const ast::TupleTypeOptionalStringType& node) const;

private:
    logger::ILogger* logger_;
    std::unique_ptr<SymbolTablePassContext> context_;
    TypeTable* typeTable_;
    SymbolTable* symbolTable_;
};

}}}

#endif //ICE_SCRIPT_SYMBOLTABLEPASSVISITOR_HPP
