#ifndef ICE_SCRIPT_ANNOTATIONFUNCTION_HPP
#define ICE_SCRIPT_ANNOTATIONFUNCTION_HPP

//#include "parser/LocationInfo.hpp"

namespace ice_script { namespace parser {

template<typename It>
struct annotation_f
{
    typedef void result_type;

    annotation_f(It first) : first(first) {}
    It const first;

    template<typename Val, typename First, typename Last>
    void operator()(Val& v, First f, Last l) const
    {
//        std::cerr << "\nannotating: " << typeid(v).name() << " '" << std::string(f,l) << "'\n";
        do_annotate(v, f, l, first);
//        std::cerr << "\nannotating done " << typeid(v).name() << "\n";//" '" << std::string(f,l) << "'\n";
    }
private:
    void static do_annotate(ast::LocationInfo& li, It f, It l, It first) {
        using std::distance;
        li.line   = get_line(f);
        li.column = get_column(first, f);
        li.length = distance(f, l);
    }
    static void do_annotate(...) { std::cerr << "(not having LocationInfo)\n"; }
};

}}

#endif //ICE_SCRIPT_ANNOTATIONFUNCTION_HPP