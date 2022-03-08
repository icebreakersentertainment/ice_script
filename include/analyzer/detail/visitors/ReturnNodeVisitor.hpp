#ifndef ICE_SCRIPT_ANALYZER_RETURNNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_RETURNNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ReturnNodeVisitorResultType = boost::variant<
            asg::Assign
>;

class ReturnNodeVisitor : public AbstractVisitor<ReturnNodeVisitor, ReturnNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        ReturnNodeVisitorResultType operator()(const ast::AssignNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_RETURNNODEVISITOR_HPP
