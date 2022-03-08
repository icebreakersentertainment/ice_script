#ifndef ICE_SCRIPT_ANALYZER_CASTNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_CASTNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using CastNodeVisitorResultType = boost::variant<
            asg::Type,
    asg::Assign
>;

class CastNodeVisitor : public AbstractVisitor<CastNodeVisitor, CastNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        CastNodeVisitorResultType operator()(const ast::TypeNode& node);
    CastNodeVisitorResultType operator()(const ast::AssignNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_CASTNODEVISITOR_HPP
