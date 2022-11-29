#ifndef ICE_SCRIPT_ANALYZER_LAMBDANODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_LAMBDANODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/TypeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/TypemodNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StatblockNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using LambdaNodeVisitorResultType = boost::variant<
        Type,
        Typemodifier,
        asg::Identifier,
        asg::Statblock
>;

class LambdaNodeVisitor : public AbstractVisitor<LambdaNodeVisitor, LambdaNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    LambdaNodeVisitorResultType operator()(const ast::TypeNode& node)
    {
        return process(*context_, node);
    }

    LambdaNodeVisitorResultType operator()(const ast::TypemodNode& node)
    {
        return process(*context_, node);
    }

    LambdaNodeVisitorResultType operator()(const ast::IdentifierNode& node)
    {
        return process(*context_, node);
    }

    LambdaNodeVisitorResultType operator()(const ast::StatblockNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_LAMBDANODEVISITOR_HPP
