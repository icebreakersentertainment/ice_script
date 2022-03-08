#include "parser/rules/NamespaceRule.hpp"
#include "parser/rules/IdentifierRule.hpp"
#include "parser/rules/ScriptRule.hpp"

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

NamespaceRuleType
    // NAMESPACE     ::= 'namespace' IDENTIFIER {'::' IDENTIFIER} '{' SCRIPT '}'
    namespaceRule = qi::eps >> string("namespace") >> _identifierRule >> _identifierRule % "::" >> lit("{") >> scriptRule.alias() >> lit("}");

}}}