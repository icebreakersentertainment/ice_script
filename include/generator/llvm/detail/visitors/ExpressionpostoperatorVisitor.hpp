#ifndef ICE_SCRIPT_GENERATOR_EXPRESSIONPOSTOPERATORVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_EXPRESSIONPOSTOPERATORVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/FunctioncallGenerator.hpp"
#include "generator/llvm/detail/generators/VariableGenerator.hpp"
#include "generator/llvm/detail/generators/VariableaccessGenerator.hpp"
#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/AssignGenerator.hpp"
#include "generator/llvm/detail/generators/ArglistGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using ExpressionpostoperatorVisitorResultType = boost::variant<
        ::llvm::Value*,
        std::vector<::llvm::Value*>
>;

class ExpressionpostoperatorVisitor : public AbstractVisitor<ExpressionpostoperatorVisitor, ExpressionpostoperatorVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    ExpressionpostoperatorVisitorResultType operator()(const asg::Functioncall& functioncall)
    {
        return process(*context_, *llvm_, functioncall);
    }
    
    ExpressionpostoperatorVisitorResultType operator()(const asg::Variable& variable)
    {
        return process(*context_, *llvm_, variable);
    }
        
    ExpressionpostoperatorVisitorResultType operator()(const asg::Variableaccess& variableAccess)
    {
        return process(*context_, *llvm_, variableAccess);
    }

    // ExpressionpostoperatorVisitorResultType operator()(const asg::Identifier& identifier)
    // {
    //     return process(*context_, *llvm_, identifier);
    // }

    // ExpressionpostoperatorVisitorResultType operator()(const asg::Assign& assign)
    // {
    //     return process(*context_, *llvm_, assign);
    // }

    // ExpressionpostoperatorVisitorResultType operator()(const asg::Arglist& arglist)
    // {
    //     return process(*context_, *llvm_, arglist);
    // }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_EXPRESSIONPOSTOPERATORVISITOR_HPP
