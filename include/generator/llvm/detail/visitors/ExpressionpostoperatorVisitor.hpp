#ifndef ICE_SCRIPT_GENERATOR_EXPRESSIONPOSTOPERATORVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_EXPRESSIONPOSTOPERATORVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using ExpressionpostoperatorVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class ExpressionpostoperatorVisitor : public AbstractVisitor<ExpressionpostoperatorVisitor, ExpressionpostoperatorVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        ExpressionpostoperatorVisitorResultType operator()(const asg::Functioncall& functioncall);
    ExpressionpostoperatorVisitorResultType operator()(const asg::Variable& variable);
    ExpressionpostoperatorVisitorResultType operator()(const asg::Identifier& identifier);
    ExpressionpostoperatorVisitorResultType operator()(const asg::Assign& assign);
    ExpressionpostoperatorVisitorResultType operator()(const asg::Arglist& arglist);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_EXPRESSIONPOSTOPERATORVISITOR_HPP
