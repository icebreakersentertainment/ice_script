#ifndef ICE_SCRIPT_ANALYZER_ARGLISTNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_ARGLISTNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ArglistNodeVisitorResultType = boost::variant<
            asg::Identifier,
    asg::Assign
>;

class ArglistNodeVisitor : public AbstractVisitor<ArglistNodeVisitor, ArglistNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        ArglistNodeVisitorResultType operator()(const ast::IdentifierNode& node);
    ArglistNodeVisitorResultType operator()(const ast::AssignNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_ARGLISTNODEVISITOR_HPP
