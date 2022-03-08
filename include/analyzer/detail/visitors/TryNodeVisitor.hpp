#ifndef ICE_SCRIPT_ANALYZER_TRYNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_TRYNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using TryNodeVisitorResultType = boost::variant<
            asg::Statblock
>;

class TryNodeVisitor : public AbstractVisitor<TryNodeVisitor, TryNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        TryNodeVisitorResultType operator()(const ast::StatblockNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_TRYNODEVISITOR_HPP
