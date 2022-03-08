#ifndef ICE_SCRIPT_ANALYZER_FUNCCALLNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_FUNCCALLNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using FunccallNodeVisitorResultType = boost::variant<
            asg::Scoperatore,
    asg::Identifier,
    asg::Arglist
>;

class FunccallNodeVisitor : public AbstractVisitor<FunccallNodeVisitor, FunccallNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        FunccallNodeVisitorResultType operator()(const ast::ScopeNode& node);
    FunccallNodeVisitorResultType operator()(const ast::IdentifierNode& node);
    FunccallNodeVisitorResultType operator()(const ast::ArglistNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_FUNCCALLNODEVISITOR_HPP
