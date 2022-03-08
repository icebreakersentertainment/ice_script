#ifndef ICE_SCRIPT_ABSTRACTPARSER_INL
#define ICE_SCRIPT_ABSTRACTPARSER_INL

#include <string>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>
#include <boost/phoenix/core.hpp>
#include <boost/phoenix/operator.hpp>
#include <boost/phoenix/object.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/fusion/adapted/std_tuple.hpp>
#include <boost/fusion/include/io.hpp>
#include "boost/variant/static_visitor.hpp"

#include "ast/Ast.hpp"

namespace ice_script { namespace parser {

template <typename Iterator, typename Expression, typename Skipper, typename Attribute>
Attribute AbstractParser<Iterator, Expression, Skipper, Attribute>::parse(Iterator& first, Iterator last, const Expression& expression, const Skipper& skipper)
{
    Iterator begin{first};

    Attribute attribute;

    const bool r = boost::spirit::qi::phrase_parse(first, last, expression, skipper, attribute);
//    bool r;
//    try
//    {
//        r = boost::spirit::qi::phrase_parse(position_it, position_end, expression, boost::spirit::ascii::space, attribute);
//    }
//    catch (const qi::expectation_failure<pos_iterator_type>& e)
//    {
////            const classic::file_position_base<std::string>& pos = e.first.get_position();
////
////            std::stringstream msg;
////
////            msg <<
////                "parse error at file " << pos.file <<
////                " line " << pos.line << " column " << pos.column << std::endl <<
////                "'" << e.first.get_currentline() << "'" << std::endl <<
////                std::setw(pos.column) << " " << "^- here";
////
////            throw std::runtime_error(msg.str());
//        throw e;
//    }

    if (!r || start != last)
    {
        int line   = get_line(start);
        int column = get_column(begin, last);
        const auto message = detail::format("Error during parsing line %s column %s.", line, column);
        throw std::runtime_error(message);
    }

    return attribute;
}

template <typename Iterator, typename Expression, typename Skipper, typename Attribute>
//template <typename Expression, typename Attribute>
Attribute AbstractParser<Iterator, Expression, Skipper, Attribute>::parse(Expression& expression, Skipper& skipper, const std::string& script)
{
//    using namespace boost::spirit::qi;
//    using boost::spirit::ascii::space;

    // iterate over stream input
//        typedef std::istreambuf_iterator<char> base_iterator_type;
//        typedef std::istream_iterator<char> base_iterator_type;
    typedef std::string::const_iterator base_iterator_type;
//        typedef boost::spirit::multi_pass<base_iterator_type> forward_iterator_type;
    typedef boost::spirit::line_pos_iterator<base_iterator_type> pos_iterator_type;
//        typedef classic::position_iterator2<forward_iterator_type> pos_iterator_type;

//        const base_iterator_type in_begin(inputStream);
//        const base_iterator_type in_end;

    // convert input iterator to forward iterator, usable by spirit parser
//        forward_iterator_type fwd_begin = boost::spirit::make_default_multi_pass(in_begin);
//        forward_iterator_type fwd_end;

    // wrap forward iterator with position iterator, to record the position
//        pos_iterator_type position_begin(fwd_begin, fwd_end, "");

//    pos_iterator_type position_begin(script.begin());
//    pos_iterator_type position_it = position_begin;
//    pos_iterator_type position_end{script.end()};

    Iterator start{script.begin()};
    Iterator end{script.end()};

    return parse(first, last, expression, skipper);
}

}}

#endif //ICE_SCRIPT_ABSTRACTPARSER_INL
