#ifndef ICE_SCRIPT_ANALYZER_ABSTRACTVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_ABSTRACTVISITOR_HPP

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/variant/static_visitor.hpp>
#include <boost/variant/variant.hpp>
#include <boost/variant/recursive_wrapper.hpp>

#include "ast/LocationInfo.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

template <typename VisitorType, typename ResultType>
class AbstractVisitor : public boost::static_visitor<ResultType>
{
public:
    AbstractVisitor(logger::ILogger& logger, Context& context) : logger_(&logger), context_(&context)
    {

    }

//    T operator()(const std::string& string)
//    {
//        std::cout << "wtf string: " << string << std::endl;
//
//        return {};
//    }

    ResultType operator()(const boost::spirit::qi::unused_type& unusedType)
    {
        std::cout << "wtf ?: " << std::endl;

        return {};
    }

//    template<
//            typename U,
//            typename = typename std::enable_if<std::is_base_of<ast::LocationInfo, U>::value, U>::type
//    >
//    T operator()(const boost::recursive_wrapper<U>& node)
//    {
//        LOG_DEBUG(logger_, "agh 2 %s", typeid(node).name())
//        return operator()(node.get());
//    }

    template<
            typename U
    >
    ResultType operator()(const boost::recursive_wrapper<U>& node)
    {
        LOG_DEBUG(logger_, "agh 2 %s", typeid(node).name())
        return operator()(node.get());
    }

//    template<
//            typename U,
//            typename = typename std::enable_if<std::is_base_of<ast::LocationInfo, U>::value, U>::type
//    >
//    T operator()(const U& node)
//    {
//        LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
//
//        return {};
//    }

    template<
            typename ... Us//,
//            typename = typename std::enable_if<std::is_base_of<ast::LocationInfo, Ts>::value, Ts>::type
    >
    ResultType operator()(const boost::variant<Us ...>& node)
    {
        return boost::apply_visitor(static_cast<VisitorType&>(*this), node);
    }

protected:
    logger::ILogger* logger_;
    Context* context_;
};

}}}

#endif //ICE_SCRIPT_ANALYZER_ABSTRACTVISITOR_HPP
