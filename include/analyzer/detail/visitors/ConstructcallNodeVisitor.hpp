#ifndef ICE_SCRIPT_ANALYZER_CONSTRUCTCALLNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_CONSTRUCTCALLNODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/TypeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ArglistNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ConstructcallNodeVisitorResultType = boost::variant<
        Type,
        asg::Arglist
>;

class ConstructcallNodeVisitor : public AbstractVisitor<ConstructcallNodeVisitor, ConstructcallNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    ConstructcallNodeVisitorResultType operator()(const ast::TypeNode& node)
    {
        return process(*context_, node);
    }

    ConstructcallNodeVisitorResultType operator()(const ast::ArglistNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_CONSTRUCTCALLNODEVISITOR_HPP
