#ifndef ICE_SCRIPT_ERRORHANDLERFUNCTION_HPP
#define ICE_SCRIPT_ERRORHANDLERFUNCTION_HPP

namespace ice_script { namespace parser {

struct error_handler_f
{
    typedef boost::spirit::qi::error_handler_result result_type;
    template<typename T1, typename T2, typename T3, typename T4>
    boost::spirit::qi::error_handler_result operator()(T1 b, T2 e, T3 where, T4 const& what) const
    {
        std::cerr << "Error 1: expecting " << what << " in line " << get_line(where) << ": \n"
                  << std::string(b,e) << "\n"
                  << std::setw(std::distance(b, where)) << '^' << "---- here\n";
        return boost::spirit::qi::rethrow;
    }
};

}}

#endif //ICE_SCRIPT_ERRORHANDLERFUNCTION_HPP