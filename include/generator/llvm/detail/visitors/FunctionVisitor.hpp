#ifndef ICE_SCRIPT_GENERATOR_FUNCTIONVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_FUNCTIONVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using FunctionVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class FunctionVisitor : public AbstractVisitor<FunctionVisitor, FunctionVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        FunctionVisitorResultType operator()(const asg::Type& type);
    FunctionVisitorResultType operator()(const asg::Identifier& identifier);
    FunctionVisitorResultType operator()(const asg::Parameterlist& parameterlist);
    FunctionVisitorResultType operator()(const asg::Functionattribute& functionattribute);
    FunctionVisitorResultType operator()(const asg::Statblock& statblock);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_FUNCTIONVISITOR_HPP
