#include "parser/rules/ClassRule.hpp"
#include "parser/rules/IdentifierRule.hpp"
#include "parser/rules/VirtpropRule.hpp"
#include "parser/rules/FuncRule.hpp"
#include "parser/rules/VarRule.hpp"
#include "parser/rules/FuncdefRule.hpp"

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

IdentifierRuleType _identifierRule = identifierRule.alias();
FuncRuleType _funcRule = funcRule.alias();

// CLASS         ::= {'shared' | 'abstract' | 'final' | 'external'} 'class' IDENTIFIER (';' | ([':' IDENTIFIER {',' IDENTIFIER}] '{' {VIRTPROP | FUNC | VAR | FUNCDEF} '}'))
ClassRuleType classRule = qi::eps >>
            *(string("shared") | string("abstract") | string("final") | string("external"))
            >> lit("class") >> identifierRule.alias()
            >> (
                    lit(";")
                    |
                    (
                            -(lit(":") >> _identifierRule >> _identifierRule % ',')
                            >> lit("{") >> *(virtpropRule.alias() | _funcRule | varRule.alias() | funcdefRule.alias()) >> lit("}")
                    )
            )
            ;

}}}