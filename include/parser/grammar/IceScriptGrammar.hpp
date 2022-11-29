#ifndef ICE_SCRIPT_ICESCRIPTGRAMMAR_HPP
#define ICE_SCRIPT_ICESCRIPTGRAMMAR_HPP

#include <string>
#include <iomanip>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/spirit/include/support_line_pos_iterator.hpp>
#include <boost/spirit/include/classic_position_iterator.hpp>
#include <boost/phoenix/core.hpp>
#include <boost/phoenix/operator.hpp>
#include <boost/phoenix/object.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/fusion/adapted/std_tuple.hpp>
#include <boost/fusion/include/io.hpp>

//#include "parser/grammar/AbstractGrammar.hpp"

#include "ast/LocationInfo.hpp"

#include "parser/AnnotationFunction.hpp"
#include "parser/ErrorHandlerFunction.hpp"

#include "parser/rules/ScriptRule.hpp"
#include "parser/rules/ClassRule.hpp"
#include "parser/rules/TypedefRule.hpp"
#include "parser/rules/NamespaceRule.hpp"
#include "parser/rules/FuncRule.hpp"
#include "parser/rules/InterfaceRule.hpp"
#include "parser/rules/VarRule.hpp"
#include "parser/rules/ImportRule.hpp"
#include "parser/rules/EnumRule.hpp"
#include "parser/rules/FuncdefRule.hpp"
#include "parser/rules/VirtpropRule.hpp"
#include "parser/rules/MixinRule.hpp"
#include "parser/rules/IntfmthdRule.hpp"
#include "parser/rules/StatblockRule.hpp"
#include "parser/rules/ParamlistRule.hpp"
#include "parser/rules/TypemodRule.hpp"
#include "parser/rules/TypeRule.hpp"
#include "parser/rules/InitlistRule.hpp"
#include "parser/rules/ScopeRule.hpp"
#include "parser/rules/DatatypeRule.hpp"
#include "parser/rules/PrimtypeRule.hpp"
#include "parser/rules/FuncattrRule.hpp"
#include "parser/rules/StatementRule.hpp"
#include "parser/rules/SwitchRule.hpp"
#include "parser/rules/BreakRule.hpp"
#include "parser/rules/ForRule.hpp"
#include "parser/rules/WhileRule.hpp"
#include "parser/rules/DowhileRule.hpp"
#include "parser/rules/IfRule.hpp"
#include "parser/rules/ContinueRule.hpp"
#include "parser/rules/ExprstatRule.hpp"
#include "parser/rules/TryRule.hpp"
#include "parser/rules/ReturnRule.hpp"
#include "parser/rules/CaseRule.hpp"
#include "parser/rules/ExprRule.hpp"
#include "parser/rules/ExprtermRule.hpp"
#include "parser/rules/ExprvalueRule.hpp"
#include "parser/rules/ConstructcallRule.hpp"
#include "parser/rules/ExprpreopRule.hpp"
#include "parser/rules/ExprpostopRule.hpp"
#include "parser/rules/CastRule.hpp"
#include "parser/rules/LambdaRule.hpp"
#include "parser/rules/LiteralRule.hpp"
#include "parser/rules/FunccallRule.hpp"
#include "parser/rules/VaraccessRule.hpp"
#include "parser/rules/ArglistRule.hpp"
#include "parser/rules/AssignRule.hpp"
#include "parser/rules/ConditionRule.hpp"
#include "parser/rules/ExpropRule.hpp"
#include "parser/rules/BitopRule.hpp"
#include "parser/rules/MathopRule.hpp"
#include "parser/rules/CompopRule.hpp"
#include "parser/rules/LogicopRule.hpp"
#include "parser/rules/AssignopRule.hpp"
#include "parser/rules/IdentifierRule.hpp"
#include "parser/rules/NumberRule.hpp"
#include "parser/rules/StringRule.hpp"
#include "parser/rules/BitsRule.hpp"
#include "parser/rules/BoolRule.hpp"
#include "parser/rules/NullRule.hpp"
#include "parser/rules/VoidRule.hpp"

#include "parser/Iterator.hpp"
#include "parser/Skipper.hpp"

#include "ast/Root.hpp"
//#include "ast/Ast.hpp"

#include "detail/Format.hpp"

namespace ice_script { namespace parser { namespace grammar {

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

using namespace ice_script::parser::rules;
using namespace ice_script::ast;

struct IceScriptGrammar : boost::spirit::qi::grammar<PositionIteratorType, ast::Root(), SkipperType>
{
    explicit IceScriptGrammar(PositionIteratorType it);

    boost::phoenix::function<error_handler_f> handler;
    boost::phoenix::function<annotation_f<PositionIteratorType>> annotate;

