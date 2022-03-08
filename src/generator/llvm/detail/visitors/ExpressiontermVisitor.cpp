#include "generator/llvm/detail/visitors/ExpressiontermVisitor.hpp"

#include "generator/llvm/detail/generators/TypeGenerator.hpp"
#include "generator/llvm/detail/generators/InitlistGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressiontermGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionpreoperatorGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionvalueGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionpostoperatorGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

//ExpressiontermVisitorResultType ExpressiontermVisitor::operator()(const asg::Type& type)
//{
//    return process(*logger_, *context_, *llvm_, type);
//}
//
//ExpressiontermVisitorResultType ExpressiontermVisitor::operator()(const asg::Initlist& initlist)
//{
//    return process(*logger_, *context_, *llvm_, initlist);
//}
//
//ExpressiontermVisitorResultType ExpressiontermVisitor::operator()(const asg::Expressionpreoperator& expressionpreoperator)
//{
//    return process(*logger_, *context_, *llvm_, expressionpreoperator);
//}
//
//ExpressiontermVisitorResultType ExpressiontermVisitor::operator()(const asg::Expressionvalue& expressionvalue)
//{
//    return process(*logger_, *context_, *llvm_, expressionvalue);
//}
//
//ExpressiontermVisitorResultType ExpressiontermVisitor::operator()(const asg::Expressionpostoperator& expressionpostoperator)
//{
//    return process(*logger_, *context_, *llvm_, expressionpostoperator);
//}

ExpressiontermVisitorResultType ExpressiontermVisitor::operator()(const asg::OptionalTypeAndInitListType& optionalTypeAndInitList)
{
    return {}; //process(*logger_, *context_, *llvm_, expressionpostoperator);
}

ExpressiontermVisitorResultType ExpressiontermVisitor::operator()(const asg::VectorExprpreopExprvalueVectorExprpreopType& vectorExprpreopExprvalueVectorExprpreop)
{
//    return process(*logger_, *context_, *llvm_, expressionpostoperator);
//    return process(*logger_, *context_, *llvm_, boost::get<1>(vectorExprpreopExprvalueVectorExprpreop));
    return process(*logger_, *context_, *llvm_, vectorExprpreopExprvalueVectorExprpreop);
}


}}}}