#ifndef ICE_SCRIPT_GENERATOR_EXPRESSIONSTATVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_EXPRESSIONSTATVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using ExpressionstatVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class ExpressionstatVisitor : public AbstractVisitor<ExpressionstatVisitor, ExpressionstatVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        ExpressionstatVisitorResultType operator()(const asg::Assign& assign);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_EXPRESSIONSTATVISITOR_HPP
