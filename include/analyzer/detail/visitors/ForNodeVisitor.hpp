#ifndef ICE_SCRIPT_ANALYZER_FORNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_FORNODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/VarNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprstatNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StatementNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ForNodeVisitorResultType = boost::variant<
        asg::Variable,
        asg::Expressionstat
>;

class ForNodeVisitor : public AbstractVisitor<ForNodeVisitor, ForNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    ForNodeVisitorResultType operator()(const ast::VarNode& node)
    {
        return process(*context_, node);
    }

    ForNodeVisitorResultType operator()(const ast::ExprstatNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_FORNODEVISITOR_HPP
