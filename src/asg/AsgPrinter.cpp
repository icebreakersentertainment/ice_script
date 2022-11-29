#include "asg/AsgPrinter.hpp"
#include "asg/Typemodifier.hpp"
#include "type/TypeModifier.hpp"
#include "type/TypeQualifier.hpp"

// Adapted from: https://stackoverflow.com/a/45677131
template<int N, typename... Ts> using NthTypeOf = typename std::tuple_element<N, std::tuple<Ts...>>::type;

template<int N, typename... Ts>
auto& get(boost::variant<Ts...>& v)
{
    using target = NthTypeOf<N, Ts...>;
    return boost::get<target>(v);
}

template<int N, typename... Ts>
auto& get(const boost::variant<Ts...>& v)
{
    using target = NthTypeOf<N, Ts...>;
    return boost::get<target>(v);
}

namespace ice_script { namespace asg {

void AsgPrinter::operator()(const Arglist& arglist) const
{
	printBasic(arglist);

    AsgPrinter asgPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};
    
    for (const auto& argument : arglist.arguments)
    {
        os_ << std::endl << "Argument " << argument.name.value_or("") << std::endl;
        
        asgPrinter.operator()(argument.assign);
    }
}

void AsgPrinter::operator()(const Asg& asg) const
{
    operator()(asg.root);
}

void AsgPrinter::operator()(const Assign& assign) const
{
	printBasic(assign);

    AsgPrinter asgPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

    asgPrinter.operator()(assign.condition);

    if (assign.functioncall)
    {
        asgPrinter.operator()(assign.functioncall.get());
    }
}

void AsgPrinter::operator()(const Assignoperator& assignoperator) const
{
	printBasic(assignoperator);
}

void AsgPrinter::operator()(const Bitoperator& bitoperator) const
{
	printBasic(bitoperator);
}

void AsgPrinter::operator()(const Bits& bits) const
{
	printBasic(bits);
}

void AsgPrinter::operator()(const Break& breakStatement) const
{
	printBasic(breakStatement);
}

void AsgPrinter::operator()(const Case& caseStatement) const
{
	printBasic(caseStatement);
}

void AsgPrinter::operator()(const Cast& cast) const
{
	printBasic(cast);
}

void AsgPrinter::operator()(const Class& classData) const
{
	printBasic(classData, false);
    
    os_ << "[" << classData.name << "]" << std::endl;

    AsgPrinter asgPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

    for (const auto& virtualproperatorerty : classData.virtualproperatorerties) asgPrinter.operator()(virtualproperatorerty);
    for (const auto& function : classData.functions) asgPrinter.operator()(function);
    for (const auto& variable : classData.variables) asgPrinter.operator()(variable);
    for (const auto& functiondefinition : classData.functiondefinitions) asgPrinter.operator()(functiondefinition);
}

void AsgPrinter::operator()(const Comparisonoperator& comparisonoperator) const
{
	printBasic(comparisonoperator, false);

    os_ << "[" << toString(comparisonoperator.comparisonOperator) << "]" << std::endl;
}

void AsgPrinter::operator()(const Condition& condition) const
{
	printBasic(condition);

    AsgPrinter asgPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

    asgPrinter.operator()(condition.expression);

    if (condition.assign)
    {
        asgPrinter.operator()(boost::get<0>(condition.assign.get()));
        asgPrinter.operator()(boost::get<1>(condition.assign.get()));
    }
}

void AsgPrinter::operator()(const Constructcall& constructcall) const
{
	printBasic(constructcall, false);

    os_ << "[" << constructcall.symbol->name() << "]" << std::endl;

    AsgPrinter asgPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

    asgPrinter.operator()(constructcall.arglist);
}

void AsgPrinter::operator()(const Continue& continueStatement) const
{
	printBasic(continueStatement);
}

void AsgPrinter::operator()(const Datatype& datatype) const
{
	printBasic(datatype);
}

void AsgPrinter::operator()(const Double& doubleValue) const
{
	printBasic(doubleValue, false);

    os_ << "[" << doubleValue.value << "]" << std::endl;
}


void AsgPrinter::operator()(const Dowhile& dowhile) const
{
	printBasic(dowhile);
}

void AsgPrinter::operator()(const Enumeration& enumeration) const
{
	printBasic(enumeration);
}

void AsgPrinter::operator()(const Expression& expression) const
{
	printBasic(expression);

    AsgPrinter asgPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

    asgPrinter.operator()(expression.expressionterm);

    if (expression.functioncall)
    {
        asgPrinter.operator()(expression.functioncall.get());
    }
}

void AsgPrinter::operator()(const Expressionoperatorerty& expressionoperatorerty) const
{
	printBasic(expressionoperatorerty);

    boost::apply_visitor(AsgPrinter(os_, printLocationInfo_, indent_ + TAB_SIZE), expressionoperatorerty.value);
}

void AsgPrinter::operator()(const Expressionpostoperator& expressionpostoperator) const
{
	printBasic(expressionpostoperator);

    boost::apply_visitor(AsgPrinter(os_, printLocationInfo_, indent_ + TAB_SIZE), expressionpostoperator.value);
}

void AsgPrinter::operator()(const Expressionpreoperator& expressionpreoperator) const
{
	printBasic(expressionpreoperator);
}

void AsgPrinter::operator()(const Expressionstat& expressionstat) const
{
	printBasic(expressionstat);

    AsgPrinter asgPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

    if (expressionstat.assign)
    {
        asgPrinter.operator()(expressionstat.assign.get());
    }
}

void AsgPrinter::operator()(const Expressionterm& expressionterm) const
{
	printBasic(expressionterm);

    if (expressionterm.value.which() == 2)
    {
        AsgPrinter asgPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

        const auto& exprpreopsExprvalueExprpostops = get<2>(expressionterm.value);

        for (const auto& expressionPreoperator : exprpreopsExprvalueExprpostops.expressionPreoperators) asgPrinter.operator()(expressionPreoperator);

        asgPrinter.operator()(exprpreopsExprvalueExprpostops.expressionValue);

        for (const auto& expressionPostoperator : exprpreopsExprvalueExprpostops.expressionPostoperators) asgPrinter.operator()(expressionPostoperator);
    }
}

void AsgPrinter::operator()(const Expressionvalue& expressionvalue) const
{
	printBasic(expressionvalue);

    boost::apply_visitor(AsgPrinter(os_, printLocationInfo_, indent_ + TAB_SIZE), expressionvalue.value);
}

void AsgPrinter::operator()(const Float& floatValue) const
{
	printBasic(floatValue, false);

    os_ << "[" << floatValue.value << "]" << std::endl;
}


void AsgPrinter::operator()(const For& forLoop) const
{
	printBasic(forLoop);

    AsgPrinter asgPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

    boost::apply_visitor(asgPrinter, forLoop.variableOrExpressionstat);

    asgPrinter.operator()(forLoop.expressionstat);

    for (const auto& assign : forLoop.assigns)
    {
        asgPrinter.operator()(assign);
    }

    asgPrinter.operator()(forLoop.statement);
}

void AsgPrinter::operator()(const Function& function) const
{
	printBasic(function, false);

    os_ << "[" << function.name << "]" << std::endl;

    AsgPrinter asgPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

    for (const auto& parameter : function.parameters)
    {
        asgPrinter.operator()(parameter);
    }

    asgPrinter.operator()(function.body);
}

void AsgPrinter::operator()(const std::shared_ptr<FunctionType>& functionType) const
{
	operator()(*functionType);
}

void AsgPrinter::operator()(const FunctionType& functionType) const
{
	printBasic(functionType, false);
//    operator()(static_cast<const Type&>(functionType));

    os_ << "[" << functionType.name() << "]" << std::endl;
}

void AsgPrinter::operator()(const Functionattribute& functionattribute) const
{
	printBasic(functionattribute);
}

void AsgPrinter::operator()(const Functioncall& functioncall) const
{
	printBasic(functioncall, false);

    const auto& name = functioncall.symbol ? functioncall.symbol->name() : functioncall.type->name();
    
    os_ << "[" << name << "]" << std::endl;

    AsgPrinter asgPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

    asgPrinter.operator()(functioncall.arglist);
    
    // for (const auto& argument : functioncall.arguments)
    // {
    //     os_ << std::endl << "Argument " << argument.name << std::endl;
        
    //     asgPrinter.operator()(argument.assign);
    // }
}

void AsgPrinter::operator()(const Functiondefinition& functiondefinition) const
{
	printBasic(functiondefinition);
}

void AsgPrinter::operator()(const Identifier& identifier) const
{
	printBasic(identifier, false);

    os_ << "[" << identifier.value << "]" << std::endl;
}

void AsgPrinter::operator()(const If& ifStatement) const
{
	printBasic(ifStatement);

    AsgPrinter asgPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

    asgPrinter.operator()(ifStatement.assign.get());
    asgPrinter.operator()(ifStatement.statement.get());

    if (ifStatement.optionalStatement)
    {
        asgPrinter.operator()(ifStatement.optionalStatement.get().get());
    }
}

void AsgPrinter::operator()(const Import& import) const
{
	printBasic(import);
}

void AsgPrinter::operator()(const Initlist& initlist) const
{
	printBasic(initlist);
}

void AsgPrinter::operator()(const Integer& integer) const
{
	printBasic(integer, false);

    os_ << "[" << integer.value << "]" << std::endl;
}

void AsgPrinter::operator()(const Integer16& integer16) const
{
	printBasic(integer16, false);

    os_ << "[" << integer16.value << "]" << std::endl;
}

void AsgPrinter::operator()(const Integer32& integer32) const
{
	printBasic(integer32, false);

    os_ << "[" << integer32.value << "]" << std::endl;
}

void AsgPrinter::operator()(const Integer64& integer64) const
{
	printBasic(integer64, false);

    os_ << "[" << integer64.value << "]" << std::endl;
}

void AsgPrinter::operator()(const Integer8& integer8) const
{
	printBasic(integer8, false);

    os_ << "[" << static_cast<int32_t>(integer8.value) << "]" << std::endl;
}


void AsgPrinter::operator()(const Interface& interfaceData) const
{
	printBasic(interfaceData);
}

void AsgPrinter::operator()(const Interfacemethod& interfacemethod) const
{
	printBasic(interfacemethod);
}

void AsgPrinter::operator()(const Lambda& lambda) const
{
	printBasic(lambda);
}

void AsgPrinter::operator()(const Literal& literal) const
{
	printBasic(literal);

    boost::apply_visitor(AsgPrinter(os_, printLocationInfo_, indent_ + TAB_SIZE), literal.value);
}

void AsgPrinter::operator()(const Logicoperator& logicoperator) const
{
	printBasic(logicoperator);
}

void AsgPrinter::operator()(const Mathoperator& mathoperator) const
{
	printBasic(mathoperator, false);

    os_ << "[" << toString(mathoperator.mathOperator) << "]" << std::endl;
}

void AsgPrinter::operator()(const Mixin& mixin) const
{
	printBasic(mixin);
}

void AsgPrinter::operator()(const Namespace& namespaceDefinition) const
{
	printBasic(namespaceDefinition);
}

void AsgPrinter::operator()(const Number& number) const
{
	printBasic(number);

    AsgPrinter asgPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

    asgPrinter.operator()(number.value);

}

void AsgPrinter::operator()(const std::shared_ptr<OperatorType>& operatorType) const
{
	operator()(*operatorType);
}

void AsgPrinter::operator()(const OperatorType& operatorType) const
{
//	printBasic(operatorType);
//    operator()(static_cast<const FunctionType&>(operatorType));

    printBasic(operatorType, false);
//    operator()(static_cast<const Type&>(functionType));

    os_ << "[" << operatorType.name() << "]" << std::endl;
}

void AsgPrinter::operator()(const Parameterlist& parameterlist) const
{
	printBasic(parameterlist);
}

void AsgPrinter::operator()(const Primativetype& primativetype) const
{
	printBasic(primativetype);
}

void AsgPrinter::operator()(const std::shared_ptr<PrimitiveType>& primitiveType) const
{
	operator()(*primitiveType);
}

void AsgPrinter::operator()(const PrimitiveType& primitiveType) const
{
//	printBasic(primitiveType);
//    operator()(static_cast<const Type&>(primitiveType));

    printBasic(primitiveType, false);
//    operator()(static_cast<const Type&>(functionType));

    os_ << "[" << primitiveType.name() << "]" << std::endl;
}


void AsgPrinter::operator()(const Return& returnStatement) const
{
	printBasic(returnStatement);

    if (returnStatement.assignment)
    {
        AsgPrinter asgPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

        asgPrinter.operator()(returnStatement.assignment.get());
    }
}

void AsgPrinter::operator()(const Scoperatore& scoperatore) const
{
	printBasic(scoperatore);
}

void AsgPrinter::operator()(const Script& script) const
{
	printBasic(script);

    for (const auto& _node: script.nodes)
    {
//            tab(indent+tabsize);
//            operator()(_node);
        boost::apply_visitor(AsgPrinter(os_, printLocationInfo_, indent_ + TAB_SIZE), _node);
    }
//        tab(indent);
}

void AsgPrinter::operator()(const Statblock& statblock) const
{
	printBasic(statblock);

    for (const auto& v : statblock.values)
    {
        boost::apply_visitor(AsgPrinter(os_, printLocationInfo_, indent_ + TAB_SIZE), v);
    }
}

void AsgPrinter::operator()(const Statement& statement) const
{
	printBasic(statement);

    boost::apply_visitor(AsgPrinter(os_, printLocationInfo_, indent_ + TAB_SIZE), statement.value);
}

void AsgPrinter::operator()(const String& string) const
{
	printBasic(string);
}

void AsgPrinter::operator()(const Switch& switchStatement) const
{
	printBasic(switchStatement);
}

void AsgPrinter::operator()(const Try& tryStatement) const
{
	printBasic(tryStatement);
}

void AsgPrinter::operator()(const std::shared_ptr<Type>& type) const
{
    operator()(*type);
}

void AsgPrinter::operator()(const Type& type) const
{
	printBasic(type, false);

    os_ << "[" << type.name() << "]" << std::endl;
}

void AsgPrinter::operator()(const Typedefinition& typedefinition) const
{
	printBasic(typedefinition);
}

void AsgPrinter::operator()(const Typemodifier& typemodifier) const
{
	printBasic(typemodifier);
}

void AsgPrinter::operator()(const UInteger& uinteger) const
{
	printBasic(uinteger, false);

    os_ << "[" << uinteger.value << "]" << std::endl;
}

void AsgPrinter::operator()(const UInteger16& uinteger16) const
{
	printBasic(uinteger16, false);

    os_ << "[" << uinteger16.value << "]" << std::endl;
}

void AsgPrinter::operator()(const UInteger32& uinteger32) const
{
	printBasic(uinteger32, false);

    os_ << "[" << uinteger32.value << "]" << std::endl;
}

void AsgPrinter::operator()(const UInteger64& uinteger64) const
{
	printBasic(uinteger64, false);

    os_ << "[" << uinteger64.value << "]" << std::endl;
}

void AsgPrinter::operator()(const UInteger8& uinteger8) const
{
	printBasic(uinteger8, false);

    os_ << "[" << static_cast<uint32_t>(uinteger8.value) << "]" << std::endl;
}

void AsgPrinter::operator()(const std::shared_ptr<UnknownType>& unknownType) const
{
	operator()(*unknownType);
}

void AsgPrinter::operator()(const UnknownType& unknownType) const
{
	printBasic(unknownType, false);
//    operator()(static_cast<const Type&>(functionType));

    os_ << "[" << toString(unknownType) << "]" << std::endl;
}

void AsgPrinter::operator()(const Variable& variable) const
{
	printBasic(variable, false);
    
    os_ << "[" << variable.symbol->name() << "]" << std::endl;

    boost::apply_visitor(AsgPrinter(os_, printLocationInfo_, indent_ + TAB_SIZE), variable.value);
}

void AsgPrinter::operator()(const Variableaccess& variableaccess) const
{
	printBasic(variableaccess, false);

    os_ << "[" << variableaccess.symbol->name() << "]" << std::endl;
}

void AsgPrinter::operator()(const Virtualproperatorerty& virtualproperatorerty) const
{
	printBasic(virtualproperatorerty);
}

void AsgPrinter::operator()(const While& whileStatement) const
{
	printBasic(whileStatement);

    AsgPrinter asgPrinter{os_, printLocationInfo_, indent_ + TAB_SIZE};

    asgPrinter.operator()(whileStatement.assign);
    asgPrinter.operator()(whileStatement.statement);
}


}}