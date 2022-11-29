#ifndef ICE_SCRIPT_ANALYZER_LITERALNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_LITERALNODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/NumberNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StringNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/BitsNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using LiteralNodeVisitorResultType = boost::variant<
        asg::Number,
        asg::String,
        asg::Bits,
        ast::Boolean,
        ast::Null
>;

class LiteralNodeVisitor : public AbstractVisitor<LiteralNodeVisitor, LiteralNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    LiteralNodeVisitorResultType operator()(const ast::NumberNode& node)
    {
        return process(*context_, node);
    }

    LiteralNodeVisitorResultType operator()(const ast::StringNode& node)
    {
        return process(*context_, node);
    }

    LiteralNodeVisitorResultType operator()(const ast::BitsNode& node)
    {
        return process(*context_, node);
    }

    LiteralNodeVisitorResultType operator()(const ast::BoolNode& node)
    {
        return node.value;
    }

    LiteralNodeVisitorResultType operator()(const ast::NullNode& node)
    {
        return node.value;
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_LITERALNODEVISITOR_HPP
