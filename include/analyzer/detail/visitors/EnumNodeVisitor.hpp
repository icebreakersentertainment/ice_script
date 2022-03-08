#ifndef ICE_SCRIPT_ANALYZER_ENUMNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_ENUMNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using EnumNodeVisitorResultType = boost::variant<
            asg::Identifier,
    asg::Expression
>;

class EnumNodeVisitor : public AbstractVisitor<EnumNodeVisitor, EnumNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        EnumNodeVisitorResultType operator()(const ast::IdentifierNode& node);
    EnumNodeVisitorResultType operator()(const ast::ExprNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_ENUMNODEVISITOR_HPP
