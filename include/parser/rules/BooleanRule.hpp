#ifndef ICE_SCRIPT_BOOLEANRULE_HPP
#define ICE_SCRIPT_BOOLEANRULE_HPP

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>

#include "ast/Boolean.hpp"

#include "parser/Iterator.hpp"
#include "parser/Skipper.hpp"

namespace ice_script { namespace parser { namespace rules {

struct BooleanSymbols : boost::spirit::qi::symbols<char, ast::Boolean>
{
    BooleanSymbols()
    {
        add
            ("true", ast::Boolean(true))
            ("false", ast::Boolean(false))
        ;
    }

} booleanRule;

}}}

#endif //ICE_SCRIPT_BOOLEANRULE_HPP
