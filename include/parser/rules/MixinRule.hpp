#ifndef ICE_SCRIPT_MIXINRULE_HPP
#define ICE_SCRIPT_MIXINRULE_HPP

#include <string>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/support_line_pos_iterator.hpp>

#include "ast/MixinNode.hpp"

#include "parser/Iterator.hpp"
#include "parser/Skipper.hpp"

namespace ice_script { namespace parser { namespace rules {

using MixinRuleType = boost::spirit::qi::rule<PositionIteratorType, ast::MixinNode(), SkipperType>;

extern MixinRuleType mixinRule;

}}}

#endif //ICE_SCRIPT_MIXINRULE_HPP