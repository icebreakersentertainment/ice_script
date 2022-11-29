#include "analyzer/detail/analyzers/ExprvalueNodeAnalyzer.hpp"

#include "analyzer/detail/visitors/ExprvalueNodeVisitor.hpp"

//#include "analyzer/detail/TypeResolver.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;
//
//class DisambiguatorVisitor : public AbstractVisitor<DisambiguatorVisitor, ExprvalueNodeValueType>
//{
//public:
//    using AbstractVisitor::AbstractVisitor;
//
//    using AbstractVisitor::operator();
//
//    ExprvalueNodeValueType operator()(const ast::VoidNode& node) { return node; }
//
//    ExprvalueNodeValueType operator()(const ast::ConstructcallNode& node)
//    {
//        std::shared_ptr<Type> type = resolve(*logger_, *context_, node.typeNode.get());
//
//        if (type->typeId() == Type::TypeId::FUNCTION)
//        {
//
//        }
//
//        return node;
//    }
//
//    ExprvalueNodeValueType operator()(const ast::FunccallNode& node)
//    {
//        return node;
//    }
//
//    ExprvalueNodeValueType operator()(const ast::VaraccessNode& node) { return node; }
//    ExprvalueNodeValueType operator()(const ast::CastNode& node) { return node; }
//    ExprvalueNodeValueType operator()(const ast::LiteralNode& node) { return node; }
//    ExprvalueNodeValueType operator()(const ast::AssignNode& node) { return node; }
//    ExprvalueNodeValueType operator()(const ast::LambdaNode& node) { return node; }
//};

asg::Expressionvalue process(Context& context, const ast::ExprvalueNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Expressionvalue expressionvalue{};

//    DisambiguatorVisitor disambiguatorVisitor{context};
//    auto value = boost::apply_visitor(disambiguatorVisitor, node.value);

    ExprvalueNodeVisitor visitor{context};
    expressionvalue.value = boost::apply_visitor(visitor, node.value);

    if (expressionvalue.value.which() == 2)
    {
        auto v = boost::get<Functioncall>(expressionvalue.value);

    }

    return expressionvalue;
}

}}}