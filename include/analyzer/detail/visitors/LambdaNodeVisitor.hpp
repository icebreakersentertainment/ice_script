#ifndef ICE_SCRIPT_ANALYZER_LAMBDANODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_LAMBDANODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using LambdaNodeVisitorResultType = boost::variant<
            asg::Type,
    asg::Typemodifier,
    asg::Identifier,
    asg::Statblock
>;

class LambdaNodeVisitor : public AbstractVisitor<LambdaNodeVisitor, LambdaNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        LambdaNodeVisitorResultType operator()(const ast::TypeNode& node);
    LambdaNodeVisitorResultType operator()(const ast::TypemodNode& node);
    LambdaNodeVisitorResultType operator()(const ast::IdentifierNode& node);
    LambdaNodeVisitorResultType operator()(const ast::StatblockNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_LAMBDANODEVISITOR_HPP
