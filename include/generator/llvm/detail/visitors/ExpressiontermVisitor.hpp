#ifndef ICE_SCRIPT_GENERATOR_EXPRESSIONTERMVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_EXPRESSIONTERMVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/TypeGenerator.hpp"
#include "generator/llvm/detail/generators/InitlistGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressiontermGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionpreoperatorGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionvalueGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionpostoperatorGenerator.hpp"

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

    // ExpressiontermVisitorResultType operator()(const Type& type)
    // {
    //     return process(*context_, *llvm_, type);
    // }

    // ExpressiontermVisitorResultType operator()(const asg::Initlist& initlist)
    // {
    //     return process(*context_, *llvm_, initlist);
    // }

    // ExpressiontermVisitorResultType operator()(const asg::Expressionpreoperator& expressionpreoperator)
    // {
    //     return process(*context_, *llvm_, expressionpreoperator);
    // }

    // ExpressiontermVisitorResultType operator()(const asg::Expressionvalue& expressionvalue)
    // {
    //     return process(*context_, *llvm_, expressionvalue);
    // }

    // ExpressiontermVisitorResultType operator()(const asg::Expressionpostoperator& expressionpostoperator)
    // {
    //     return {};// process(*context_, *llvm_, expressionpostoperator);
    // }
    
    ExpressiontermVisitorResultType operator()(const asg::OptionalTypeAndInitListType& optionalTypeAndInitList)
    {
        return {}; //process(*context_, *llvm_, expressionpostoperator);
    }
    
    ExpressiontermVisitorResultType operator()(const asg::ExprpreopsExprvalueExprpostops& exprpreopsExprvalueExprpostops)
    {
    //    return process(*context_, *llvm_, expressionpostoperator);
    //    return process(*context_, *llvm_, boost::get<1>(vectorExprpreopExprvalueVectorExprpreop));
        return process(*context_, *llvm_, exprpreopsExprvalueExprpostops);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_EXPRESSIONTERMVISITOR_HPP
