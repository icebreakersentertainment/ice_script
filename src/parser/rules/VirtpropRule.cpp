#include "parser/rules/VirtpropRule.hpp"
#include "parser/rules/TypeRule.hpp"
#include "parser/rules/IdentifierRule.hpp"
#include "parser/rules/FuncattrRule.hpp"
#include "parser/rules/StatblockRule.hpp"

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

VirtpropRuleType
    // VIRTPROP      ::= ['private' | 'protected'] TYPE ['&'] IDENTIFIER '{' {('get' | 'set') ['const'] FUNCATTR (STATBLOCK | ';')} '}'
    virtpropRule = qi::eps >>
            -(string("private") | string("protected"))
            >> typeRule.alias() >> -string("&") >> identifierRule.alias()
            >> lit("{")
            >> *(
                    (string("get") | string("set")) >> -string("const") >> funcattrRule.alias() >> (statblockRule.alias() | string(";"))
                )
            >> lit("}");

}}}