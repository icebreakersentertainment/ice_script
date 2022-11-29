#ifndef ICE_SCRIPT_ANALYZER_CLASSNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_CLASSNODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/VirtpropNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/FuncNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/VarNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/FuncdefNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ClassNodeVisitorResultType = boost::variant<
//            asg::Identifier,
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

    ClassNodeVisitorResultType operator()(const ast::VirtpropNode& node)
    {
        return process(*context_, node);
    }

    ClassNodeVisitorResultType operator()(const ast::FuncNode& node)
    {
        return process(*context_, node);
    }

    ClassNodeVisitorResultType operator()(const ast::VarNode& node)
    {
        return process(*context_, node);
    }

    ClassNodeVisitorResultType operator()(const ast::FuncdefNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_CLASSNODEVISITOR_HPP
