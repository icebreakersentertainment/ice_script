#ifndef ICE_SCRIPT_ANALYZER_EXPRTERMNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_EXPRTERMNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ExprtermNodeVisitorResultType = boost::variant<
            asg::Type,
    asg::Initlist,
    asg::Expressionpreoperator,
    asg::Expressionvalue,
    asg::Expressionpostoperator
>;

class ExprtermNodeVisitor : public AbstractVisitor<ExprtermNodeVisitor, ExprtermNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        ExprtermNodeVisitorResultType operator()(const ast::TypeNode& node);
    ExprtermNodeVisitorResultType operator()(const ast::InitlistNode& node);
    ExprtermNodeVisitorResultType operator()(const ast::ExprpreopNode& node);
    ExprtermNodeVisitorResultType operator()(const ast::ExprvalueNode& node);
    ExprtermNodeVisitorResultType operator()(const ast::ExprpostopNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_EXPRTERMNODEVISITOR_HPP
