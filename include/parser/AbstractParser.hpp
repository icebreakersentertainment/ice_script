#ifndef ICE_SCRIPT_ABSTRACTPARSER_HPP
#define ICE_SCRIPT_ABSTRACTPARSER_HPP

#include <string>

#include "parser/Iterator.hpp"
#include "parser/Skipper.hpp"

#include "ast/Ast.hpp"

namespace ice_script { namespace parser {

//template <typename Iterator, typename Expression, typename Skipper, typename Attribute>
template <typename Expression, typename Attribute>
Attribute parse(Expression& expression, const std::string& script)
{
    using namespace boost::spirit::qi;
//    using boost::spirit::ascii::space;
//    namespace classic = boost::spirit::classic;

//    // iterate over stream input
////        typedef std::istreambuf_iterator<char> base_iterator_type;
////        typedef std::istream_iterator<char> base_iterator_type;
//    typedef std::string::const_iterator base_iterator_type;
////        typedef boost::spirit::multi_pass<base_iterator_type> forward_iterator_type;
//    typedef boost::spirit::line_pos_iterator<base_iterator_type> PositionIteratorType;
////        typedef classic::position_iterator2<forward_iterator_type> PositionIteratorType;

//        const base_iterator_type in_begin(inputStream);
//        const base_iterator_type in_end;

    // convert input iterator to forward iterator, usable by spirit parser
//        forward_iterator_type fwd_begin = boost::spirit::make_default_multi_pass(in_begin);
//        forward_iterator_type fwd_end;

    // wrap forward iterator with position iterator, to record the position
//        PositionIteratorType position_begin(fwd_begin, fwd_end, "");
    PositionIteratorType position_begin(script.begin());
    PositionIteratorType position_it = position_begin;
    PositionIteratorType position_end{script.end()};

//    numberRule = qi::eps >> lexeme[+char_("0-9") >> -(char_(".") >> +char_("0-9"))];

//    IceScriptGrammar<PositionIteratorType> grammar{position_it};

    Attribute attribute;

    const bool r = boost::spirit::qi::phrase_parse(position_it, position_end, expression, skipper, attribute);
//    bool r;
//    try
//    {
//        r = boost::spirit::qi::phrase_parse(position_it, position_end, expression, boost::spirit::ascii::space, attribute);
//    }
//    catch (const qi::expectation_failure<PositionIteratorType>& e)
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

    if (!r || position_it != position_end)
    {
        int line   = get_line(position_it);
        int column = get_column(position_begin, position_it);
        const auto message = detail::format("Error during parsing line %s column %s.", line, column);
        throw std::runtime_error(message);
    }

    return attribute;
}

template <typename Iterator, typename Expression, typename Skipper, typename Attribute>
class AbstractParser
{
public:
//    AbstractParser(Expression& expression, Skipper& skipper) : expression_(&expression), skipper_(&skipper)
//    {}

    virtual ~AbstractParser() = default;

    virtual Attribute parse(const std::string& script) = 0;

//    Attribute parse(std::istream& inputStream, const std::string& script);

protected:
//    Expression* expression_;
//    Skipper* skipper_;
//
//    virtual Attribute parse(Iterator& first, Iterator last, const Expression& expression, const Skipper& skipper) = 0;
//    virtual Attribute parse(Expression& expression, Skipper& skipper, const std::string& script) = 0;
};

}}

#endif //ICE_SCRIPT_ABSTRACTPARSER_HPP
