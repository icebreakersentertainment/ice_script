#include "parser/rules/ImportRule.hpp"
#include "parser/rules/TypeRule.hpp"
#include "parser/rules/IdentifierRule.hpp"
#include "parser/rules/ParamlistRule.hpp"
#include "parser/rules/FuncattrRule.hpp"
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

// IMPORT        ::= 'import' TYPE ['&'] IDENTIFIER PARAMLIST FUNCATTR 'from' STRING ';'
//    importRule = qi::eps >> lit("import") >> typeRule.alias() >> -string("&") >> identifierRule.alias() >> paramlistRule.alias() >> funcattrRule.alias() >> lit("from") >> stringRule.alias() >> lit(";");
ImportRuleType importRule = qi::eps >> string("import") > typeRule.alias() > -string("&") > identifierRule.alias() > paramlistRule.alias() > funcattrRule.alias() > lit("from") > stringRule.alias() > lit(";");
}}}