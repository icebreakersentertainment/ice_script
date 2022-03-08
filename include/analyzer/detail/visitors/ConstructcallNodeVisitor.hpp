#ifndef ICE_SCRIPT_ANALYZER_CONSTRUCTCALLNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_CONSTRUCTCALLNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ConstructcallNodeVisitorResultType = boost::variant<
            asg::Type,
    asg::Arglist
>;

class ConstructcallNodeVisitor : public AbstractVisitor<ConstructcallNodeVisitor, ConstructcallNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        ConstructcallNodeVisitorResultType operator()(const ast::TypeNode& node);
    ConstructcallNodeVisitorResultType operator()(const ast::ArglistNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_CONSTRUCTCALLNODEVISITOR_HPP
