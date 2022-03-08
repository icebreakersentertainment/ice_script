#ifndef ICE_SCRIPT_ANALYZER_EXPROPNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_EXPROPNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ExpropNodeVisitorResultType = boost::variant<
            asg::Mathoperator,
    asg::Comparisonoperator,
    asg::Logicoperator,
    asg::Bitoperator
>;

class ExpropNodeVisitor : public AbstractVisitor<ExpropNodeVisitor, ExpropNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        ExpropNodeVisitorResultType operator()(const ast::MathopNode& node);
    ExpropNodeVisitorResultType operator()(const ast::CompopNode& node);
    ExpropNodeVisitorResultType operator()(const ast::LogicopNode& node);
    ExpropNodeVisitorResultType operator()(const ast::BitopNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_EXPROPNODEVISITOR_HPP
