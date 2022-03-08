#ifndef ICE_SCRIPT_LLVMIRVISITOR_HPP
#define ICE_SCRIPT_LLVMIRVISITOR_HPP

#include <string>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/variant/static_visitor.hpp>

#include "asg/Asg.hpp"

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "logger/ILogger.hpp"

struct monostate {};

namespace ice_script { namespace generator { namespace llvm {

using LlvmIrVisitorReturnType = boost::variant<
        monostate,
        std::string,
        ::llvm::Value*
>;

class LlvmIrVisitor : public boost::static_visitor<LlvmIrVisitorReturnType>
{
public:
    LlvmIrVisitor(logger::ILogger& logger, std::shared_ptr<Context> context2, std::shared_ptr<Llvm> llvm);

    LlvmIrVisitorReturnType operator()(const std::string& string) const;

    LlvmIrVisitorReturnType operator()(const boost::spirit::qi::unused_type& unusedType) const
    {
        std::cout << "wtf: " << typeid(unusedType).name() << std::endl;

        return {};
    }

    template <typename T>
    LlvmIrVisitorReturnType operator()(const boost::recursive_wrapper<T>& node) const
    {
        return operator()(node.get());
    }

    template <typename T>
    LlvmIrVisitorReturnType operator()(const T& node) const
    {
//        os_ << typeid(node).name() << " " << node.value << std::endl;
        std::cout << "asdf: " << typeid(node).name() << std::endl;

        return {};
    }

    template<
            typename ... Us//,
//            typename = typename std::enable_if<std::is_base_of<ast::LocationInfo, Ts>::value, Ts>::type
    >
    LlvmIrVisitorReturnType operator()(const boost::variant<Us ...>& node) const
    {
        return boost::apply_visitor(*this, node);
    }

