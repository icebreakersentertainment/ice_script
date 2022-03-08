#ifndef ICE_SCRIPT_ANALYZER_EXPRNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_EXPRNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ExprNodeVisitorResultType = boost::variant<
            asg::Expressionterm,
    asg::Expressionoperatorerty
>;

class ExprNodeVisitor : public AbstractVisitor<ExprNodeVisitor, ExprNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        ExprNodeVisitorResultType operator()(const ast::ExprtermNode& node);
    ExprNodeVisitorResultType operator()(const ast::ExpropNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_EXPRNODEVISITOR_HPP
