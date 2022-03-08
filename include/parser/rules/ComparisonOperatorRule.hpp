#ifndef ICE_SCRIPT_COMPARISONOPERATORRULE_HPP
#define ICE_SCRIPT_COMPARISONOPERATORRULE_HPP

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>

#include "ast/CompopNode.hpp"

#include "parser/Iterator.hpp"
#include "parser/Skipper.hpp"

namespace ice_script { namespace parser { namespace rules {

struct ComparisonOperatorSymbols : boost::spirit::qi::symbols<char, ast::ComparisonOperator>
{
    ComparisonOperatorSymbols()
    {
        add
            ("==", ast::ComparisonOperator::EQUALS)
            ("!=", ast::ComparisonOperator::NOT_EQUALS)
            ("<", ast::ComparisonOperator::LESS_THAN)
            ("<=", ast::ComparisonOperator::LESS_THAN_OR_EQUALS)
            (">", ast::ComparisonOperator::GREATER_THAN)
            (">=", ast::ComparisonOperator::GREATER_THAN_OR_EQUALS)
            ("is", ast::ComparisonOperator::IS)
            ("!is", ast::ComparisonOperator::IS_NOT)
        ;
    }

} comparisonOperatorRule;

//using VarRuleType = boost::spirit::qi::rule<PositionIteratorType, ast::VarNode(), SkipperType>;
//
//extern VarRuleType varRule;

}}}

#endif //ICE_SCRIPT_COMPARISONOPERATORRULE_HPP
