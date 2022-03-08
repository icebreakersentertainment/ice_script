#include "parser/rules/InterfaceRule.hpp"
#include "parser/rules/IdentifierRule.hpp"
#include "parser/rules/VirtpropRule.hpp"
#include "parser/rules/IntfmthdRule.hpp"

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
static IntfmthdRuleType _intfmthdRule = intfmthdRule.alias();

InterfaceRuleType
    // INTERFACE     ::= {'external' | 'shared'} 'interface' IDENTIFIER (';' | ([':' IDENTIFIER {',' IDENTIFIER}] '{' {VIRTPROP | INTFMTHD} '}'))
    interfaceRule = qi::eps >>
            *(string("external") | string("shared"))
            >> lit("interface") >> _identifierRule
            >> (
                    lit(";")
                    |
                    (
                            -(lit(":") >> _identifierRule % ',')
                            >> lit("{") >> *(virtpropRule.alias() | _intfmthdRule) >> lit("}")
                    )
            );

}}}