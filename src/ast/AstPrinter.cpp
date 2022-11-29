#include "ast/AstPrinter.hpp"
#include <string>

// Adapted from: https://stackoverflow.com/a/45677131
template<int N, typename... Ts> using NthTypeOf = typename std::tuple_element<N, std::tuple<Ts...>>::type;

template<int N, typename... Ts>
auto& get(boost::variant<Ts...>& v)
{
    using target = NthTypeOf<N, Ts...>;
    return boost::get<target>(v);
}

template<int N, typename... Ts>
auto& get(const boost::variant<Ts...>& v)
{
    using target = NthTypeOf<N, Ts...>;
    return boost::get<target>(v);
}

namespace ice_script { namespace ast {

void AstPrinter::operator()(const Ast& ast) const
{
    operator()(ast.root);
}

void AstPrinter::operator()(const Root& node) const
{
    printBasic(node);

    operator()(node.scriptNode);
}

void AstPrinter::operator()(const ScriptNode& node) const
{
    printBasic(node);

    for (const auto& _node: node.value)
    {
//            tab(indent+tabsize);
//            operator()(_node);
        boost::apply_visitor(AstPrinter(os_, printLocationInfo_, indent_ + TAB_SIZE), _node);
    }
//        tab(indent);
}

void AstPrinter::operator()(const ClassNode& node) const
{
    printBasic(node);

    AstPrinter astPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

    for (const auto& type : node.type)
    {
        os_ << "[" << type << "]" << std::endl;
    }

    astPrinter.operator()(node.identifierNode);

    if (node.value)
    {
        if (node.value.get().extendsAndImplements)
        {
            for (const auto& extendsAndImplements: node.value.get().extendsAndImplements.get())
            {
                astPrinter.operator()(extendsAndImplements);
            }
        }

        for (const auto& virtualPropertyFunctionVariableFunctionDefinition : node.value.get().virtualPropertyFunctionVariableFunctionDefinitions)
        {
            boost::apply_visitor(astPrinter, virtualPropertyFunctionVariableFunctionDefinition);
        }
    }
}

void AstPrinter::operator()(const TypedefNode& node) const
{
    printBasic(node);

    tab(TAB_SIZE);
    operator()(node.primTypeNode);
    tab(TAB_SIZE);
    operator()(node.identifierNode);
}

void AstPrinter::operator()(const NamespaceNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const FuncNode& node) const
{
    printBasic(node);

    tab(TAB_SIZE);
    operator()(node.identifierNode);

    if (node.optionalStatblockNode)
    {
        AstPrinter astPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

        astPrinter.operator()(node.optionalStatblockNode.get());
    }
}

void AstPrinter::operator()(const InterfaceNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const VarNode& node) const
{
    printBasic(node);

    AstPrinter astPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

    astPrinter.operator()(node.identifierNode);
    astPrinter.operator()(node.typeNode);

    if (node.initListOrExprOrArgList)
    {
        boost::apply_visitor(astPrinter, node.initListOrExprOrArgList.get());

//        if (node.initListOrExprOrArgList.get().which() == 0)
//        {
//            const auto& v = get<0>(node.initListOrExprOrArgList.get());
//
//            boost::apply_visitor(AstPrinter(os_, printLocationInfo_, indent_ + TAB_SIZE), v);
//        }
//        else
//        {
////            operator()(get<1>(node.initListOrExprOrArgList.get()));
//        }
    }
}

void AstPrinter::operator()(const ImportNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const EnumNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const FuncdefNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const VirtpropNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const MixinNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const IntfmthdNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const StatblockNode& node) const
{
    printBasic(node);

    for (const auto& v : node.value)
    {
        boost::apply_visitor(AstPrinter(os_, printLocationInfo_, indent_ + TAB_SIZE), v);
    }
}

void AstPrinter::operator()(const ParamlistNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const TypemodNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const TypeNode& node) const
{
    printBasic(node, false);
    
    std::string typeQualifiers{};
    for (size_t i = 0; i < node.typeQualifiers.size(); ++i)
    {
        typeQualifiers += (i > 0 ? " " : "") + toString(node.typeQualifiers[i]);
    }
    
    std::string array{};
    for (const auto& optionalArray : node.array)
    {
        array += "[" + (optionalArray ? std::to_string(optionalArray.get()) : "") + "]";
    }
    
    const auto typeModifier = node.typeModifier ? toString(node.typeModifier.get()) : "";
    
    os_ << "[" << typeQualifiers << array << typeModifier << "]" << std::endl;

    AstPrinter astPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

    // isConst
    astPrinter.operator()(node.scopeNode);
    astPrinter.operator()(node.datatypeNode);
    // templates

//        boost::apply_visitor(AstPrinter(os_, printLocationInfo_, indent_+TAB_SIZE), node.value);
}

void AstPrinter::operator()(const InitlistNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const ScopeNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const DatatypeNode& node) const
{
    printBasic(node);

    boost::apply_visitor(AstPrinter(os_, printLocationInfo_, indent_ + TAB_SIZE), node.value);
}

void AstPrinter::operator()(const PrimtypeNode& node) const
{
    printBasic(node, false);

    os_ << "[" << toString(node.primitiveType) << "]" << std::endl;
}

void AstPrinter::operator()(const FuncattrNode& node) const
{
    printBasic(node);

    tab(TAB_SIZE);
    os_ << node.value.size() << " ";
    for (const auto& e: node.value)
    {
        os_ << e << " ";
    }
    os_ << std::endl;

//        operator()(node.isRef);
//
//        if (node.inout)
//        {
//            tab(TAB_SIZE);
//            operator()(node.inout.get());
//        }
}

void AstPrinter::operator()(const StatementNode& node) const
{
    printBasic(node);

    boost::apply_visitor(AstPrinter(os_, printLocationInfo_, indent_ + TAB_SIZE), node.value);
}

void AstPrinter::operator()(const SwitchNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const BreakNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const ForNode& node) const
{
    printBasic(node);

    AstPrinter astPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

    boost::apply_visitor(astPrinter, node.varOrExprstatNode);

    astPrinter.operator()(node.exprstatNode.get());

    for (const auto& assignNode : node.assignNodes)
    {
        astPrinter.operator()(assignNode.get());
    }

    astPrinter.operator()(node.statementNode.get());
}

void AstPrinter::operator()(const WhileNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const DowhileNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const IfNode& node) const
{
    printBasic(node);

    AstPrinter astPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

    astPrinter.operator()(node.assignNode.get());
    astPrinter.operator()(node.statementNode.get());

    if (node.optionalStatementNode)
    {
        astPrinter.operator()(node.optionalStatementNode.get().get());
    }
}

void AstPrinter::operator()(const ContinueNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const ExprstatNode& node) const
{
    printBasic(node);

    if (node.value)
    {
        AstPrinter astPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

        astPrinter.operator()(node.value.get());
    }
}

void AstPrinter::operator()(const TryNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const ReturnNode& node) const
{
    printBasic(node);

    if (node.value)
    {
        AstPrinter astPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

        astPrinter.operator()(node.value.get());
    }
}

void AstPrinter::operator()(const CaseNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const ExprNode& node) const
{
    printBasic(node);

    AstPrinter astPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

    astPrinter.operator()(node.exprtermNode.get());

    for (const auto& expropNodeAndExprtermNode : node.expropNodeAndExprtermNodes)
    {
        astPrinter.operator()(expropNodeAndExprtermNode.expropNode);
        astPrinter.operator()(expropNodeAndExprtermNode.exprtermNode);
    }
}

void AstPrinter::operator()(const ExprtermNode& node) const
{
    printBasic(node);

    if (node.value.which() == 2)
    {
        AstPrinter astPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

        const auto& exprpreopsExprvalueExprpostops = get<2>(node.value);

        const auto& exprPreopNodes = exprpreopsExprvalueExprpostops.exprPreopNodes;

        for (const auto& exprPreopNode : exprPreopNodes) astPrinter.operator()(exprPreopNode);

        const auto& exprValueNode = exprpreopsExprvalueExprpostops.exprValueNode;

        astPrinter.operator()(exprValueNode);

        const auto& exprPostopNodes = exprpreopsExprvalueExprpostops.exprPostopNodes;

        for (const auto& exprPostopNode : exprPostopNodes) astPrinter.operator()(exprPostopNode);
    }
}

void AstPrinter::operator()(const ExprvalueNode& node) const
{
    printBasic(node);

    boost::apply_visitor(AstPrinter(os_, printLocationInfo_, indent_ + TAB_SIZE), node.value);
}

void AstPrinter::operator()(const ConstructcallNode& node) const
{
    printBasic(node);

    AstPrinter astPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

    astPrinter.operator()(node.typeNode);
    astPrinter.operator()(node.arglistNode);
}

void AstPrinter::operator()(const ExprpreopNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const ExprpostopNode& node) const
{
    printBasic(node);

    boost::apply_visitor(AstPrinter(os_, printLocationInfo_, indent_ + TAB_SIZE), node.value);
}

void AstPrinter::operator()(const CastNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const LambdaNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const LiteralNode& node) const
{
    printBasic(node);

    boost::apply_visitor(AstPrinter(os_, printLocationInfo_, indent_ + TAB_SIZE), node.value);
}

void AstPrinter::operator()(const FunccallNode& node) const
{
    printBasic(node);

    AstPrinter astPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

    astPrinter.operator()(node.scopeNode);
    astPrinter.operator()(node.identifierNode);
    astPrinter.operator()(node.arglistNode);
}

void AstPrinter::operator()(const VaraccessNode& node) const
{
    printBasic(node);

    tab(TAB_SIZE);
    operator()(node.identifierNode);
}

void AstPrinter::operator()(const ArglistNode& node) const
{
    printBasic(node);

    AstPrinter astPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

    for (const auto& argument : node.value)
    {
        astPrinter.operator()(argument.assignNode);
    }
}

void AstPrinter::operator()(const AssignNode& node) const
{
    printBasic(node);

    AstPrinter astPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

    astPrinter.operator()(node.conditionNode);

    if (node.assignopAssignNode)
    {
        astPrinter.operator()(node.assignopAssignNode.get().assignopNode);
        astPrinter.operator()(node.assignopAssignNode.get().assignNode);
    }
}

void AstPrinter::operator()(const ConditionNode& node) const
{
    printBasic(node);

    AstPrinter astPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

    astPrinter.operator()(node.exprNode);

    if (node.assignNode)
    {
        astPrinter.operator()(boost::get<0>(node.assignNode.get()));
        astPrinter.operator()(boost::get<1>(node.assignNode.get()));
    }
}

void AstPrinter::operator()(const ExpropNode& node) const
{
    printBasic(node);

    boost::apply_visitor(AstPrinter(os_, printLocationInfo_, indent_ + TAB_SIZE), node.value);
}

void AstPrinter::operator()(const BitopNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const MathopNode& node) const
{
    printBasic(node, false);

    os_ << "[" << toString(node.mathOperator) << "]" << std::endl;
}

void AstPrinter::operator()(const CompopNode& node) const
{
    printBasic(node, false);

    os_ << "[" << toString(node.comparisonOperator) << "]" << std::endl;
}

void AstPrinter::operator()(const LogicopNode& node) const
{
    printBasic(node, false);

    os_ << "[" << toString(node.logicOperator) << "]" << std::endl;
}

void AstPrinter::operator()(const AssignopNode& node) const
{
    printBasic(node, false);

    os_ << "[" << toString(node.assignOperator) << "]" << std::endl;
}

void AstPrinter::operator()(const IdentifierNode& node) const
{
    printBasic(node, false);

    os_ << "[" << node.value << "]" << std::endl;
}

void AstPrinter::operator()(const NumberNode& node) const
{
    printBasic(node, false);

    os_ << "[" << node.value << "]" << std::endl;
}

void AstPrinter::operator()(const StringNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const BitsNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const BoolNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const NullNode& node) const
{
    printBasic(node);
}

void AstPrinter::operator()(const VoidNode& node) const
{
    printBasic(node);
}

}}