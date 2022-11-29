#ifndef ICE_SCRIPT_ANALYZER_SWITCHNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_SWITCHNODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/CaseNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using SwitchNodeVisitorResultType = boost::variant<
        asg::Assign,
        asg::Case
>;

class SwitchNodeVisitor : public AbstractVisitor<SwitchNodeVisitor, SwitchNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    SwitchNodeVisitorResultType operator()(const ast::AssignNode& node)
    {
        return process(*context_, node);
    }

    SwitchNodeVisitorResultType operator()(const ast::CaseNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_SWITCHNODEVISITOR_HPP
