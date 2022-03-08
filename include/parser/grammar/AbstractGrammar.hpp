#ifndef ICE_SCRIPT_ABSTRACTGRAMMAR_HPP
#define ICE_SCRIPT_ABSTRACTGRAMMAR_HPP

#include <string>

#include "ast/LocationInfo.hpp"

#include "parser/AnnotationFunction.hpp"
#include "parser/ErrorHandlerFunction.hpp"

namespace ice_script { namespace parser { namespace grammar {

template <typename Iterator, typename Node>
struct AbstractGrammar : boost::spirit::qi::grammar<Iterator, Node(), SkipperType>
{
    explicit AbstractGrammar(Iterator it) : AbstractGrammar::base_type(start), annotate(it)
    {

    }

    boost::phoenix::function<error_handler_f> handler;
    boost::phoenix::function<annotation_f<Iterator>> annotate;

    boost::spirit::qi::rule<Iterator, Node(), SkipperType> start;
};

}}}

#endif //ICE_SCRIPT_ABSTRACTGRAMMAR_HPP
