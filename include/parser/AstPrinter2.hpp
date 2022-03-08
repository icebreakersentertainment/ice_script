#ifndef ICE_SCRIPT_ASTPRINTER_HPP
#define ICE_SCRIPT_ASTPRINTER_HPP

#include <string>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>
#include <boost/phoenix/core.hpp>
#include <boost/phoenix/operator.hpp>
#include <boost/phoenix/object.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/fusion/adapted/std_tuple.hpp>
#include <boost/fusion/include/io.hpp>
#include "boost/variant/static_visitor.hpp"

namespace ice_script { namespace parser {

class AstPrinter : public boost::static_visitor<>
{
public:
    const static int TAB_SIZE = 4;

    explicit AstPrinter(std::ostream& os, int indent = 0) : os_(os), indent_(indent)
    {}

    AstPrinter(std::ostream& os, bool printLocationInfo, int indent = 0)
            :
            os_(os),
            printLocationInfo_(printLocationInfo),
            indent_(indent)
    {}

    void operator()(const std::string& string) const
    {
        tab(indent_);

        os_ << typeid(std::string).name() << " " << string << std::endl;
    }

    template <typename T>
    void operator()(const T& node) const
    {
        tab(indent_);

        os_ << typeid(node).name() << " " << node.value << std::endl;
//        os_ << typeid(node).name() << " " << node.value.get() << std::endl;
    }

    void operator()(const Ast& ast) const
    {
        operator()(ast.root);
//        boost::apply_visitor(AstPrinter(_os, indent+TAB_SIZE), ast.root);
    }
//
//    void operator()(const binop <op_and>& b) const
//    { print(" & ", b.oper1, b.oper2); }
//
//    void operator()(const binop <op_or>& b) const
//    { print(" | ", b.oper1, b.oper2); }
//
//    void operator()(const binop <op_xor>& b) const
//    { print(" ^ ", b.oper1, b.oper2); }
//
//    void print(const std::string& op, const expr& l, const expr& r) const
//    {
//        _os << "(";
//        boost::apply_visitor(*this, l);
//        _os << op;
//        boost::apply_visitor(*this, r);
//        _os << ")";
//    }
//
//    void operator()(const unop <op_not>& u) const
//    {
//        _os << "(";
//        _os << "!";
//        boost::apply_visitor(*this, u.oper1);
//        _os << ")";
//    }

private:
    void tab(int spaces) const
    {
        for (int i = 0; i < spaces; ++i)
            os_ << ' ';
    }

    std::ostream& os_;
    int indent_;
    bool printLocationInfo_;
};

}}

#endif //ICE_SCRIPT_ASTPRINTER_HPP
