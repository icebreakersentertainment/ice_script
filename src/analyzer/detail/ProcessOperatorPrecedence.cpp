#include <stack>
#include <queue>

#include <boost/hana.hpp>

#include "analyzer/detail/ProcessOperatorPrecedence.hpp"

#include "ast/AstPrinter.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "detail/monostate.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;

//class OperatorPrecedenceVisitor : public AbstractVisitor<OperatorPrecedenceVisitor, void>
//{
//public:
//    using AbstractVisitor::AbstractVisitor;
//
//    using AbstractVisitor::operator();
//
//    void operator()(const ast::ImportNode& node);
//    void operator()(const ast::EnumNode& node);
//    void operator()(const ast::TypedefNode& node);
//    void operator()(const ast::ClassNode& node);
//    void operator()(const ast::MixinNode& node);
//    void operator()(const ast::InterfaceNode& node);
//    void operator()(const ast::FuncdefNode& node);
//    void operator()(const ast::VirtpropNode& node);
//    void operator()(const ast::VarNode& node);
//    void operator()(const ast::FuncNode& node);
//    void operator()(const ast::NamespaceNode& node);
//    void operator()(const std::string& node);
//
//    void operator()(const ast::ExprNode& node)
//    {
//        if (node.expropNodeAndExprtermNodes.size() < 2) return;
//
//        std::stack<ExpropNode> operatorStack{};
//        std::queue<Token> outputQueue{};
//
//        outputQueue.push(node.exprtermNode.get());
//
////        while (!tokens_.empty())
//        for (auto& expropAndExprtermNode : node.expropNodeAndExprtermNodes)
//        {
//            auto& expropNode = expropAndExprtermNode.expropNode.get();
//            auto& exprtermNode = expropAndExprtermNode.exprtermNode.get();
//
//            if (!operatorStack.empty())
//            {
//                ExpropNode* processedOperator = &operatorStack.top();
//
//                while (processedOperator && precedence(*processedOperator) > precedence(_operator))
//                {
//                    processedOperator = nullptr;
//                    outputQueue.push(operatorStack.top());
//
//                    operatorStack.pop();
//
//                    if (!operatorStack.empty()) processedOperator = &operatorStack.top();
//                }
//            }
//
//            operatorStack.push(expropNode);
//
//            outputQueue.push(exprtermNode);
//        }
//
//        while (!operatorStack.empty())
//        {
//            outputQueue.push(operatorStack.top());
//
//            operatorStack.pop();
//        }
//
//
//        while (!outputQueue.empty())
//        {
//
//        }
//    }
//};

class OperatorPrecedenceVisitor : public AbstractVisitor<OperatorPrecedenceVisitor, int>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    int operator()(const BitopNode& node) const
    {
        switch (node.bitwiseOperator)
        {
            case BitwiseOperator::COMPLEMENT: return 30;
            case BitwiseOperator::LEFT_SHIFT: return 70;
            case BitwiseOperator::RIGHT_SHIFT: return 70;
            case BitwiseOperator::ARITHMETIC_RIGHT_SHIFT: return 70; // Do we care to implement this?
            case BitwiseOperator::AND: return 110;
            case BitwiseOperator::XOR: return 120;
            case BitwiseOperator::OR: return 130;

            default:
                throw InvalidArgumentException("Bitwise operator not valid.");
        }
    }

    int operator()(const MathopNode& node) const
    {
        switch (node.mathOperator)
        {
            case MathOperator::MULTIPLY: return 50;
            case MathOperator::DIVIDE: return 50;
            case MathOperator::MODULOS: return 50;
            case MathOperator::EXPONENT: return 50; // Do we care to implement this?
            case MathOperator::ADD: return 60;
            case MathOperator::SUBTRACT: return 60;

            default:
                throw InvalidArgumentException("Math operator not valid.");
        }
    }

    int operator()(const CompopNode& node) const
    {
        switch (node.comparisonOperator)
        {
            case ComparisonOperator::LESS_THAN: return 90;
            case ComparisonOperator::LESS_THAN_OR_EQUALS: return 90;
            case ComparisonOperator::GREATER_THAN: return 90;
            case ComparisonOperator::GREATER_THAN_OR_EQUALS: return 90;
            case ComparisonOperator::EQUALS: return 100;
            case ComparisonOperator::NOT_EQUALS: return 100;
            case ComparisonOperator::IS: return 100; // Do we care to implement this?
            case ComparisonOperator::IS_NOT: return 100; // Do we care to implement this?

            default:
                throw InvalidArgumentException("Comparison operator not valid.");
        }
    }

    int operator()(const LogicopNode& node) const
    {
        switch (node.logicOperator)
        {
            case LogicOperator::NOT: return 30;
            case LogicOperator::AND: return 140;
            case LogicOperator::OR: return 150;
            case LogicOperator::XOR: return 150; // Do we care to implement this?

            default:
                throw InvalidArgumentException("Comparison operator not valid.");
        }
    }
};

int precedence(Context& context, const ExpropNode& node)
{
    return boost::apply_visitor(OperatorPrecedenceVisitor(context), node.value);
}

using Token = boost::variant<monostate, ExprNode, ExprtermNode, ExpropNode>;

