#ifndef ICE_SCRIPT_GENERATOR_LITERALVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_LITERALVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/NumberGenerator.hpp"
#include "generator/llvm/detail/generators/StringGenerator.hpp"
#include "generator/llvm/detail/generators/BitsGenerator.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using LiteralVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class LiteralVisitor : public AbstractVisitor<LiteralVisitor, LiteralVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    LiteralVisitorResultType operator()(const asg::Number& number)
    {
        return process(*context_, *llvm_, number);
    }

    LiteralVisitorResultType operator()(const asg::String& string)
    {
        return process(*context_, *llvm_, string);
    }

    LiteralVisitorResultType operator()(const asg::Bits& bits)
    {
        return process(*context_, *llvm_, bits);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_LITERALVISITOR_HPP
