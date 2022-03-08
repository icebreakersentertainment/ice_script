#ifndef ICE_SCRIPT_MATHOPERATORRULE_HPP
#define ICE_SCRIPT_MATHOPERATORRULE_HPP

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>

#include "ast/MathOpNode.hpp"

#include "parser/Iterator.hpp"
#include "parser/Skipper.hpp"

namespace ice_script { namespace parser { namespace rules {

struct MathOperatorSymbols : boost::spirit::qi::symbols<char, ast::MathOperator>
{
    MathOperatorSymbols()
    {
        add
            ("+", ast::MathOperator::ADD)
            ("-", ast::MathOperator::SUBTRACT)
            ("*", ast::MathOperator::MULTIPLY)
            ("/", ast::MathOperator::DIVIDE)
            ("**", ast::MathOperator::EXPONENT)
        ;
    }

} mathOperatorRule;

//using VarRuleType = boost::spirit::qi::rule<PositionIteratorType, ast::VarNode(), SkipperType>;
//
//extern VarRuleType varRule;

}}}

#endif //ICE_SCRIPT_MATHOPERATORRULE_HPP
