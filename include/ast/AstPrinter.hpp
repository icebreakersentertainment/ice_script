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

#include "ast/Ast.hpp"
#include "ast/Root.hpp"
#include "ast/ScriptNode.hpp"
#include "ast/FuncattrNode.hpp"
#include "ast/TypedefNode.hpp"
#include "ast/TypeNode.hpp"
#include "ast/LiteralNode.hpp"
#include "ast/ExpropNode.hpp"
#include "ast/DatatypeNode.hpp"

namespace ice_script { namespace ast {

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
    void operator()(const boost::recursive_wrapper<T>& node) const
    {
        operator()(node.get());
    }

    template<
            typename T//,
//            typename = typename std::enable_if<std::is_base_of<ast::LocationInfo, T>::value, T>::type
    >
    void operator()(const T& node) const
    {
        printBasic(node);
    }

    template<
            typename T,
            typename std::enable_if<std::is_base_of<ast::LocationInfo, T>::value, bool>::type = true
    >
    void printBasic(const T& node, bool newline = true) const
    {
        tab(indent_);

        if (printLocationInfo_)
        {
            os_ << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
        }

        os_ << typeid(node).name();

        if (newline) os_ << std::endl;
    }

    template<
            typename T,
            typename std::enable_if<!std::is_base_of<ast::LocationInfo, T>::value, bool>::type = true
    >
    void printBasic(const T& node, bool newline = true) const
    {
        tab(indent_);

//        if (printLocationInfo_)
//        {
//            os_ << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        }

        os_ << typeid(node).name();

        if (newline) os_ << std::endl;
    }

    template<
            typename ... Ts//,
//            typename = typename std::enable_if<std::is_base_of<ast::LocationInfo, Ts>::value, Ts>::type
    >
    void operator()(const boost::variant<Ts ...>& node) const
    {
        return boost::apply_visitor(*this, node);
    }

    void operator()(const Ast& ast) const;
    void operator()(const Root& node) const;
    void operator()(const ScriptNode& node) const;
    void operator()(const ClassNode& node) const;
    void operator()(const TypedefNode& node) const;
    void operator()(const NamespaceNode& node) const;
    void operator()(const FuncNode& node) const;
    void operator()(const InterfaceNode& node) const;
    void operator()(const VarNode& node) const;
    void operator()(const ImportNode& node) const;
    void operator()(const EnumNode& node) const;
    void operator()(const FuncdefNode& node) const;
    void operator()(const VirtpropNode& node) const;
    void operator()(const MixinNode& node) const;
    void operator()(const IntfmthdNode& node) const;
    void operator()(const StatblockNode& node) const;
    void operator()(const ParamlistNode& node) const;
    void operator()(const TypemodNode& node) const;
    void operator()(const TypeNode& node) const;
    void operator()(const InitlistNode& node) const;
    void operator()(const ScopeNode& node) const;
    void operator()(const DatatypeNode& node) const;
    void operator()(const PrimtypeNode& node) const;
    void operator()(const FuncattrNode& node) const;
    void operator()(const StatementNode& node) const;
    void operator()(const SwitchNode& node) const;
    void operator()(const BreakNode& node) const;
    void operator()(const ForNode& node) const;
    void operator()(const WhileNode& node) const;
    void operator()(const DowhileNode& node) const;
    void operator()(const IfNode& node) const;
    void operator()(const ContinueNode& node) const;
    void operator()(const ExprstatNode& node) const;
    void operator()(const TryNode& node) const;
    void operator()(const ReturnNode& node) const;
    void operator()(const CaseNode& node) const;
    void operator()(const ExprNode& node) const;
    void operator()(const ExprtermNode& node) const;
    void operator()(const ExprvalueNode& node) const;
    void operator()(const ConstructcallNode& node) const;
    void operator()(const ExprpreopNode& node) const;
    void operator()(const ExprpostopNode& node) const;
    void operator()(const CastNode& node) const;
    void operator()(const LambdaNode& node) const;
    void operator()(const LiteralNode& node) const;
    void operator()(const FunccallNode& node) const;
    void operator()(const VaraccessNode& node) const;
    void operator()(const ArglistNode& node) const;
    void operator()(const AssignNode& node) const;
    void operator()(const ConditionNode& node) const;
    void operator()(const ExpropNode& node) const;
    void operator()(const BitopNode& node) const;
    void operator()(const MathopNode& node) const;
    void operator()(const CompopNode& node) const;
    void operator()(const LogicopNode& node) const;
    void operator()(const AssignopNode& node) const;
    void operator()(const IdentifierNode& node) const;
    void operator()(const NumberNode& node) const;
    void operator()(const StringNode& node) const;
    void operator()(const BitsNode& node) const;
    void operator()(const BoolNode& node) const;
    void operator()(const NullNode& node) const;
    void operator()(const VoidNode& node) const;

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
