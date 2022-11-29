#include "analyzer/detail/analyzers/ClassNodeAnalyzer.hpp"

#include "analyzer/detail/visitors/ClassNodeVisitor.hpp"
#include "analyzer/detail/SymbolKeyResolver.hpp"

#include "asg/Expressionterm.hpp"
#include "asg/Expressionvalue.hpp"
#include "asg/Variableaccess.hpp"
#include "symbol/FunctionSymbol.hpp"
#include "type/ClassType.hpp"

#include "asg/Virtualproperatorerty.hpp"
#include "type/TypeQualifier.hpp"
#include <algorithm>
#include <memory>

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

struct VirtualPropertyFunctionVariableFunctionDefinitionsVisitor : public boost::static_visitor<void>
{
    explicit VirtualPropertyFunctionVariableFunctionDefinitionsVisitor(Class& classData) : classData(&classData)
    {}
    
    void operator()(const Virtualproperatorerty& virtualproperatorerty)
    {
        classData->virtualproperatorerties.push_back(virtualproperatorerty);
    }
    
    void operator()(const Function& function)
    {
        classData->functions.push_back(function);
    }
    
    void operator()(const Variable& variable)
    {
        classData->variables.push_back(variable);
    }
    
    void operator()(const Functiondefinition& functiondefinition)
    {
        classData->functiondefinitions.push_back(functiondefinition);
    }
    
    Class* classData;
};

auto createAssignment(Context& context, const std::shared_ptr<Symbol>& thisSymbol, const std::shared_ptr<Symbol>& memberVariable, const Expression& expression)
{
    Assign assign{};
    
    // ice_script::asg::ExprpreopsExprvalueExprpostops exprpreopsExprvalueExprpostopsLhs{};
    // exprpreopsExprvalueExprpostopsLhs.expressionValue = Expressionvalue{Variableaccess{thisSymbol, thisSymbol->type()}};
    // exprpreopsExprvalueExprpostopsLhs.expressionPostoperators.push_back(Expressionpostoperator{Variableaccess{memberVariable, memberVariable->type()}});
    
    ice_script::asg::ExprpreopsExprvalueExprpostops exprpreopsExprvalueExprpostopsLhs{};
    exprpreopsExprvalueExprpostopsLhs.expressionValue = Expressionvalue{Variableaccess{memberVariable, memberVariable->type()}};
    
    Expressionterm expressiontermLhs{exprpreopsExprvalueExprpostopsLhs};
    Expression expressionLhs{expressiontermLhs}; 
    
    // ice_script::asg::ExprpreopsExprvalueExprpostops exprpreopsExprvalueExprpostopsRhs{};
    // exprpreopsExprvalueExprpostopsRhs.expressionValue = Expressionvalue{Variableaccess{otherSymbol, otherSymbol->type()}};
    // exprpreopsExprvalueExprpostopsRhs.expressionPostoperators.push_back(Expressionpostoperator{Variableaccess{memberVariable, memberVariable->type()}});
    
    // Expressionterm expressiontermRhs{exprpreopsExprvalueExprpostopsRhs};
    // Expression expressionRhs{expressiontermRhs};
    
    Assign assignRhs{};
    assignRhs.condition = {expression};
    
    const auto operators = memberVariable->type()->operators().find(OperatorTypeId::ASSIGN_EQUAL);
    
    std::shared_ptr<OperatorType> operatorType{};
    for (const auto& _operator : operators)
    {
        if (_operator->parameters().size() != 1) continue;
        
        const auto& parameter = _operator->parameters()[0];
        
        if (parameter != memberVariable->type()) continue;
        
        operatorType = _operator;
    }
    
    if (!operatorType) throw RuntimeException("");
    
    assign.condition = {expressionLhs};
    assign.functioncall = {Functioncall{nullptr, operatorType, Arglist{{Argument(assignRhs)}}}};
    
    return assign;
}

auto createCopyAssignment(Context& context, const std::shared_ptr<Symbol>& thisSymbol, const std::shared_ptr<Symbol>& otherSymbol, const std::shared_ptr<Symbol>& memberVariable)
{
    Assign assign{};
    
    // ice_script::asg::ExprpreopsExprvalueExprpostops exprpreopsExprvalueExprpostopsLhs{};
    // exprpreopsExprvalueExprpostopsLhs.expressionValue = Expressionvalue{Variableaccess{thisSymbol, thisSymbol->type()}};
    // exprpreopsExprvalueExprpostopsLhs.expressionPostoperators.push_back(Expressionpostoperator{Variableaccess{memberVariable, memberVariable->type()}});
    
    ice_script::asg::ExprpreopsExprvalueExprpostops exprpreopsExprvalueExprpostopsLhs{};
    exprpreopsExprvalueExprpostopsLhs.expressionValue = Expressionvalue{Variableaccess{memberVariable, memberVariable->type()}};
    
    Expressionterm expressiontermLhs{exprpreopsExprvalueExprpostopsLhs};
    Expression expressionLhs{expressiontermLhs}; 
    
    ice_script::asg::ExprpreopsExprvalueExprpostops exprpreopsExprvalueExprpostopsRhs{};
    exprpreopsExprvalueExprpostopsRhs.expressionValue = Expressionvalue{Variableaccess{otherSymbol, otherSymbol->type()}};
    exprpreopsExprvalueExprpostopsRhs.expressionPostoperators.push_back(Expressionpostoperator{Variableaccess{memberVariable, memberVariable->type()}});
    
    Expressionterm expressiontermRhs{exprpreopsExprvalueExprpostopsRhs};
    Expression expressionRhs{expressiontermRhs};
    
    Assign assignRhs{};
    assignRhs.condition = {expressionRhs};
    
    const auto operators = memberVariable->type()->operators().find(OperatorTypeId::ASSIGN_EQUAL);
    
    std::shared_ptr<OperatorType> operatorType{};
    for (const auto& _operator : operators)
    {
        if (_operator->parameters().size() != 1) continue;
        
        const auto& parameter = _operator->parameters()[0];
        
        if (parameter != memberVariable->type()) continue;
        
        operatorType = _operator;
    }
    
    if (!operatorType) throw RuntimeException("");
    
    assign.condition = {expressionLhs};
    assign.functioncall = {Functioncall{nullptr, operatorType, Arglist{{Argument(assignRhs)}}}};
    
    return assign;
}