    boost::spirit::qi::rule<PositionIteratorType, ast::Root(), SkipperType> start;
//    ScriptRuleType scriptRule_ = ice_script::parser::rules::scriptRule;
//    ClassRuleType classRule_ = ice_script::parser::rules::classRule;
//    TypedefRuleType typedefRule_ = ice_script::parser::rules::typedefRule;
//    NamespaceRuleType namespaceRule_ = ice_script::parser::rules::namespaceRule;
//    FuncRuleType funcRule_ = ice_script::parser::rules::funcRule;
//    InterfaceRuleType interfaceRule_ = ice_script::parser::rules::interfaceRule;
//    VarRuleType varRule_ = ice_script::parser::rules::varRule;
//    ImportRuleType importRule_ = ice_script::parser::rules::importRule;
//    EnumRuleType enumRule_ = ice_script::parser::rules::enumRule;
//    FuncdefRuleType funcdefRule_ = ice_script::parser::rules::funcdefRule;
//    VirtpropRuleType virtpropRule_ = ice_script::parser::rules::virtpropRule;
//    MixinRuleType mixinRule_ = ice_script::parser::rules::mixinRule;
//    IntfmthdRuleType intfmthdRule_ = ice_script::parser::rules::intfmthdRule;
//    StatblockRuleType statblockRule_ = ice_script::parser::rules::statblockRule;
//    ParamlistRuleType paramlistRule_ = ice_script::parser::rules::paramlistRule;
//    TypemodRuleType typemodRule_ = ice_script::parser::rules::typemodRule;
//    TypeRuleType typeRule_ = ice_script::parser::rules::typeRule;
//    InitlistRuleType initlistRule_ = ice_script::parser::rules::initlistRule;
//    ScopeRuleType scopeRule_ = ice_script::parser::rules::scopeRule;
//    DatatypeRuleType datatypeRule_ = ice_script::parser::rules::datatypeRule;
//    PrimtypeRuleType primtypeRule_ = ice_script::parser::rules::primtypeRule;
//    FuncattrRuleType funcattrRule_ = ice_script::parser::rules::funcattrRule;
//    StatementRuleType statementRule_ = ice_script::parser::rules::statementRule;
//    SwitchRuleType switchRule_ = ice_script::parser::rules::switchRule;
//    BreakRuleType breakRule_ = ice_script::parser::rules::breakRule;
//    ForRuleType forRule_ = ice_script::parser::rules::forRule;
//    WhileRuleType whileRule_ = ice_script::parser::rules::whileRule;
//    DowhileRuleType dowhileRule_ = ice_script::parser::rules::dowhileRule;
//    IfRuleType ifRule_ = ice_script::parser::rules::ifRule;
//    ContinueRuleType continueRule_ = ice_script::parser::rules::continueRule;
//    ExprstatRuleType exprstatRule_ = ice_script::parser::rules::exprstatRule;
//    TryRuleType tryRule_ = ice_script::parser::rules::tryRule;
//    ReturnRuleType returnRule_ = ice_script::parser::rules::returnRule;
//    CaseRuleType caseRule_ = ice_script::parser::rules::caseRule;
//    ExprRuleType exprRule_ = ice_script::parser::rules::exprRule;
//    ExprtermRuleType exprtermRule_ = ice_script::parser::rules::exprtermRule;
//    ExprvalueRuleType exprvalueRule_ = ice_script::parser::rules::exprvalueRule;
//    ConstructcallRuleType constructcallRule_ = ice_script::parser::rules::constructcallRule;
//    ExprpreopRuleType exprpreopRule_ = ice_script::parser::rules::exprpreopRule;
//    ExprpostopRuleType exprpostopRule_ = ice_script::parser::rules::exprpostopRule;
//    CastRuleType castRule_ = ice_script::parser::rules::castRule;
//    LambdaRuleType lambdaRule_ = ice_script::parser::rules::lambdaRule;
//    LiteralRuleType literalRule_ = ice_script::parser::rules::literalRule;
//    FunccallRuleType funccallRule_ = ice_script::parser::rules::funccallRule;
//    VaraccessRuleType varaccessRule_ = ice_script::parser::rules::varaccessRule;
//    ArglistRuleType arglistRule_ = ice_script::parser::rules::arglistRule;
//    AssignRuleType assignRule_ = ice_script::parser::rules::assignRule;
//    ConditionRuleType conditionRule_ = ice_script::parser::rules::conditionRule;
//    ExpropRuleType expropRule_ = ice_script::parser::rules::expropRule;
//    BitopRuleType bitopRule_ = ice_script::parser::rules::bitopRule;
//    MathopRuleType mathopRule_ = ice_script::parser::rules::mathopRule;
//    CompopRuleType compopRule_ = ice_script::parser::rules::compopRule;
//    LogicopRuleType logicopRule_ = ice_script::parser::rules::logicopRule;
//    AssignopRuleType assignopRule_ = ice_script::parser::rules::assignopRule;
//    IdentifierRuleType identifierRule_ = ice_script::parser::rules::identifierRule;
//    NumberRuleType numberRule_ = ice_script::parser::rules::numberRule;
//    StringRuleType stringRule_ = ice_script::parser::rules::stringRule;
//    BitsRuleType bitsRule_ = ice_script::parser::rules::bitsRule;
//    BoolRuleType boolRule_ = ice_script::parser::rules::boolRule;
//    NullRuleType nullRule_ = ice_script::parser::rules::nullRule;
//    VoidRuleType voidRule_ = ice_script::parser::rules::voidRule;
};

}}}

#endif //ICE_SCRIPT_ICESCRIPTGRAMMAR_HPP