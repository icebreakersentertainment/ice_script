#ifndef ICE_SCRIPT_BITWISEOPERATORRULE_HPP
#define ICE_SCRIPT_BITWISEOPERATORRULE_HPP

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>

#include "ast/BitopNode.hpp"

#include "parser/Iterator.hpp"
#include "parser/Skipper.hpp"

namespace ice_script { namespace parser { namespace rules {

struct BitwiseOperatorSymbols : boost::spirit::qi::symbols<char, ast::BitwiseOperator>
{
    BitwiseOperatorSymbols()
    {
        add
            ("~", ast::BitwiseOperator::COMPLEMENT)
            ("&", ast::BitwiseOperator::AND)
            ("|", ast::BitwiseOperator::OR)
            ("^", ast::BitwiseOperator::XOR)
            ("<<", ast::BitwiseOperator::LEFT_SHIFT)
            (">>", ast::BitwiseOperator::RIGHT_SHIFT)
            (">>>", ast::BitwiseOperator::ARITHMETIC_RIGHT_SHIFT)
        ;
    }

} bitwiseOperatorRule;

//using VarRuleType = boost::spirit::qi::rule<PositionIteratorType, ast::VarNode(), SkipperType>;
//
//extern VarRuleType varRule;

}}}

#endif //ICE_SCRIPT_BITWISEOPERATORRULE_HPP
