#ifndef ICE_SCRIPT_NULLSYMBOLSRULE_HPP
#define ICE_SCRIPT_NULLSYMBOLSRULE_HPP

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>

#include "ast/Null.hpp"

#include "parser/Iterator.hpp"
#include "parser/Skipper.hpp"

namespace ice_script { namespace parser { namespace rules {

struct NullSymbols : boost::spirit::qi::symbols<char, ast::Null>
{
    NullSymbols()
    {
        add
            ("null", ast::Null())
        ;
    }

} nullSymbolsRule;

}}}

#endif //ICE_SCRIPT_NULLSYMBOLSRULE_HPP
