#ifndef ICE_SCRIPT_ANALYZER_ASSIGNNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_ASSIGNNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using AssignNodeVisitorResultType = boost::variant<
            asg::Condition,
    asg::Assignoperator
>;

class AssignNodeVisitor : public AbstractVisitor<AssignNodeVisitor, AssignNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        AssignNodeVisitorResultType operator()(const ast::ConditionNode& node);
    AssignNodeVisitorResultType operator()(const ast::AssignopNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_ASSIGNNODEVISITOR_HPP
