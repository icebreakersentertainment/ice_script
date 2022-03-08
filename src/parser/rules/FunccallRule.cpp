#include "parser/rules/FunccallRule.hpp"
#include "parser/rules/ScopeRule.hpp"
#include "parser/rules/IdentifierRule.hpp"
#include "parser/rules/ArglistRule.hpp"

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

static IdentifierRuleType _identifierRule = identifierRule.alias();

// FUNCCALL      ::= SCOPE IDENTIFIER ARGLIST
FunccallRuleType funccallRule = scopeRule.alias() >> _identifierRule >> arglistRule.alias();

}}}