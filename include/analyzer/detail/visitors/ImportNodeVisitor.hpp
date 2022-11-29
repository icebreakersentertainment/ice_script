#ifndef ICE_SCRIPT_ANALYZER_IMPORTNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_IMPORTNODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/TypeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ParamlistNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/FuncattrNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StringNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ImportNodeVisitorResultType = boost::variant<
        Type,
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

    ImportNodeVisitorResultType operator()(const ast::TypeNode& node)
    {
        return process(*context_, node);
    }

    ImportNodeVisitorResultType operator()(const ast::IdentifierNode& node)
    {
        return process(*context_, node);
    }

    ImportNodeVisitorResultType operator()(const ast::ParamlistNode& node)
    {
        return process(*context_, node);
    }

    ImportNodeVisitorResultType operator()(const ast::FuncattrNode& node)
    {
        return process(*context_, node);
    }

    ImportNodeVisitorResultType operator()(const ast::StringNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_IMPORTNODEVISITOR_HPP
