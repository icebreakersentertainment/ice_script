#ifndef ICE_SCRIPT_ANALYZER_PARAMLISTNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_PARAMLISTNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ParamlistNodeVisitorResultType = boost::variant<
            asg::Type,
    asg::Typemodifier,
    asg::Identifier,
    asg::Expression
>;

class ParamlistNodeVisitor : public AbstractVisitor<ParamlistNodeVisitor, ParamlistNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        ParamlistNodeVisitorResultType operator()(const ast::TypeNode& node);
    ParamlistNodeVisitorResultType operator()(const ast::TypemodNode& node);
    ParamlistNodeVisitorResultType operator()(const ast::IdentifierNode& node);
    ParamlistNodeVisitorResultType operator()(const ast::ExprNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_PARAMLISTNODEVISITOR_HPP
