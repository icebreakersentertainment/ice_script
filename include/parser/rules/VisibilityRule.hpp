#ifndef ICE_SCRIPT_VISIBILITYRULE_HPP
#define ICE_SCRIPT_VISIBILITYRULE_HPP

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>

#include "ast/VarNode.hpp"

#include "parser/Iterator.hpp"
#include "parser/Skipper.hpp"

namespace ice_script { namespace parser { namespace rules {

struct VisibilitySymbols : boost::spirit::qi::symbols<char, ast::Visibility>
{
    VisibilitySymbols()
    {
        add
            ("public", ast::Visibility::PUBLIC)
            ("private", ast::Visibility::PRIVATE)
            ("protected", ast::Visibility::PROTECTED)
        ;
    }

} visibilitySymbols;

//using VarRuleType = boost::spirit::qi::rule<PositionIteratorType, ast::VarNode(), SkipperType>;
//
//extern VarRuleType varRule;

}}}

#endif //ICE_SCRIPT_VISIBILITYRULE_HPP
