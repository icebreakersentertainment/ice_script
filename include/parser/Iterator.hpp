#ifndef ICE_SCRIPT_ITERATOR_HPP
#define ICE_SCRIPT_ITERATOR_HPP

#include <string>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/support_line_pos_iterator.hpp>
#include <boost/spirit/include/classic_position_iterator.hpp>

using BaseIteratorType = std::string::const_iterator;
using PositionIteratorType = boost::spirit::line_pos_iterator<BaseIteratorType>;

#endif //ICE_SCRIPT_ITERATOR_HPP
