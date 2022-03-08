#ifndef ICE_SCRIPT_BITSRULE_HPP
#define ICE_SCRIPT_BITSRULE_HPP

#include <string>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/support_line_pos_iterator.hpp>

#include "ast/BitsNode.hpp"

#include "parser/Iterator.hpp"
#include "parser/Skipper.hpp"

namespace ice_script { namespace parser { namespace rules {

using BitsRuleType = boost::spirit::qi::rule<PositionIteratorType, ast::BitsNode(), SkipperType>;

extern BitsRuleType bitsRule;

}}}

#endif //ICE_SCRIPT_BITSRULE_HPP