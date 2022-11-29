#ifndef ICE_SCRIPT_ANALYZER_EXPRPOSTOPNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_EXPRPOSTOPNODEVISITOR_HPP

#include <boost/algorithm/string/predicate.hpp>
#include <memory>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/FunccallNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ArglistNodeAnalyzer.hpp"
#include "analyzer/detail/SymbolKeyResolver.hpp"
#include "analyzer/detail/OperatorTypeUtilities.hpp"

#include "detail/Assert.hpp"
#include "type/ClassType.hpp"
#include "asg/PostfixOperator.hpp"

#include "detail/Format.hpp"

namespace ice_script { namespace analyzer { namespace detail {

inline const std::shared_ptr<ArraySymbol>& resolveArraySymbol(const Context& context, const std::shared_ptr<ArrayType>& arrayType)
{
    const auto fullyQualifiedName = ice_script::detail::format(
        "%s%s%s",
        arrayType->fullyQualifiedScopeName(),
        boost::algorithm::ends_with(arrayType->fullyQualifiedScopeName(), "::") ? "" : "::",
        arrayType->name()
    );
    
    const auto symbolKey = "array_" + fullyQualifiedName;
    
    return context.symbolTable().getArrayByKey(symbolKey);
}

inline const std::shared_ptr<ClassSymbol>& resolveClassSymbol(const Context& context, const std::shared_ptr<ClassType>& classType)
{
    const auto fullyQualifiedName = ice_script::detail::format(
        "%s%s%s",
        classType->fullyQualifiedScopeName(),
        boost::algorithm::ends_with(classType->fullyQualifiedScopeName(), "::") ? "" : "::",
        classType->name()
    );
    
    const auto symbolKey = "class_" + fullyQualifiedName;
    
    return context.symbolTable().getClassByKey(symbolKey);
}

inline const std::shared_ptr<FunctionSymbol>& resolveFunctionSymbol(const Context& context, const std::shared_ptr<OperatorType>& operatorType)
{
    const auto fullyQualifiedName = ice_script::detail::format(
        "%s%s%s",
        operatorType->fullyQualifiedScopeName(),
        boost::algorithm::ends_with(operatorType->fullyQualifiedScopeName(), "::") ? "" : "::",
        operatorType->name()
    );
    
    const auto symbolKey = "function_" + fullyQualifiedName;
    
    return context.symbolTable().getFunctionByKey(symbolKey);
}

using ExprpostopNodeVisitorResultType = boost::variant<
        asg::Functioncall,
        asg::Variable,
        asg::Variableaccess
>;

class ExprpostopNodeVisitor : public AbstractVisitor<ExprpostopNodeVisitor, ExprpostopNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    ExprpostopNodeVisitorResultType operator()(const ast::FunccallNode& node)
    {
        return process(*context_, node);
    }

    ExprpostopNodeVisitorResultType operator()(const ast::IdentifierNode& node)
    {
        const std::shared_ptr<Type>& type = context_->scope().valueType();
        const std::shared_ptr<Symbol>& symbol = context_->scope().valueSymbol();

        const auto& classType = std::dynamic_pointer_cast<ClassType>(type);
        if (!classType)
        {
            // error?
        }
        
        const auto& classSymbol = resolveClassSymbol(*context_, classType);
        
        asg::Variableaccess variableAccess{};

        const auto& name = node.value;
        auto memberVariableSymbols = classSymbol->memberVariables().find(name);
        
        ICE_SCRIPT_ASSERT(memberVariableSymbols.size() == 1);
        
        // auto memberVariableType = classType->findMemberVariable(name);

        variableAccess.symbol = memberVariableSymbols[0];
        // variable.type = memberVariableType;

        return variableAccess;
    }

    ExprpostopNodeVisitorResultType operator()(const boost::recursive_wrapper<ast::AssignNode>& node)
    {
    //    return process(*context_, node);
        const auto& type = context_->scope().valueType();
        const auto& symbol = context_->scope().valueSymbol();
        
        std::shared_ptr<FunctionSymbol> operatorSymbol{};
        
        const auto& classType = std::dynamic_pointer_cast<ClassType>(type);
        if (classType)
        {
            const auto classSymbol = resolveClassSymbol(*context_, classType);
            
            const auto operatorSymbols = classSymbol->operators().find(OperatorTypeId::INDEX);
            
            operatorSymbol = operatorSymbols[0];
        }
        else
        {
            const auto& arrayType = std::dynamic_pointer_cast<ArrayType>(type);
            
            if (arrayType)
            {
                const auto arraySymbol = resolveArraySymbol(*context_, arrayType);
                
                const auto operatorSymbols = arraySymbol->operators().find(OperatorTypeId::INDEX);
                
                operatorSymbol = operatorSymbols[0];
            }
            else
            {
                // error?
            }
        }
        
        asg::Functioncall functionCall{};
        
        functionCall.name = operatorSymbol->name();
        functionCall.type = operatorSymbol->type();
        functionCall.symbol = operatorSymbol;
        
        functionCall.arglist.get().arguments.push_back({process(*context_, node.get())});

        return functionCall;
    }

    ExprpostopNodeVisitorResultType operator()(const ast::ArglistNode& node)
    {
    //    return process(*context_, node);
        return {};
    }

    ExprpostopNodeVisitorResultType operator()(const ast::PostfixOperator& postfixOperator)
    {
        asg::PostfixOperator asgPostfixOperator{};

        asgPostfixOperator.postfixOperator = postfixOperator;

        const std::shared_ptr<Type>& type = context_->scope().valueType();

        const auto operators = type->operators().find(toOperatorTypeId(*context_, postfixOperator));

        const auto _operator = operators[0];

        asg::Functioncall functionCall{};
        
        functionCall.name = _operator->name();
        functionCall.type = _operator;

        return functionCall;
    }

    // ExprpostopNodeVisitorResultType operator()(const ast::OptionalIdentifierAssignVectorTupleOptionalIdentifierAssignType& optionalIdentifierAssignVectorTupleOptionalIdentifierAssign)
    // {
    //     return {};
    // }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_EXPRPOSTOPNODEVISITOR_HPP
