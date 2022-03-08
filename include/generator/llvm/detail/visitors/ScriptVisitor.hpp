#ifndef ICE_SCRIPT_GENERATOR_SCRIPTVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_SCRIPTVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using ScriptVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class ScriptVisitor : public AbstractVisitor<ScriptVisitor, ScriptVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        ScriptVisitorResultType operator()(const asg::Import& import);
    ScriptVisitorResultType operator()(const asg::Enumeration& enumeration);
    ScriptVisitorResultType operator()(const asg::Typedefinition& typedefinition);
    ScriptVisitorResultType operator()(const asg::Class& classData);
    ScriptVisitorResultType operator()(const asg::Mixin& mixin);
    ScriptVisitorResultType operator()(const asg::Interface& interfaceData);
    ScriptVisitorResultType operator()(const asg::Functiondefinition& functiondefinition);
    ScriptVisitorResultType operator()(const asg::Virtualproperatorerty& virtualproperatorerty);
    ScriptVisitorResultType operator()(const asg::Variable& variable);
    ScriptVisitorResultType operator()(const asg::Function& function);
    ScriptVisitorResultType operator()(const asg::Namespace& namespaceDefinition);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_SCRIPTVISITOR_HPP
