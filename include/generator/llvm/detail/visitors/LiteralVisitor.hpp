#ifndef ICE_SCRIPT_GENERATOR_LITERALVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_LITERALVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

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

    LiteralVisitorResultType operator()(const asg::Number& number);
    LiteralVisitorResultType operator()(const asg::String& string);
    LiteralVisitorResultType operator()(const asg::Bits& bits);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_LITERALVISITOR_HPP
