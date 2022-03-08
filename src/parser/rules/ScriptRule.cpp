#include "parser/rules/ScriptRule.hpp"
#include "parser/rules/ImportRule.hpp"
#include "parser/rules/EnumRule.hpp"
#include "parser/rules/TypedefRule.hpp"
#include "parser/rules/ClassRule.hpp"
#include "parser/rules/MixinRule.hpp"
#include "parser/rules/InterfaceRule.hpp"
#include "parser/rules/FuncdefRule.hpp"
#include "parser/rules/VirtpropRule.hpp"
#include "parser/rules/VarRule.hpp"
#include "parser/rules/FuncRule.hpp"
#include "parser/rules/NamespaceRule.hpp"

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

static EnumRuleType _enumRule = enumRule.alias();

// SCRIPT        ::= {IMPORT | ENUM | TYPEDEF | CLASS | MIXIN | INTERFACE | FUNCDEF | VIRTPROP | VAR | FUNC | NAMESPACE | ';'}
ScriptRuleType scriptRule = qi::eps >> *(importRule.alias() | _enumRule | typedefRule.alias() | classRule.alias() | mixinRule.alias() | interfaceRule.alias() | funcdefRule.alias() | virtpropRule.alias() | varRule.alias() | funcRule.alias() | namespaceRule.alias() | as_string[string(";")]);

}}}