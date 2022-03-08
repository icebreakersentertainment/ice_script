#include "parser/rules/CaseRule.hpp"
#include "parser/rules/ExprRule.hpp"
#include "parser/rules/StatementRule.hpp"

namespace ice_script { namespace parser { namespace rules {

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;
using namespace boost::spirit;
using namespace boost::spirit::qi;
using qi::int_;
using qi::lit;
using qi::double_;
using qi::lexeme;
using ascii::char_;
using ascii::space;
using ascii::space_type;

static StatementRuleType _statementRule = statementRule.alias();

//using CaseStatement = boost::tuple<std::string, boost::recursive_wrapper<ast::ExprNode>>;
//
//static boost::spirit::qi::rule<PositionIteratorType, CaseStatement(), SkipperType> caseStatement = string("case") >> exprRule.alias();

CaseRuleType
    // CASE          ::= (('case' EXPR) | 'default') ':' {STATEMENT}
//    caseRule = qi::eps >> ((string("case") >> exprRule.alias()) | string("default")) >> lit(":") >> *_statementRule;
    caseRule = qi::eps >> ((string("case") >> qi::as<boost::recursive_wrapper<ast::ExprNode>>()[exprRule.alias()]) | string("default")) >> lit(":") >> *_statementRule;
//    caseRule = qi::eps >> (caseStatement | string("default")) >> lit(":") >> *_statementRule;

}}}