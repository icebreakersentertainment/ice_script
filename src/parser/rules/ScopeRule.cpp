#include "parser/rules/ScopeRule.hpp"
#include "parser/rules/IdentifierRule.hpp"
#include "parser/rules/TypeRule.hpp"

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

ScopeRuleType
    // SCOPE         ::= ['::'] {IDENTIFIER '::'} [IDENTIFIER ['<' TYPE {',' TYPE} '>'] '::']
    scopeRule = qi::eps >> -(string("::"))
            >> *(identifierRule.alias() >> string("::"))
            >> -(
                    identifierRule.alias()
                    >> -(
                            lit("<") >> typeRule.alias() >> *(lit(",") >> typeRule.alias()) >> lit(">")
                    )
                    >> string("::")
            );

}}}