ExprtermNode toExprterm(boost::variant<monostate, ExprNode, ExprtermNode>& variant)
{
    if (variant.which() == 1) return boost::get<ExprtermNode>(variant);

    ConditionNode condition{};
    condition.exprNode = boost::get<ExprNode>(variant);
    condition.column = condition.exprNode.get().column;
    condition.length = condition.exprNode.get().length;
    condition.line = condition.exprNode.get().line;

    AssignNode assign{};
    assign.conditionNode = condition;
    assign.column = condition.exprNode.get().column;
    assign.length = condition.exprNode.get().length;
    assign.line = condition.exprNode.get().line;

    ExprvalueNode exprvalue{};
    exprvalue.value = assign;
    exprvalue.column = condition.exprNode.get().column;
    exprvalue.length = condition.exprNode.get().length;
    exprvalue.line = condition.exprNode.get().line;

    ExprtermNode exprterm{};
    ExprpreopsExprvalueExprpostops a{};
    a.exprValueNode = exprvalue;
    exprterm.value = a;
    exprterm.column = condition.exprNode.get().column;
    exprterm.length = condition.exprNode.get().length;
    exprterm.line = condition.exprNode.get().line;

    return exprterm;
}

ast::ExprNode transformBasedOnOperatorPrecedence(Context& context, const ast::ExprNode& node)
{
    if (node.expropNodeAndExprtermNodes.size() < 2) return node;

    std::stack<ExpropNode> operatorStack{};
    std::queue<Token> outputQueue{};

//    ast::AstPrinter printer{std::cout, true};
//    printer(node.exprtermNode.get());
    outputQueue.push(node.exprtermNode.get());

//        while (!tokens_.empty())
    for (auto& expropAndExprtermNode : node.expropNodeAndExprtermNodes)
    {
        auto& expropNode = expropAndExprtermNode.expropNode.get();
        auto& exprtermNode = expropAndExprtermNode.exprtermNode.get();

//        printer(expropNode);
//        printer(exprtermNode);

        if (!operatorStack.empty())
        {
            ExpropNode* processedOperator = &operatorStack.top();

            auto a = precedence(context, *processedOperator);
            auto b = precedence(context, expropNode);
//            while (processedOperator && precedence(context, *processedOperator) > precedence(context, expropNode))
            while (processedOperator && a < b)
            {
                processedOperator = nullptr;
                outputQueue.push(operatorStack.top());

                operatorStack.pop();

                if (!operatorStack.empty()) processedOperator = &operatorStack.top();
            }
        }

        operatorStack.push(expropNode);

        outputQueue.push(exprtermNode);
    }

    while (!operatorStack.empty())
    {
        outputQueue.push(operatorStack.top());

        operatorStack.pop();
    }

    std::stack<boost::variant<monostate, ExprNode, ExprtermNode>> outputStack{};
    ExprNode transformedNode{};

    while (!outputQueue.empty())
    {
        Token& token = outputQueue.front();

//        std::cout << "Token: " << std::endl;
//        ast::AstPrinter printer{std::cout, true};
//        printer(token);

        if (token.which() == 1)
        {
            ExprtermNode& exprtermNode = boost::get<ExprtermNode>(token);
            outputStack.push(exprtermNode);
        }
        else if (token.which() == 2)
        {
            ExpropNode& expropNode = boost::get<ExpropNode>(token);

            auto rhs = toExprterm(outputStack.top());
            outputStack.pop();
//            auto lhs = boost::get<ExprtermNode>(outputStack.top());
            auto lhs = toExprterm(outputStack.top());
            outputStack.pop();

//            if (rhs.which() == 0)
//            {
//                auto& rhsExprNode = boost::get<ExprNode>(rhs);
//
//                rhsExprNode.expropNodeAndExprtermNodes.insert(rhsExprNode.expropNodeAndExprtermNodes.begin(), {expropNode, rhsExprNode.exprtermNode});
////                rhsExprNode.expropNodeAndExprtermNodes.push_back({expropNode, rhsExprNode.exprtermNode});
//                rhsExprNode.exprtermNode = lhs;
//
//                outputStack.push(rhsExprNode);
//            }
//            else if (rhs.which() == 1)
//            {
//                auto& rhsExprtermNode = boost::get<ExprtermNode>(rhs);
//
//                ExprNode exprNode{};
//                exprNode.exprtermNode = lhs;
//                exprNode.expropNodeAndExprtermNodes = {{expropNode, rhsExprtermNode}};
//
//                outputStack.push(exprNode);
//            }

            ExprNode exprNode{};
            exprNode.exprtermNode = lhs;
            exprNode.expropNodeAndExprtermNodes = {{expropNode, rhs}};
            exprNode.column = exprNode.exprtermNode.get().column;
            exprNode.length = exprNode.exprtermNode.get().length;
            exprNode.line = exprNode.exprtermNode.get().line;

            outputStack.push(exprNode);
        }

        outputQueue.pop();
    }

    ICE_SCRIPT_ASSERT(outputStack.size() == 1)
    ICE_SCRIPT_ASSERT(outputStack.top().which() == 0)

//    auto& result = outputStack.top();
//
//    if (result.which() == 0)
//    {
//        return boost::get<ExprNode>(result);
//    }
//    else if (result.which() == 1)
//    {
//        auto& exprtermNode = boost::get<ExprtermNode>(result);
//
//
//    }

    return boost::get<ExprNode>(outputStack.top());
}

//void processOperatorPrecedence(Expression& expression)
//{
//
//}

}}}