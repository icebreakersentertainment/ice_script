#include "parser/rules/StringRule.hpp"

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

StringRuleType
    // STRING        ::= single token:  single quoted ', double quoted ", or heredoc multi-line string """
    stringRule = qi::eps
            >> (
                    (lit("'") >> *(char_ - lit("'")) >> lit("'"))
                    |
                    (lit("\"") >> *(char_ - lit("\"")) >> lit("\""))
                    |
                    (lit(R"(""")") >> *(char_ - lit(R"(""")")) >> lit(R"(""")"))
            );

}}}