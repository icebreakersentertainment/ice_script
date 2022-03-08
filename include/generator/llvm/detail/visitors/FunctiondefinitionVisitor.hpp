#ifndef ICE_SCRIPT_GENERATOR_FUNCTIONDEFINITIONVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_FUNCTIONDEFINITIONVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using FunctiondefinitionVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class FunctiondefinitionVisitor : public AbstractVisitor<FunctiondefinitionVisitor, FunctiondefinitionVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        FunctiondefinitionVisitorResultType operator()(const asg::Type& type);
    FunctiondefinitionVisitorResultType operator()(const asg::Identifier& identifier);
    FunctiondefinitionVisitorResultType operator()(const asg::Parameterlist& parameterlist);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_FUNCTIONDEFINITIONVISITOR_HPP
