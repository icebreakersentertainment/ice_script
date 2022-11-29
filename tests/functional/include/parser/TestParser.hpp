#ifndef ICE_SCRIPT_TESTPARSER_HPP
#define ICE_SCRIPT_TESTPARSER_HPP

#include <string>

#include <boost/algorithm/string.hpp>

//#include "parser/AstAll.hpp"
#include "parser/AnnotationFunction.hpp"
#include "parser/ErrorHandlerFunction.hpp"

#include "ast/Ast.hpp"

#include "detail/Format.hpp"

namespace ice_script { namespace parser {

template <typename RuleType, typename NodeType>
struct TestGrammar : boost::spirit::qi::grammar<PositionIteratorType, NodeType(), SkipperType>
{
    TestGrammar(PositionIteratorType it, RuleType rule) : TestGrammar::base_type(start), annotate(it), rule_(rule)
    {
        using namespace boost::spirit;
        using namespace boost::spirit::qi;

        start = qi::eps >> rule_;

        on_error<rethrow>(start, handler(_1, _2, _3, _4));
        on_error<rethrow>(rule_, handler(_1, _2, _3, _4));

        auto set_location_info = annotate(_val, _1, _3);
        on_success(start, set_location_info);
        on_success(rule_, set_location_info);

        BOOST_SPIRIT_DEBUG_NODES(
                (start)
                (rule_)
        )
    }
    
    boost::phoenix::function<error_handler_f> handler;
    boost::phoenix::function<annotation_f<PositionIteratorType>> annotate;

    boost::spirit::qi::rule<PositionIteratorType, NodeType(), SkipperType> start;
    // RuleType rule_ = ice_script::parser::rules::arglistRule;
    RuleType rule_;
//    IdentifierRuleType identifierRule_ = ice_script::parser::rules::identifierRule;
};

template <typename RuleType, typename NodeType>
class TestParser
{
public:
    RuleType rule_;
    
    TestParser(RuleType rule) : rule_(rule)
    {

    }

    NodeType parse(const std::string& script)
    {
        std::istringstream inputStringStream(script);

        return parse(inputStringStream, script);
    }

    NodeType parse(std::istream& inputStream, const std::string& script)
    {
        using namespace boost::spirit::qi;
        using boost::spirit::ascii::space;
    //    namespace classic = boost::spirit::classic;

    //        Grammar<std::string::const_iterator> grammar;

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
    //        PositionIteratorType begin(fwd_begin, fwd_end, "");
        PositionIteratorType begin(script.begin());
        PositionIteratorType it = begin;
        PositionIteratorType end{script.end()};

    //    numberRule = qi::eps >> lexeme[+char_("0-9") >> -(char_(".") >> +char_("0-9"))];

    //    IceScriptGrammar<PositionIteratorType> grammar{it};
        TestGrammar<RuleType, NodeType> grammar{it, rule_};
        // TestGrammar grammar{};
        NodeType node;
    //    std::string root;
    //    ast::NumberNode root;

    //    numberRule = qi::eps >> lexeme[+char_("0-9") >> -(char_(".") >> +char_("0-9"))];
        bool r;
        try
        {
            r = boost::spirit::qi::phrase_parse(it, end, grammar, skipper, node);
    //        r = boost::spirit::qi::phrase_parse(it, end, assignRule3 | assignRule4, boost::spirit::ascii::space, root);
    //        r = boost::spirit::qi::phrase_parse(it, end, numberRule, boost::spirit::ascii::space, root);
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
    //        throw e;

            int line   = get_line(it);
    //                int column = get_column(begin, it);
            int column = get_column(begin, e.first);
    //
            std::cerr << "Error 2: expecting " << e.what() << " in line " << line << ": \n"
                      << std::string(begin, e.first) << "\n"
                      << std::setw(std::distance(begin, e.first)) << '^' << "---- here\n";

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

//        ast::Ast ast;
//        ast.root = node;
    //    std::cout << "OKOK: " << root.value << std::endl;

//        return ast;
        return node;
    }
};

}}

#endif //ICE_SCRIPT_TESTPARSER_HPP
