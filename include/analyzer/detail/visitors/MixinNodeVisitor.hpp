#ifndef ICE_SCRIPT_ANALYZER_MIXINNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_MIXINNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

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

        MixinNodeVisitorResultType operator()(const ast::ClassNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_MIXINNODEVISITOR_HPP
