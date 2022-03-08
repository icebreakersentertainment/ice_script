#ifndef ICE_SCRIPT_ANALYZER_FUNCNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_FUNCNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using FuncNodeVisitorResultType = boost::variant<
            asg::Type,
    asg::Identifier,
    asg::Parameterlist,
    asg::Functionattribute,
    asg::Statblock
>;

class FuncNodeVisitor : public AbstractVisitor<FuncNodeVisitor, FuncNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        FuncNodeVisitorResultType operator()(const ast::TypeNode& node);
    FuncNodeVisitorResultType operator()(const ast::IdentifierNode& node);
    FuncNodeVisitorResultType operator()(const ast::ParamlistNode& node);
    FuncNodeVisitorResultType operator()(const ast::FuncattrNode& node);
    FuncNodeVisitorResultType operator()(const ast::StatblockNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_FUNCNODEVISITOR_HPP
