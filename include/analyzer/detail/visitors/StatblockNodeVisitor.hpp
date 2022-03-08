#ifndef ICE_SCRIPT_ANALYZER_STATBLOCKNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_STATBLOCKNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using StatblockNodeVisitorResultType = boost::variant<
            asg::Variable,
    asg::Statement
>;

class StatblockNodeVisitor : public AbstractVisitor<StatblockNodeVisitor, StatblockNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        StatblockNodeVisitorResultType operator()(const ast::VarNode& node);
    StatblockNodeVisitorResultType operator()(const ast::StatementNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_STATBLOCKNODEVISITOR_HPP
