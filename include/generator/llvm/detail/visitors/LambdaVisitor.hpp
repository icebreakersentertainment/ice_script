#ifndef ICE_SCRIPT_GENERATOR_LAMBDAVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_LAMBDAVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/TypeGenerator.hpp"
#include "generator/llvm/detail/generators/TypemodifierGenerator.hpp"
#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/StatblockGenerator.hpp"

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

    LambdaVisitorResultType operator()(const Type& type)
    {
        return process(*context_, *llvm_, type);
    }

    LambdaVisitorResultType operator()(const asg::Typemodifier& typemodifier)
    {
        return process(*context_, *llvm_, typemodifier);
    }

    LambdaVisitorResultType operator()(const asg::Identifier& identifier)
    {
        return process(*context_, *llvm_, identifier);
    }

    LambdaVisitorResultType operator()(const asg::Statblock& statblock)
    {
        return process(*context_, *llvm_, statblock);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_LAMBDAVISITOR_HPP
