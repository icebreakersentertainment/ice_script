#ifndef ICE_SCRIPT_ANALYZER_IFNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_IFNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using IfNodeVisitorResultType = boost::variant<
            asg::Assign,
    asg::Statement
>;

class IfNodeVisitor : public AbstractVisitor<IfNodeVisitor, IfNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        IfNodeVisitorResultType operator()(const ast::AssignNode& node);
    IfNodeVisitorResultType operator()(const ast::StatementNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_IFNODEVISITOR_HPP
