#ifndef ICE_SCRIPT_ANALYZER_CASENODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_CASENODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using CaseNodeVisitorResultType = boost::variant<
            asg::Expression,
    asg::Statement
>;

class CaseNodeVisitor : public AbstractVisitor<CaseNodeVisitor, CaseNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        CaseNodeVisitorResultType operator()(const ast::ExprNode& node);
    CaseNodeVisitorResultType operator()(const ast::StatementNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_CASENODEVISITOR_HPP