    LlvmIrVisitorReturnType operator()(const asg::Asg& asg) const;
    LlvmIrVisitorReturnType operator()(const asg::Script& script) const;
//    LlvmIrVisitorReturnType operator()(const asg::Class& classData) const;
    LlvmIrVisitorReturnType operator()(const asg::Typedefinition& typedefinition) const;
//    LlvmIrVisitorReturnType operator()(const asg::Namespace& namespaceDefinition) const;
    LlvmIrVisitorReturnType operator()(const asg::Function& function) const;
//    LlvmIrVisitorReturnType operator()(const asg::Interface& interfaceData) const;
    LlvmIrVisitorReturnType operator()(const asg::Variable& variable) const;
    LlvmIrVisitorReturnType operator()(const asg::Import& import) const;
    LlvmIrVisitorReturnType operator()(const asg::Enumeration& enumeration) const;
    LlvmIrVisitorReturnType operator()(const asg::Functiondefinition& functiondefinition) const;
    LlvmIrVisitorReturnType operator()(const asg::Virtualproperatorerty& virtualproperatorerty) const;
    LlvmIrVisitorReturnType operator()(const asg::Mixin& mixin) const;
    LlvmIrVisitorReturnType operator()(const asg::Interfacemethod& interfacemethod) const;
    LlvmIrVisitorReturnType operator()(const asg::Statblock& statblock) const;
    LlvmIrVisitorReturnType operator()(const asg::Parameterlist& parameterlist) const;
    LlvmIrVisitorReturnType operator()(const asg::Typemodifier& typemodifier) const;
    LlvmIrVisitorReturnType operator()(const asg::Type& type) const;
    LlvmIrVisitorReturnType operator()(const asg::Initlist& initlist) const;
    LlvmIrVisitorReturnType operator()(const asg::Scoperatore& scoperatore) const;
    LlvmIrVisitorReturnType operator()(const asg::Datatype& datatype) const;
    LlvmIrVisitorReturnType operator()(const asg::Primativetype& primativetype) const;
    LlvmIrVisitorReturnType operator()(const asg::Functionattribute& functionattribute) const;
    LlvmIrVisitorReturnType operator()(const asg::Statement& statement) const;
//    LlvmIrVisitorReturnType operator()(const asg::Switch& switchStatement) const;
//    LlvmIrVisitorReturnType operator()(const asg::Break& breakStatement) const;
//    LlvmIrVisitorReturnType operator()(const asg::For& forLoop) const;
//    LlvmIrVisitorReturnType operator()(const asg::While& whileStatement) const;
    LlvmIrVisitorReturnType operator()(const asg::Dowhile& dowhile) const;
//    LlvmIrVisitorReturnType operator()(const asg::If& ifStatement) const;
//    LlvmIrVisitorReturnType operator()(const asg::Continue& continueStatement) const;
    LlvmIrVisitorReturnType operator()(const asg::Expressionstat& expressionstat) const;
//    LlvmIrVisitorReturnType operator()(const asg::Try& tryStatement) const;
    LlvmIrVisitorReturnType operator()(const asg::Return& ret) const;
//    LlvmIrVisitorReturnType operator()(const asg::Case& caseStatement) const;
    LlvmIrVisitorReturnType operator()(const asg::Expression& expression) const;
    LlvmIrVisitorReturnType operator()(const asg::Expressionterm& expressionterm) const;
    LlvmIrVisitorReturnType operator()(const asg::Expressionvalue& expressionvalue) const;
    LlvmIrVisitorReturnType operator()(const asg::Constructcall& constructcall) const;
    LlvmIrVisitorReturnType operator()(const asg::Expressionpreoperator& expressionpreoperator) const;
    LlvmIrVisitorReturnType operator()(const asg::Expressionpostoperator& expressionpostoperator) const;
    LlvmIrVisitorReturnType operator()(const asg::Cast& cast) const;
    LlvmIrVisitorReturnType operator()(const asg::Lambda& lambda) const;
    LlvmIrVisitorReturnType operator()(const asg::Literal& literal) const;
    LlvmIrVisitorReturnType operator()(const asg::Functioncall& functioncall) const;
    LlvmIrVisitorReturnType operator()(const asg::Variableaccess& variableaccess) const;
    LlvmIrVisitorReturnType operator()(const asg::Arglist& arglist) const;
    LlvmIrVisitorReturnType operator()(const asg::Assign& assign) const;
    LlvmIrVisitorReturnType operator()(const asg::Condition& condition) const;
    LlvmIrVisitorReturnType operator()(const asg::Expressionoperatorerty& expressionoperatorerty) const;
    LlvmIrVisitorReturnType operator()(const asg::Bitoperator& bitoperator) const;
//    LlvmIrVisitorReturnType operator()(const asg::Mathoperator& mathoperator) const;
//    LlvmIrVisitorReturnType operator()(const asg::Comparisonoperator& comparisonoperator) const;
//    LlvmIrVisitorReturnType operator()(const asg::Logicoperator& logicoperator) const;
    LlvmIrVisitorReturnType operator()(const asg::Assignoperator& assignoperator) const;
    LlvmIrVisitorReturnType operator()(const asg::Identifier& identifier) const;
    LlvmIrVisitorReturnType operator()(const asg::Number& number) const;
    LlvmIrVisitorReturnType operator()(const asg::String& string) const;
    LlvmIrVisitorReturnType operator()(const asg::Bits& bits) const;

private:
    logger::ILogger* logger_;
    std::shared_ptr<Context> context_;
    std::shared_ptr<Llvm> llvm_;

    std::vector<::llvm::Type*> createParameterTypeList(const std::vector<asg::Variable>& parameters) const;
    ::llvm::Type* toLlvmType(const asg::Type& type) const;

//    std::vector<::llvm::Type*> createParameterTypeList(const ast::ParamlistNode& node) const;

//    void generate(const ast::FuncNode& node, Scope& scope) const;
//    void generate(const ast::StatblockNode& node, Scope& scope) const;
//    void generate(const ast::VarNode& node, Scope& scope) const;
};

}}}

#endif //ICE_SCRIPT_LLVMIRVISITOR_HPP
