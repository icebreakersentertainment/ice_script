#ifndef ICE_SCRIPT_FUNCATTRNODE_HPP
#define ICE_SCRIPT_FUNCATTRNODE_HPP

#include <string>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct FuncattrNode : LocationInfo
{
    FuncattrNode() = default;

    // funcattrRule = *(string("override") | string("final") | string("explicit") | string("property"));
    std::vector<std::string> value;
//    std::string value;
};

}}

namespace boost{ namespace spirit{ namespace traits
{
template<>
struct is_container<ice_script::ast::FuncattrNode> : boost::mpl::true_
{};

template<>
struct container_value<ice_script::ast::FuncattrNode>
{
    typedef std::string type;
};

template<>
struct push_back_container<ice_script::ast::FuncattrNode, std::string>
{
    static bool call(ice_script::ast::FuncattrNode& c, std::string val)
    {
        c.value.push_back(val);
        return true;
    }
};
}}}

//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::FuncattrNode,
//        value
//)

#endif //ICE_SCRIPT_FUNCATTRNODE_HPP
