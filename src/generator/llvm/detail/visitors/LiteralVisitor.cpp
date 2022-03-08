#include "generator/llvm/detail/visitors/LiteralVisitor.hpp"

#include "generator/llvm/detail/generators/NumberGenerator.hpp"
#include "generator/llvm/detail/generators/StringGenerator.hpp"
#include "generator/llvm/detail/generators/BitsGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

LiteralVisitorResultType LiteralVisitor::operator()(const asg::Number& number)
{
    return process(*logger_, *context_, *llvm_, number);
}

LiteralVisitorResultType LiteralVisitor::operator()(const asg::String& string)
{
    return process(*logger_, *context_, *llvm_, string);
}

LiteralVisitorResultType LiteralVisitor::operator()(const asg::Bits& bits)
{
    return process(*logger_, *context_, *llvm_, bits);
}


}}}}