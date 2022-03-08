#ifndef ICE_SCRIPT_ANALYZER_INTFMTHDNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_INTFMTHDNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using IntfmthdNodeVisitorResultType = boost::variant<
            asg::Type,
    asg::Identifier,
    asg::Parameterlist
>;

class IntfmthdNodeVisitor : public AbstractVisitor<IntfmthdNodeVisitor, IntfmthdNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        IntfmthdNodeVisitorResultType operator()(const ast::TypeNode& node);
    IntfmthdNodeVisitorResultType operator()(const ast::IdentifierNode& node);
    IntfmthdNodeVisitorResultType operator()(const ast::ParamlistNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_INTFMTHDNODEVISITOR_HPP
