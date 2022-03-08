#ifndef ICE_SCRIPT_ANALYZER_EXPRPOSTOPNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_EXPRPOSTOPNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ExprpostopNodeVisitorResultType = boost::variant<
            asg::Functioncall,
    asg::Identifier,
    asg::Assign,
    asg::Arglist
>;

class ExprpostopNodeVisitor : public AbstractVisitor<ExprpostopNodeVisitor, ExprpostopNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        ExprpostopNodeVisitorResultType operator()(const ast::FunccallNode& node);
    ExprpostopNodeVisitorResultType operator()(const ast::IdentifierNode& node);
    ExprpostopNodeVisitorResultType operator()(const ast::AssignNode& node);
    ExprpostopNodeVisitorResultType operator()(const ast::ArglistNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_EXPRPOSTOPNODEVISITOR_HPP
