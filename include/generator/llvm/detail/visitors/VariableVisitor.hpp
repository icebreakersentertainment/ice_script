#ifndef ICE_SCRIPT_GENERATOR_VARIABLEVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_VARIABLEVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using VariableVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class VariableVisitor : public AbstractVisitor<VariableVisitor, VariableVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    VariableVisitorResultType operator()(const asg::Initlist& initlist);
    VariableVisitorResultType operator()(const asg::Expression& expression);
    VariableVisitorResultType operator()(const asg::Arglist& arglist);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_VARIABLEVISITOR_HPP
