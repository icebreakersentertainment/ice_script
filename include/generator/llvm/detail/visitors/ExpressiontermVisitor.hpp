#ifndef ICE_SCRIPT_GENERATOR_EXPRESSIONTERMVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_EXPRESSIONTERMVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using ExpressiontermVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class ExpressiontermVisitor : public AbstractVisitor<ExpressiontermVisitor, ExpressiontermVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

//    ExpressiontermVisitorResultType operator()(const asg::Type& type);
//    ExpressiontermVisitorResultType operator()(const asg::Initlist& initlist);
//    ExpressiontermVisitorResultType operator()(const asg::Expressionpreoperator& expressionpreoperator);
//    ExpressiontermVisitorResultType operator()(const asg::Expressionvalue& expressionvalue);
//    ExpressiontermVisitorResultType operator()(const asg::Expressionpostoperator& expressionpostoperator);
    ExpressiontermVisitorResultType operator()(const asg::OptionalTypeAndInitListType& optionalTypeAndInitList);
    ExpressiontermVisitorResultType operator()(const asg::VectorExprpreopExprvalueVectorExprpreopType& vectorExprpreopExprvalueVectorExprpreop);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_EXPRESSIONTERMVISITOR_HPP
