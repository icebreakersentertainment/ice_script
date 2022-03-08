#include "analyzer/detail/analyzers/VarNodeAnalyzer.hpp"

#include "analyzer/detail/visitors/VarNodeVisitor.hpp"

#include "analyzer/detail/TypeResolver.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

using TestVisitorResultType = boost::variant<
        asg::Initlist,
        asg::Expression,
        asg::Arglist
>;

class TestVisitor : public AbstractVisitor<TestVisitor, TestVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    VarNodeVisitorResultType operator()(const ast::InitlistNode& node)
    {

    }

    VarNodeVisitorResultType operator()(const ast::ExprNode& node)
    {

    }

    VarNodeVisitorResultType operator()(const ast::ArglistNode& node)
    {

    }
};

asg::Variable process(logger::ILogger& logger, Context& context, const ast::VarNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    std::shared_ptr<Type> type = resolve(logger, context, node.typeNode.get());

    const auto variableName = toName(node.identifierNode.get().value);

    std::shared_ptr<Symbol> symbol = scope.symbolTable().find(variableName);

//        if (symbol) throw DuplicateSymbolException(symbol);
    if (symbol) throw DuplicateSymbolException();
//        if (symbol) throw RedeclarationException(symbol);

    symbol = scope.symbolTable().create(variableName);
    symbol->setType(type);

    scope.pushExpectedTypes({type});

    Variable variable{};

//        if (node.visibility && scope.type() != ScopeType::CLASS)
//        {
//            throw IllegalStartOfExpressionException(node);
//        }

//        variable.visibility = node.visibility ? node.visibility.get() : ast::Visibility::PUBLIC;

    variable.type = type;
    variable.name = variableName;

    if (node.initListOrExprOrArgList)
    {
        VarNodeVisitor visitor{logger, context};
        variable.value = boost::apply_visitor(visitor, node.initListOrExprOrArgList.get());
    }

    scope.popExpectedTypes();

    return variable;
}

}}}