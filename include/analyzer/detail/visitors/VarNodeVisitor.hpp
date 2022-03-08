#ifndef ICE_SCRIPT_ANALYZER_VARNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_VARNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using VarNodeVisitorResultType = boost::variant<
        asg::Initlist,
        asg::Expression,
        asg::Arglist
>;

class VarNodeVisitor : public AbstractVisitor<VarNodeVisitor, VarNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    VarNodeVisitorResultType operator()(const ast::InitlistNode& node);
    VarNodeVisitorResultType operator()(const ast::ExprNode& node);
    VarNodeVisitorResultType operator()(const ast::ArglistNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_VARNODEVISITOR_HPP
