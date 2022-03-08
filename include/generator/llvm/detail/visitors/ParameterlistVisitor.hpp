#ifndef ICE_SCRIPT_GENERATOR_PARAMETERLISTVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_PARAMETERLISTVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using ParameterlistVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class ParameterlistVisitor : public AbstractVisitor<ParameterlistVisitor, ParameterlistVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        ParameterlistVisitorResultType operator()(const asg::Type& type);
    ParameterlistVisitorResultType operator()(const asg::Typemodifier& typemodifier);
    ParameterlistVisitorResultType operator()(const asg::Identifier& identifier);
    ParameterlistVisitorResultType operator()(const asg::Expression& expression);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_PARAMETERLISTVISITOR_HPP
