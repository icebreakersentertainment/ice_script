#ifndef ICE_SCRIPT_ANALYZER_INTFMTHDNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_INTFMTHDNODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/TypeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ParamlistNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using IntfmthdNodeVisitorResultType = boost::variant<
        Type,
        asg::Identifier,
        asg::Parameterlist
>;

class IntfmthdNodeVisitor : public AbstractVisitor<IntfmthdNodeVisitor, IntfmthdNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    IntfmthdNodeVisitorResultType operator()(const ast::TypeNode& node)
    {
        return process(*context_, node);
    }

    IntfmthdNodeVisitorResultType operator()(const ast::IdentifierNode& node)
    {
        return process(*context_, node);
    }

    IntfmthdNodeVisitorResultType operator()(const ast::ParamlistNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_INTFMTHDNODEVISITOR_HPP
