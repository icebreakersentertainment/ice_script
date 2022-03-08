#ifndef ICE_SCRIPT_LOGICOPERATORRULE_HPP
#define ICE_SCRIPT_LOGICOPERATORRULE_HPP

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>

#include "ast/LogicopNode.hpp"

#include "parser/Iterator.hpp"
#include "parser/Skipper.hpp"

namespace ice_script { namespace parser { namespace rules {

struct LogicOperatorSymbols : boost::spirit::qi::symbols<char, ast::LogicOperator>
{
    LogicOperatorSymbols()
    {
        add
            ("&&", ast::LogicOperator::AND)
            ("and", ast::LogicOperator::AND)
            ("||", ast::LogicOperator::OR)
            ("or", ast::LogicOperator::OR)
            ("^^", ast::LogicOperator::XOR)
            ("xor", ast::LogicOperator::XOR)
            ("!", ast::LogicOperator::NOT)
            ("not", ast::LogicOperator::NOT)
        ;
    }

} logicOperatorRule;

//using VarRuleType = boost::spirit::qi::rule<PositionIteratorType, ast::VarNode(), SkipperType>;
//
//extern VarRuleType varRule;

}}}

#endif //ICE_SCRIPT_LOGICOPERATORRULE_HPP
