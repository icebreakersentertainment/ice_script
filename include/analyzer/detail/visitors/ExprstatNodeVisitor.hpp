#ifndef ICE_SCRIPT_ANALYZER_EXPRSTATNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_EXPRSTATNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ExprstatNodeVisitorResultType = boost::variant<
            asg::Assign
>;

class ExprstatNodeVisitor : public AbstractVisitor<ExprstatNodeVisitor, ExprstatNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        ExprstatNodeVisitorResultType operator()(const ast::AssignNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_EXPRSTATNODEVISITOR_HPP
