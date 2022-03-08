#ifndef ICE_SCRIPT_ANALYZER_LITERALNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_LITERALNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

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

    LiteralNodeVisitorResultType operator()(const ast::NumberNode& node);
    LiteralNodeVisitorResultType operator()(const ast::StringNode& node);
    LiteralNodeVisitorResultType operator()(const ast::BitsNode& node);
    LiteralNodeVisitorResultType operator()(const ast::BoolNode& node);
    LiteralNodeVisitorResultType operator()(const ast::NullNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_LITERALNODEVISITOR_HPP
