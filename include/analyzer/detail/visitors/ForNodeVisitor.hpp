#ifndef ICE_SCRIPT_ANALYZER_FORNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_FORNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ForNodeVisitorResultType = boost::variant<
            asg::Variable,
    asg::Expressionstat,
    asg::Assign,
    asg::Statement
>;

class ForNodeVisitor : public AbstractVisitor<ForNodeVisitor, ForNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        ForNodeVisitorResultType operator()(const ast::VarNode& node);
    ForNodeVisitorResultType operator()(const ast::ExprstatNode& node);
    ForNodeVisitorResultType operator()(const ast::AssignNode& node);
    ForNodeVisitorResultType operator()(const ast::StatementNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_FORNODEVISITOR_HPP
