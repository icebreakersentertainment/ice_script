#ifndef ICE_SCRIPT_SKIPPER_HPP
#define ICE_SCRIPT_SKIPPER_HPP

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/support_line_pos_iterator.hpp>
#include <boost/spirit/include/classic_position_iterator.hpp>

#include "parser/Iterator.hpp"

namespace ice_script { namespace parser {

using SkipperType = boost::spirit::qi::rule<PositionIteratorType>;

static SkipperType blockComment = "/*" >> *(blockComment | boost::spirit::qi::char_ - "*/") > "*/";
static SkipperType singleLineComment = "//" >> *(boost::spirit::qi::char_ - boost::spirit::qi::eol) >> (boost::spirit::qi::eol | boost::spirit::qi::eoi);
static SkipperType skipper = boost::spirit::qi::space | singleLineComment | blockComment;

}}

#endif //ICE_SCRIPT_SKIPPER_HPP
