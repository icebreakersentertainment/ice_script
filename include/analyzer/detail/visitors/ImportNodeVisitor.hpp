#ifndef ICE_SCRIPT_ANALYZER_IMPORTNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_IMPORTNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ImportNodeVisitorResultType = boost::variant<
            asg::Type,
    asg::Identifier,
    asg::Parameterlist,
    asg::Functionattribute,
    asg::String
>;

class ImportNodeVisitor : public AbstractVisitor<ImportNodeVisitor, ImportNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        ImportNodeVisitorResultType operator()(const ast::TypeNode& node);
    ImportNodeVisitorResultType operator()(const ast::IdentifierNode& node);
    ImportNodeVisitorResultType operator()(const ast::ParamlistNode& node);
    ImportNodeVisitorResultType operator()(const ast::FuncattrNode& node);
    ImportNodeVisitorResultType operator()(const ast::StringNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_IMPORTNODEVISITOR_HPP
