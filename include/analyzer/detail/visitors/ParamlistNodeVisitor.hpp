#ifndef ICE_SCRIPT_ANALYZER_PARAMLISTNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_PARAMLISTNODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/TypeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/TypemodNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ParamlistNodeVisitorResultType = boost::variant<
        Type,
        Typemodifier,
        asg::Identifier,
        asg::Expression
>;

class ParamlistNodeVisitor : public AbstractVisitor<ParamlistNodeVisitor, ParamlistNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    ParamlistNodeVisitorResultType operator()(const ast::TypeNode& node)
    {
        return process(*context_, node);
    }

    ParamlistNodeVisitorResultType operator()(const ast::TypemodNode& node)
    {
        return process(*context_, node);
    }

    ParamlistNodeVisitorResultType operator()(const ast::IdentifierNode& node)
    {
        return process(*context_, node);
    }

    ParamlistNodeVisitorResultType operator()(const ast::ExprNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_PARAMLISTNODEVISITOR_HPP
