#ifndef ICE_SCRIPT_PARSER_RULES_TYPEMODIFIERRULE_HPP
#define ICE_SCRIPT_PARSER_RULES_TYPEMODIFIERRULE_HPP

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>

#include "type/TypeModifier.hpp"

#include "parser/Iterator.hpp"
#include "parser/Skipper.hpp"

namespace ice_script { namespace parser { namespace rules {

struct TypeModifierSymbols : boost::spirit::qi::symbols<char, TypeModifier>
{
    TypeModifierSymbols()
    {
        add
            // ("", TypeModifier::NONE)
            // ("", TypeModifier::VALUE)
            ("&", TypeModifier::REFERENCE)
            ("*", TypeModifier::POINTER)
            ("@", TypeModifier::SMART_POINTER)
        ;
    }

} typeModifierRule;

//using VarRuleType = boost::spirit::qi::rule<PositionIteratorType, ast::VarNode(), SkipperType>;
//
//extern VarRuleType varRule;

}}}

#endif /* ICE_SCRIPT_PARSER_RULES_TYPEMODIFIERRULE_HPP */
