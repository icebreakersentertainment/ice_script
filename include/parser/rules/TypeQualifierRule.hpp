#ifndef ICE_SCRIPT_PARSER_RULES_TYPEQUALIFIERRULE_HPP
#define ICE_SCRIPT_PARSER_RULES_TYPEQUALIFIERRULE_HPP

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>

#include "type/TypeQualifier.hpp"

#include "parser/Iterator.hpp"
#include "parser/Skipper.hpp"

namespace ice_script { namespace parser { namespace rules {

struct TypeQualifierSymbols : boost::spirit::qi::symbols<char, TypeQualifier::TypeQualifierFlags>
{
    TypeQualifierSymbols()
    {
        add
            // ("", TypeQualifier::NONE)
            ("const", TypeQualifier::CONSTANT)
            // ("||", TypeQualifier::VOLATILE)
        ;
    }

} typeQualifierRule;

//using VarRuleType = boost::spirit::qi::rule<PositionIteratorType, ast::VarNode(), SkipperType>;
//
//extern VarRuleType varRule;

}}}

#endif /* ICE_SCRIPT_PARSER_RULES_TYPEQUALIFIERRULE_HPP */
