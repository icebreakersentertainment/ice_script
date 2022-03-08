#include "generator/llvm/detail/visitors/LambdaVisitor.hpp"

#include "generator/llvm/detail/generators/TypeGenerator.hpp"
#include "generator/llvm/detail/generators/TypemodifierGenerator.hpp"
#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/StatblockGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

LambdaVisitorResultType LambdaVisitor::operator()(const asg::Type& type)
{
    return process(*logger_, *context_, *llvm_, type);
}

LambdaVisitorResultType LambdaVisitor::operator()(const asg::Typemodifier& typemodifier)
{
    return process(*logger_, *context_, *llvm_, typemodifier);
}

LambdaVisitorResultType LambdaVisitor::operator()(const asg::Identifier& identifier)
{
    return process(*logger_, *context_, *llvm_, identifier);
}

LambdaVisitorResultType LambdaVisitor::operator()(const asg::Statblock& statblock)
{
    return process(*logger_, *context_, *llvm_, statblock);
}


}}}}