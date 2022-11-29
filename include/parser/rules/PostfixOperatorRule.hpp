#ifndef ICE_SCRIPT_POSTFIXOPERATORRULE_HPP
#define ICE_SCRIPT_POSTFIXOPERATORRULE_HPP

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>

#include "ast/PostfixOperator.hpp"

#include "parser/Iterator.hpp"
#include "parser/Skipper.hpp"

namespace ice_script { namespace parser { namespace rules {

struct PostfixOperatorSymbols : boost::spirit::qi::symbols<char, ast::PostfixOperator>
{
    PostfixOperatorSymbols()
    {
        add
            ("++", ast::PostfixOperator::INCREMENT)
            ("--", ast::PostfixOperator::DECREMENT)
        ;
    }

} postfixOperatorRule;

//using VarRuleType = boost::spirit::qi::rule<PositionIteratorType, ast::VarNode(), SkipperType>;
//
//extern VarRuleType varRule;

}}}

#endif //ICE_SCRIPT_POSTFIXOPERATORRULE_HPP
