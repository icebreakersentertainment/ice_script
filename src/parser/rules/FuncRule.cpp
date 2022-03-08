#include "parser/rules/FuncRule.hpp"
#include "parser/rules/TypeRule.hpp"
#include "parser/rules/IdentifierRule.hpp"
#include "parser/rules/ParamlistRule.hpp"
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

// FUNC          ::= {'shared' | 'external'} ['private' | 'protected'] [((TYPE ['&']) | '~')] IDENTIFIER PARAMLIST ['const'] FUNCATTR (';' | STATBLOCK)
FuncRuleType funcRule = qi::eps >> *(string("shared") | string("external"))
            >> -(string("private") | string("protected"))
            >> -(
                   as<ast::TupleTypeOptionalStringType>()[(typeRule.alias() >> -string("&"))] | as_string[string("~")]
            )
            >> identifierRule.alias() >> paramlistRule.alias() >> -string("const") >> funcattrRule.alias()
            >> (lit(";") | statblockRule.alias());

}}}