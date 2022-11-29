#ifndef ICE_SCRIPT_GENERATOR_ENUMERATIONVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_ENUMERATIONVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionGenerator.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using EnumerationVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class EnumerationVisitor : public AbstractVisitor<EnumerationVisitor, EnumerationVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    EnumerationVisitorResultType operator()(const asg::Identifier& identifier)
    {
        return process(*context_, *llvm_, identifier);
    }

    EnumerationVisitorResultType operator()(const asg::Expression& expression)
    {
        return process(*context_, *llvm_, expression);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_ENUMERATIONVISITOR_HPP
