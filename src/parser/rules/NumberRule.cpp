//#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
//#define BOOST_MPL_LIMIT_LIST_SIZE 50
//
//#include <boost/spirit/include/qi.hpp>
//#include <boost/spirit/include/support_line_pos_iterator.hpp>
//
//#include "parser/Test.hpp"
#include "parser/rules/NumberRule.hpp"

namespace ice_script { namespace parser { namespace rules {

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;
using namespace boost::spirit;
using namespace boost::spirit::qi;
using qi::int_;
using qi::lit;
using qi::double_;
using qi::lexeme;
using ascii::char_;
using ascii::space;
using ascii::space_type;

//boost::spirit::qi::rule<PositionIteratorType, std::string(), boost::spirit::ascii::space_type> assignRule3 = boost::spirit::qi::char_("0-9");
//boost::spirit::qi::rule<PositionIteratorType, std::string(), boost::spirit::ascii::space_type> assignRule3_ = assignRule3.copy();

boost::spirit::qi::rule<PositionIteratorType, ast::NumberNode(), SkipperType>
    // NUMBER        ::= single token:  includes integers and real numbers, same as C++
//    numberRule<PositionIteratorType> = qi::eps >> lexeme[+char_("0-9") >> -(char_(".") >> +char_("0-9"))];
    numberRule = qi::eps >> lexeme[+char_("0-9") >> -(char_(".") >> +char_("0-9"))];
//    numberRule = qi::eps >> +char_("0-9");
//    numberRule = qi::eps >> as_string[+assignRule3 >> -assignRule4];

}}}
