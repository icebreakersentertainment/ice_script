#ifndef ICE_SCRIPT_BITOPRULE_HPP
#define ICE_SCRIPT_BITOPRULE_HPP

#include <string>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/support_line_pos_iterator.hpp>

#include "ast/BitopNode.hpp"

#include "parser/Iterator.hpp"
#include "parser/Skipper.hpp"

namespace ice_script { namespace parser { namespace rules {

using BitopRuleType = boost::spirit::qi::rule<PositionIteratorType, ast::BitopNode(), SkipperType>;

extern BitopRuleType bitopRule;

}}}

#endif //ICE_SCRIPT_BITOPRULE_HPP