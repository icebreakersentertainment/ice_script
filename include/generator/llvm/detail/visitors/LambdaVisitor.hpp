#ifndef ICE_SCRIPT_GENERATOR_LAMBDAVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_LAMBDAVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using LambdaVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class LambdaVisitor : public AbstractVisitor<LambdaVisitor, LambdaVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        LambdaVisitorResultType operator()(const asg::Type& type);
    LambdaVisitorResultType operator()(const asg::Typemodifier& typemodifier);
    LambdaVisitorResultType operator()(const asg::Identifier& identifier);
    LambdaVisitorResultType operator()(const asg::Statblock& statblock);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_LAMBDAVISITOR_HPP