Function createConstructor(Context& context, const Class& classData, const std::shared_ptr<FunctionSymbol>& constructor)
{
    Function function{};
    function.name = constructor->name();
    function.symbol = constructor;
    function.returnType = constructor->type()->returnType();
    
    const auto& parameters = constructor->type()->parameters().getAll();
    
    const auto& constReferenceType = context.typeTable().find(constructor->ownerSymbol()->type(), TypeQualifier::CONSTANT, TypeModifier::REFERENCE);
    
    if (parameters.empty())
    {
        // Default constructor
        // Statblock statblock{};
        
        // const auto& classSymbol = std::dynamic_pointer_cast<ClassSymbol>(constructor->ownerSymbol());
        
        for (const auto& variable : classData.variables)
        {
            if (variable.get().value.type() == typeid(Initlist))
            {
                // const auto& initlist = boost::get<Initlist>(variable.get().value);
            }
            else if (variable.get().value.type() == typeid(Expression))
            {
                const auto& expression = boost::get<Expression>(variable.get().value);
                
                auto assign = createAssignment(context, classData.symbol, variable.get().symbol, expression);
                
                function.body.get().values.push_back(Statement{Expressionstat{assign}});
            }
            else if (variable.get().value.type() == typeid(Arglist))
            {
                // const auto& arglist = boost::get<Arglist>(variable.get().value);
            }
            else
            {
                throw RuntimeException("");
            }
            
            // function.body.get().values.push_back(variable.get());
        }
        
        // function.body = statblock;
    }
    else if (parameters.size() == 1 && parameters[0] == constReferenceType)
    {
        // Copy constructor
        // Statblock statblock{};
        
        const auto& classSymbol = std::dynamic_pointer_cast<ClassSymbol>(constructor->ownerSymbol());
        
        // auto otherSymbol = std::make_shared<Symbol>("other");
    
        // otherSymbol->setType(constructor->ownerSymbol()->type());
        
        for (const auto& memberVariable : classSymbol->memberVariables())
        {
            // auto assign = createCopyAssignment(context, classData.symbol, constructor->parameters()[0], memberVariable);
            auto assign = createCopyAssignment(context, classData.symbol, constructor->parameters()[0], memberVariable);
            function.body.get().values.push_back(Statement{Expressionstat{assign}});
        }
        
        // function.body = statblock;
    }
    else
    {
        // TODO?
        throw RuntimeException("");
    }
    
    return function;
}

void addMissingConstructors(Context& context, Class& classData)
{
    std::vector<std::shared_ptr<FunctionSymbol>> constructorSymbols{};
    for (const auto& function : classData.functions)
    {
        if (function.get().symbol->type()->isConstructor()) constructorSymbols.push_back(function.get().symbol);
    }
    
    // for (const auto& constructorSymbol : constructorSymbols)
    for (const auto& constructor : classData.symbol->constructors())
    {
        const auto it = std::find(constructorSymbols.begin(), constructorSymbols.end(), constructor);
        
        if (it == constructorSymbols.end())
        {
            classData.functions.push_back(createConstructor(context, classData, constructor));
        }
    }
}

asg::Class process(Context& context, const ast::ClassNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    const auto name = node.identifierNode.get().value;
    
    Scope& scope = context.scope();
    Scope& currentScope = context.pushScope(name, ScopeType::CLASS);

    Class classData{};
    
    const auto symbolKey = resolveSymbolKey(context, node);
    auto symbol = scope.symbolTable().findClassByKey(symbolKey);
    
    if (!symbol) symbol = context.symbolTable().getClassByKey(symbolKey);
    
    classData.symbol = symbol;
    
    scope.symbolTable().add(symbol);
    currentScope.symbolTable().add(symbol);
    
    currentScope.setValueSymbol(symbol);

    if (node.value)
    {
        const ClassData _classData = node.value.get();

        ClassNodeVisitor classNodeVisitor{context};
        VirtualPropertyFunctionVariableFunctionDefinitionsVisitor visitor{classData};

        for (const auto& virtualPropertyFunctionVariableFunctionDefinition : _classData.virtualPropertyFunctionVariableFunctionDefinitions)
        {
            auto value = boost::apply_visitor(classNodeVisitor, virtualPropertyFunctionVariableFunctionDefinition);
            
            boost::apply_visitor(visitor, value);
        }
        
        addMissingConstructors(context, classData);
    }

    classData.name = name;
    classData.type = context.typeTable().getClass(name);
    
    context.popScope();

    return classData;
}

}}}