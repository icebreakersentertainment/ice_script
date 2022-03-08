#ifndef ICE_SCRIPT_ANALYZER_INITLISTNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_INITLISTNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using InitlistNodeVisitorResultType = boost::variant<
            asg::Assign
>;

class InitlistNodeVisitor : public AbstractVisitor<InitlistNodeVisitor, InitlistNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        InitlistNodeVisitorResultType operator()(const ast::AssignNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_INITLISTNODEVISITOR_HPP
