#ifndef ICE_SCRIPT_GENERATOR_EXPRESSIONPREOPERATORVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_EXPRESSIONPREOPERATORVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using ExpressionpreoperatorVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class ExpressionpreoperatorVisitor : public AbstractVisitor<ExpressionpreoperatorVisitor, ExpressionpreoperatorVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_EXPRESSIONPREOPERATORVISITOR_HPP
