#ifndef ICE_SCRIPT_ASG_ASGPRINTER_HPP
#define ICE_SCRIPT_ASG_ASGPRINTER_HPP

#include <string>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>
#include <boost/phoenix/core.hpp>
#include <boost/phoenix/operator.hpp>
#include <boost/phoenix/object.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/fusion/adapted/std_tuple.hpp>
#include <boost/fusion/include/io.hpp>
#include "boost/variant/static_visitor.hpp"

#include "asg/Asg.hpp"

#include "type/PrimitiveType.hpp"
#include "type/UnknownType.hpp"

namespace ice_script { namespace asg {

class AsgPrinter : public boost::static_visitor<>
{
public:
    const static int TAB_SIZE = 4;

    explicit AsgPrinter(std::ostream& os, int indent = 0) : os_(os), indent_(indent)
    {}

    AsgPrinter(std::ostream& os, bool printLocationInfo, int indent = 0)
    :
            os_(os),
            printLocationInfo_(printLocationInfo),
            indent_(indent)
    {}

    void operator()(const std::string& string) const
    {
        tab(indent_);

        os_ << typeid(std::string).name() << " " << string << std::endl;
    }

    template <typename T>
    void operator()(const boost::recursive_wrapper<T>& node) const
    {
        operator()(node.get());
    }

    template<
            typename T//,
//            typename = typename std::enable_if<std::is_base_of<asg::LocationInfo, T>::value, T>::type
    >
    void operator()(const T& node) const
    {
        printBasic(node);
    }

    template<
            typename T,
            typename std::enable_if<std::is_base_of<asg::LocationInfo, T>::value, bool>::type = true
    >
    void printBasic(const T& node, bool newline = true) const
    {
        tab(indent_);

        if (printLocationInfo_)
        {
            os_ << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
        }

        os_ << typeid(node).name();

        if (newline) os_ << std::endl;
    }

    template<
            typename T,
            typename std::enable_if<!std::is_base_of<asg::LocationInfo, T>::value, bool>::type = true
    >
    void printBasic(const T& node, bool newline = true) const
    {
        tab(indent_);

//        if (printLocationInfo_)
//        {
//            os_ << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        }

        os_ << typeid(node).name();

        if (newline) os_ << std::endl;
    }

    template<
            typename ... Ts//,
//            typename = typename std::enable_if<std::is_base_of<asg::LocationInfo, Ts>::value, Ts>::type
    >
    void operator()(const boost::variant<Ts ...>& node) const
    {
        return boost::apply_visitor(*this, node);
    }

    void operator()(const Arglist& arglist) const;
    void operator()(const Asg& asg) const;
    void operator()(const Assign& assign) const;
    void operator()(const Assignoperator& assignoperator) const;
    void operator()(const Bitoperator& bitoperator) const;
    void operator()(const Bits& bits) const;
    void operator()(const Break& breakStatement) const;
    void operator()(const Case& caseStatement) const;
    void operator()(const Cast& cast) const;
    void operator()(const Class& classData) const;
    void operator()(const Comparisonoperator& comparisonoperator) const;
    void operator()(const Condition& condition) const;
    void operator()(const Constructcall& constructcall) const;
    void operator()(const Continue& continueStatement) const;
    void operator()(const Datatype& datatype) const;
    void operator()(const Double& doubleValue) const;
    void operator()(const Dowhile& dowhile) const;
    void operator()(const Enumeration& enumeration) const;
    void operator()(const Expression& expression) const;
    void operator()(const Expressionoperatorerty& expressionoperatorerty) const;
    void operator()(const Expressionpostoperator& expressionpostoperator) const;
    void operator()(const Expressionpreoperator& expressionpreoperator) const;
    void operator()(const Expressionstat& expressionstat) const;
    void operator()(const Expressionterm& expressionterm) const;
    void operator()(const Expressionvalue& expressionvalue) const;
    void operator()(const Float& floatValue) const;
    void operator()(const For& forLoop) const;
    void operator()(const Function& function) const;
    void operator()(const std::shared_ptr<FunctionType>& functionType) const;
    void operator()(const FunctionType& functionType) const;
    void operator()(const Functionattribute& functionattribute) const;
    void operator()(const Functioncall& functioncall) const;
    void operator()(const Functiondefinition& functiondefinition) const;
    void operator()(const Identifier& identifier) const;
    void operator()(const If& ifStatement) const;
    void operator()(const Import& import) const;
    void operator()(const Initlist& initlist) const;
    void operator()(const Integer& integer) const;
    void operator()(const Integer16& integer16) const;
    void operator()(const Integer32& integer32) const;
    void operator()(const Integer64& integer64) const;
    void operator()(const Integer8& integer8) const;
    void operator()(const Interface& interfaceData) const;
    void operator()(const Interfacemethod& interfacemethod) const;
    void operator()(const Lambda& lambda) const;
    void operator()(const Literal& literal) const;
    void operator()(const Logicoperator& logicoperator) const;
    void operator()(const Mathoperator& mathoperator) const;
    void operator()(const Mixin& mixin) const;
    void operator()(const Namespace& namespaceDefinition) const;
    void operator()(const Number& number) const;
    void operator()(const std::shared_ptr<OperatorType>& operatorType) const;
    void operator()(const OperatorType& operatorType) const;
    void operator()(const Parameterlist& parameterlist) const;
    void operator()(const Primativetype& primativetype) const;
    void operator()(const PrimitiveType& primitiveType) const;
    void operator()(const std::shared_ptr<PrimitiveType>& primitiveType) const;
    void operator()(const Return& returnStatement) const;
    void operator()(const Scoperatore& scoperatore) const;
    void operator()(const Script& script) const;
    void operator()(const Statblock& statblock) const;
    void operator()(const Statement& statement) const;
    void operator()(const String& string) const;
    void operator()(const Switch& switchStatement) const;
    void operator()(const Try& tryStatement) const;
    void operator()(const std::shared_ptr<Type>& type) const;
    void operator()(const Type& type) const;
    void operator()(const Typedefinition& typedefinition) const;
    void operator()(const Typemodifier& typemodifier) const;
    void operator()(const UInteger& uinteger) const;
    void operator()(const UInteger16& uinteger16) const;
    void operator()(const UInteger32& uinteger32) const;
    void operator()(const UInteger64& uinteger64) const;
    void operator()(const UInteger8& uinteger8) const;
    void operator()(const UnknownType& unknownType) const;
    void operator()(const std::shared_ptr<UnknownType>& unknownType) const;
    void operator()(const Variable& variable) const;
    void operator()(const Variableaccess& variableaccess) const;
    void operator()(const Virtualproperatorerty& virtualproperatorerty) const;
    void operator()(const While& whileStatement) const;


private:
    void tab(int spaces) const
    {
        for (int i = 0; i < spaces; ++i)
            os_ << ' ';
    }

    std::ostream& os_;
    int indent_;
    bool printLocationInfo_;
};

}}

#endif //ICE_SCRIPT_ASG_ASGPRINTER_HPP
