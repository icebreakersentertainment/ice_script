#ifndef ICE_SCRIPT_ANALYZER_CLASSNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_CLASSNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ClassNodeVisitorResultType = boost::variant<
            asg::Identifier,
    asg::Virtualproperatorerty,
    asg::Function,
    asg::Variable,
    asg::Functiondefinition
>;

class ClassNodeVisitor : public AbstractVisitor<ClassNodeVisitor, ClassNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        ClassNodeVisitorResultType operator()(const ast::IdentifierNode& node);
    ClassNodeVisitorResultType operator()(const ast::VirtpropNode& node);
    ClassNodeVisitorResultType operator()(const ast::FuncNode& node);
    ClassNodeVisitorResultType operator()(const ast::VarNode& node);
    ClassNodeVisitorResultType operator()(const ast::FuncdefNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_CLASSNODEVISITOR_HPP
