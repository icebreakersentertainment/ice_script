#ifndef ICE_SCRIPT_VOIDSYMBOLSRULE_HPP
#define ICE_SCRIPT_VOIDSYMBOLSRULE_HPP

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>

#include "ast/Void.hpp"

#include "parser/Iterator.hpp"
#include "parser/Skipper.hpp"

namespace ice_script { namespace parser { namespace rules {

struct VoidSymbols : boost::spirit::qi::symbols<char, ast::Void>
{
    VoidSymbols()
    {
        add
            ("void", ast::Void())
        ;
    }

} voidSymbolsRule;

}}}

#endif //ICE_SCRIPT_VOIDSYMBOLSRULE_HPP
