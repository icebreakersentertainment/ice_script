#include "parser/rules/BitsRule.hpp"

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

BitsRuleType
    // BITS          ::= single token:  binary 0b or 0B, octal 0o or 0O, decimal 0d or 0D, hexadecimal 0x or 0X
    bitsRule = qi::eps >> qi::raw[
            (char_("0") >> char_("bB") >> +char_("0-1"))
            |
            (char_("0") >> char_("oO") >> +char_("0-7"))
            |
            (char_("0") >> char_("dD") >> +char_("0-9"))
            |
            (char_("0") >> char_("xX") >> +char_("0-9a-fA-F"))
    ];

}}}