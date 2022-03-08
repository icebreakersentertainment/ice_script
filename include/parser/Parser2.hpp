#ifndef ICE_SCRIPT_PARSER_HPP
#define ICE_SCRIPT_PARSER_HPP

#include <string>

//#include <boost/any.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/phoenix/core.hpp>
#include <boost/phoenix/operator.hpp>
#include <boost/phoenix/object.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/fusion/adapted/std_tuple.hpp>
#include <boost/fusion/include/io.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/optional/optional_io.hpp>

namespace ice_script { namespace parser {

struct Node
{
//    std::vector<std::string> data1;
    std::string value;
};

struct TestNode
{
    // test = qi::eps >> -(string("&") >> -(string("in") | string("out") | string("inout")));
    std::string value1;
    boost::optional<std::string> value;
//    std::string value;
};

struct Ast
{
    TestNode root;
};

}}

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::parser::Node,
        value
)
BOOST_FUSION_ADAPT_STRUCT(
        ice_script::parser::TestNode,
        value1,
        value
)

namespace ice_script { namespace parser {

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

template <typename Iterator>
struct Grammar : boost::spirit::qi::grammar<Iterator, TestNode(), SkipperType>
{
    Grammar() : Grammar::base_type(start)
    {
        using qi::int_;
        using qi::lit;
        using qi::double_;
        using qi::lexeme;
        using ascii::char_;

        using namespace boost::spirit::qi;
        using boost::spirit::ascii::space;
        using boost::spirit::ascii::space_type;
        using boost::spirit::ascii::char_;

//        test = qi::eps >> -(string("&") >> -(string("in") | string("out") | string("inout")));
        test = qi::eps >> string("&") >> -(string("in") | string("out") | string("inout"));
//        test = qi::eps >> +char_;

        start = test;
    }

    qi::rule<Iterator, TestNode(), ascii::space_type> start;
    qi::rule<Iterator, TestNode(), ascii::space_type> test;
};

class Parser
{
public:
    Ast parse(const std::string& script)
    {
        using namespace boost::spirit::qi;
        using boost::spirit::ascii::space;

        Grammar<std::string::const_iterator> grammar;
        TestNode root;

        std::cout << "script: " << script << std::endl;

        auto bit = script.begin();
        auto eit = script.end();

        const bool r = boost::spirit::qi::phrase_parse(bit, eit, grammar, boost::spirit::ascii::space, root);

        if (r)
        {

//            auto a = boost::any_cast<std::vector<boost::any>>(  );
//            for( auto it = a.begin(); it != a.end(); ++it ) {
//                std::cout <<boost::any_cast<void *>( *it ) <<std::endl;
//            }
        }

        Ast ast;
        ast.root = root;

        return ast;
    }
};

}}

#endif //ICE_SCRIPT_PARSER_HPP
