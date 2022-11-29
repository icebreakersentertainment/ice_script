#ifndef ICE_SCRIPT_ASSIGNOPERATORRULE_HPP
#define ICE_SCRIPT_ASSIGNOPERATORRULE_HPP

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>

#include "ast/AssignopNode.hpp"

#include "parser/Iterator.hpp"
#include "parser/Skipper.hpp"

namespace ice_script { namespace parser { namespace rules {

struct AssignOperatorSymbols : boost::spirit::qi::symbols<char, ast::AssignOperator>
{
    AssignOperatorSymbols()
    {
        add
            ("=", ast::AssignOperator::EQUAL)
            ("+=", ast::AssignOperator::ADD)
            ("-=", ast::AssignOperator::SUBTRACT)
            ("*=", ast::AssignOperator::MULTIPLY)
            ("/=", ast::AssignOperator::DIVIDE)
            ("|=", ast::AssignOperator::OR)
            ("&=", ast::AssignOperator::AND)
            ("^=", ast::AssignOperator::XOR)
            ("%=", ast::AssignOperator::MODULOS)
            ("**=", ast::AssignOperator::EXPONENT)
            ("<<=", ast::AssignOperator::LEFT_SHIFT)
            (">>=", ast::AssignOperator::RIGHT_SHIFT)
            (">>>=", ast::AssignOperator::ARITHMETIC_RIGHT_SHIFT)
        ;
    }

} assignOperatorRule;

//using VarRuleType = boost::spirit::qi::rule<PositionIteratorType, ast::VarNode(), SkipperType>;
//
//extern VarRuleType varRule;

}}}

#endif //ICE_SCRIPT_ASSIGNOPERATORRULE_HPP
