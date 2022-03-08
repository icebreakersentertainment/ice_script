#include "parser/rules/TypeRule.hpp"
#include "parser/rules/ScopeRule.hpp"
#include "parser/rules/DatatypeRule.hpp"

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

// TYPE          ::= ['const'] SCOPE DATATYPE ['<' TYPE {',' TYPE} '>'] { ('[' ']') | ('@' ['const']) }
//    typeRule = qi::eps >> -string("const") >> scopeRule.alias() >> datatypeRule.alias() >> -(lit("<") >> typeRule >> typeRule % ',' >> lit(">")) >> *( as_string[string("[") >> string("]")] | (as_string[string("@")] >> -as_string[string("const")]) );
TypeRuleType typeRule = qi::eps >> -string("const") >> scopeRule.alias() >> datatypeRule.alias() >> -(lit("<") >> typeRule % ',' >> lit(">")) >> *( as_string[string("[") >> string("]")] | (as_string[string("@")] >> -as_string[string("const")]) );

}}}