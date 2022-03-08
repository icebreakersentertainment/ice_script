#include "parser/rules/FuncattrRule.hpp"

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

// FUNCATTR      ::= {'override' | 'final' | 'explicit' | 'property'}
FuncattrRuleType funcattrRule = qi::eps >> *(string("override") | string("final") | string("explicit") | string("property"));
//    funcattrRule = lit("WTF") >> *(string("override") | string("final") | string("explicit") | string("property"));

}}}