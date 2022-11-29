#ifndef ICE_SCRIPT_ANALYZER_MIXINNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_MIXINNODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/ClassNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using MixinNodeVisitorResultType = boost::variant<
        asg::Class
>;

class MixinNodeVisitor : public AbstractVisitor<MixinNodeVisitor, MixinNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    MixinNodeVisitorResultType operator()(const ast::ClassNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_MIXINNODEVISITOR_HPP
