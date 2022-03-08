#include <string>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>
#include <boost/algorithm/string.hpp>

#include "parser/AbstractParser.hpp"

#include "detail/Format.hpp"

using namespace ice_script::parser;
using namespace ice_script::ast;

#include "parser/Iterator.hpp"
#include "parser/Skipper.hpp"

struct printer
{
    typedef boost::spirit::utf8_string string;

    void element(string const& tag, string const& value, int depth) const
    {
        for (int i = 0; i < (depth*4); ++i) // indent to depth
            std::cout << ' ';

        std::cout << "tag: " << tag;
        if (value != "")
            std::cout << ", value: " << value;
        std::cout << std::endl;
    }
};

void print_info(boost::spirit::info const& what)
{
    using boost::spirit::basic_info_walker;

    printer pr;
    basic_info_walker<printer> walker(pr, what.tag, 0);
    boost::apply_visitor(walker, what.value);
}

template <typename Expression, typename Attribute>
class TestParser : public ice_script::parser::AbstractParser<PositionIteratorType, Expression, SkipperType, Attribute>
{
public:
    TestParser(Expression expression) : expression_(expression)
    {}

    ~TestParser() override = default;

//    Attribute parse(const std::string& script) override
//    {
//
//    }

    Attribute parse(const std::string& script) override
    {
            using namespace boost::spirit::qi;
            using boost::spirit::ascii::space;

            // iterate over stream input
        //        typedef std::istreambuf_iterator<char> base_iterator_type;
        //        typedef std::istream_iterator<char> base_iterator_type;

        //        typedef boost::spirit::multi_pass<base_iterator_type> forward_iterator_type;

        //        typedef classic::position_iterator2<forward_iterator_type> PositionIteratorType;

        //        const base_iterator_type in_begin(inputStream);
        //        const base_iterator_type in_end;

            // convert input iterator to forward iterator, usable by spirit parser
        //        forward_iterator_type fwd_begin = boost::spirit::make_default_multi_pass(in_begin);
        //        forward_iterator_type fwd_end;

            // wrap forward iterator with position iterator, to record the position
        //        PositionIteratorType position_begin(fwd_begin, fwd_end, "");
            PositionIteratorType begin(script.begin());
            PositionIteratorType it = begin;
            PositionIteratorType end{script.end()};

            Attribute attribute;

//            r = boost::spirit::qi::phrase_parse(it, end, expression_, boost::spirit::ascii::space, attribute);
            bool r;
            try
            {
//                r = boost::spirit::qi::phrase_parse(position_it, position_end, expression, boost::spirit::ascii::space, attribute);
                r = boost::spirit::qi::phrase_parse(it, end, expression_, skipper, attribute);
            }
            catch (const boost::spirit::qi::expectation_failure<PositionIteratorType>& e)
            {
        //            const classic::file_position_base<std::string>& pos = e.first.get_position();
        //
        //            std::stringstream msg;
        //
        //            msg <<
        //                "parse error at file " << pos.file <<
        //                " line " << pos.line << " column " << pos.column << std::endl <<
        //                "'" << e.first.get_currentline() << "'" << std::endl <<
        //                std::setw(pos.column) << " " << "^- here";
        //
        //            throw std::runtime_error(msg.str());
//                throw e;

                int line   = get_line(it);
//                int column = get_column(begin, it);
                int column = get_column(begin, e.first);
//
                std::cout << "line: " << line << " column: " << column << std::endl;
                std::cout << "line2: " << e.first.position() << " column: " << e.last.position() << std::endl;
                std::cout << "line3b: "; print_info(e.what_);
                std::cout << "line4: " << std::string(e.first, e.last) << std::endl;

                std::vector<std::string> lines;
                boost::split(lines, script, boost::is_any_of("\n"));

                const auto& _line = lines[line - 1];

                std::string pointToError = "";
                for (int i=0; i < column - 1; ++i) pointToError += " ";
                pointToError += "^- here";

                const auto message = ice_script::detail::format("Error during parsing line %s column %s\n%s\n%s", line, column, _line, pointToError);
                throw std::runtime_error(message);
            }

            if (!r || it != end)
            {
                int line   = get_line(it);
                int column = get_column(begin, it);

                std::cout << "line4: " << std::string(begin, it) << std::endl;
                std::cout << "line5: " << std::string(it, end) << std::endl;

                std::vector<std::string> lines;
                boost::split(lines, script, boost::is_any_of("\n"));

                const auto& _line = lines[line - 1];

                std::string pointToError = "";
                for (int i=0; i < column - 1; ++i) pointToError += " ";
                pointToError += "^- here";

                const auto message = ice_script::detail::format("Error during parsing line %s column %s\n%s\n%s", line, column, _line, pointToError);
                throw std::runtime_error(message);
            }

            return attribute;
    }

private:
    Expression expression_;
};

#include "parser/AbstractParser.hpp"
