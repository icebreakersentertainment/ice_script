#ifndef ICE_SCRIPT_PRIMITIVETYPERULE_HPP
#define ICE_SCRIPT_PRIMITIVETYPERULE_HPP

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>

#include "ast/PrimtypeNode.hpp"

#include "parser/Iterator.hpp"
#include "parser/Skipper.hpp"

namespace ice_script { namespace parser { namespace rules {

struct PrimitiveTypeSymbols : boost::spirit::qi::symbols<char, ast::PrimitiveType>
{
    PrimitiveTypeSymbols()
    {
        add
            ("void", ast::PrimitiveType::VOID_T)
            ("int", ast::PrimitiveType::INT)
            ("int8", ast::PrimitiveType::INT8)
            ("int16", ast::PrimitiveType::INT16)
            ("int32", ast::PrimitiveType::INT32)
            ("int64", ast::PrimitiveType::INT64)
            ("uint", ast::PrimitiveType::UINT)
            ("uint8", ast::PrimitiveType::UINT8)
            ("uint16", ast::PrimitiveType::UINT16)
            ("uint32", ast::PrimitiveType::UINT32)
            ("uint64", ast::PrimitiveType::UINT64)
            ("float", ast::PrimitiveType::FLOAT)
            ("double", ast::PrimitiveType::DOUBLE)
            ("bool", ast::PrimitiveType::BOOLEAN)
        ;
    }

} primitiveTypeRule;

//using VarRuleType = boost::spirit::qi::rule<PositionIteratorType, ast::VarNode(), SkipperType>;
//
//extern VarRuleType varRule;

}}}

#endif //ICE_SCRIPT_PRIMITIVETYPERULE_HPP
