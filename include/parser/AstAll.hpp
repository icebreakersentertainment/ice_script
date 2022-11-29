#ifndef ICE_SCRIPT_ASTALL_HPP
#define ICE_SCRIPT_ASTALL_HPP

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>
#include <boost/variant/variant.hpp>
#include <boost/optional/optional.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/fusion/adapted/std_tuple.hpp>
#include <boost/fusion/include/boost_tuple.hpp>
#include <boost/fusion/include/io.hpp>

#include "ast/LocationInfo.hpp"
#include "ast/BitsNode.hpp"

#include "detail/monostate.hpp"

namespace ice_script { namespace ast {

struct ClassNode : LocationInfo
{
    std::string value;
};

struct NamespaceNode : LocationInfo
{
    std::string value;
};

/**
SCRIPT        ::= {IMPORT | ENUM | TYPEDEF | CLASS | MIXIN | INTERFACE | FUNCDEF | VIRTPROP | VAR | FUNC | NAMESPACE | ';'}
CLASS         ::= {'shared' | 'abstract' | 'final' | 'external'} 'class' IDENTIFIER (';' | ([':' IDENTIFIER {',' IDENTIFIER}] '{' {VIRTPROP | FUNC | VAR | FUNCDEF} '}'))
TYPEDEF       ::= 'typedef' PRIMTYPE IDENTIFIER ';'
NAMESPACE     ::= 'namespace' IDENTIFIER {'::' IDENTIFIER} '{' SCRIPT '}'
FUNC          ::= {'shared' | 'external'} ['private' | 'protected'] [((TYPE ['&']) | '~')] IDENTIFIER PARAMLIST ['const'] FUNCATTR (';' | STATBLOCK)
INTERFACE     ::= {'external' | 'shared'} 'interface' IDENTIFIER (';' | ([':' IDENTIFIER {',' IDENTIFIER}] '{' {VIRTPROP | INTFMTHD} '}'))
VAR           ::= ['private'|'protected'] TYPE IDENTIFIER [( '=' (INITLIST | EXPR)) | ARGLIST] {',' IDENTIFIER [( '=' (INITLIST | EXPR)) | ARGLIST]} ';'
IMPORT        ::= 'import' TYPE ['&'] IDENTIFIER PARAMLIST FUNCATTR 'from' STRING ';'
ENUM          ::= {'shared' | 'external'} 'enum' IDENTIFIER (';' | ('{' IDENTIFIER ['=' EXPR] {',' IDENTIFIER ['=' EXPR]} '}'))
FUNCDEF       ::= {'external' | 'shared'} 'funcdef' TYPE ['&'] IDENTIFIER PARAMLIST ';'
VIRTPROP      ::= ['private' | 'protected'] TYPE ['&'] IDENTIFIER '{' {('get' | 'set') ['const'] FUNCATTR (STATBLOCK | ';')} '}'
MIXIN         ::= 'mixin' CLASS
INTFMTHD      ::= TYPE ['&'] IDENTIFIER PARAMLIST ['const'] ';'
STATBLOCK     ::= '{' {VAR | STATEMENT} '}'
PARAMLIST     ::= '(' ['void' | (TYPE TYPEMOD [IDENTIFIER] ['=' EXPR] {',' TYPE TYPEMOD [IDENTIFIER] ['=' EXPR]})] ')'
TYPEMOD       ::= ['&' ['in' | 'out' | 'inout']]
TYPE          ::= ['const'] SCOPE DATATYPE ['<' TYPE {',' TYPE} '>'] { ('[' ']') | ('@' ['const']) }
INITLIST      ::= '{' [ASSIGN | INITLIST] {',' [ASSIGN | INITLIST]} '}'
SCOPE         ::= ['::'] {IDENTIFIER '::'} [IDENTIFIER ['<' TYPE {',' TYPE} '>'] '::']
DATATYPE      ::= (IDENTIFIER | PRIMTYPE | '?' | 'auto')
PRIMTYPE      ::= 'void' | 'int' | 'int8' | 'int16' | 'int32' | 'int64' | 'uint' | 'uint8' | 'uint16' | 'uint32' | 'uint64' | 'float' | 'double' | 'bool'
FUNCATTR      ::= {'override' | 'final' | 'explicit' | 'property'}
STATEMENT     ::= (IF | FOR | WHILE | RETURN | STATBLOCK | BREAK | CONTINUE | DOWHILE | SWITCH | EXPRSTAT | TRY)
SWITCH        ::= 'switch' '(' ASSIGN ')' '{' {CASE} '}'
BREAK         ::= 'break' ';'
FOR           ::= 'for' '(' (VAR | EXPRSTAT) EXPRSTAT [ASSIGN {',' ASSIGN}] ')' STATEMENT
WHILE         ::= 'while' '(' ASSIGN ')' STATEMENT
DOWHILE       ::= 'do' STATEMENT 'while' '(' ASSIGN ')' ';'
IF            ::= 'if' '(' ASSIGN ')' STATEMENT ['else' STATEMENT]
CONTINUE      ::= 'continue' ';'
EXPRSTAT      ::= [ASSIGN] ';'
TRY           ::= 'try' STATBLOCK 'catch' STATBLOCK
RETURN        ::= 'return' [ASSIGN] ';'
CASE          ::= (('case' EXPR) | 'default') ':' {STATEMENT}
EXPR          ::= EXPRTERM {EXPROP EXPRTERM}
EXPRTERM      ::= ([TYPE '='] INITLIST) | ({EXPRPREOP} EXPRVALUE {EXPRPOSTOP})
EXPRVALUE     ::= 'void' | CONSTRUCTCALL | FUNCCALL | VARACCESS | CAST | LITERAL | '(' ASSIGN ')' | LAMBDA
CONSTRUCTCALL ::= TYPE ARGLIST
EXPRPREOP     ::= '-' | '+' | '!' | '++' | '--' | '~' | '@'
EXPRPOSTOP    ::= ('.' (FUNCCALL | IDENTIFIER)) | ('[' [IDENTIFIER ':'] ASSIGN {',' [IDENTIFIER ':' ASSIGN} ']') | ARGLIST | '++' | '--'
CAST          ::= 'cast' '<' TYPE '>' '(' ASSIGN ')'
LAMBDA        ::= 'function' '(' [[TYPE TYPEMOD] IDENTIFIER {',' [TYPE TYPEMOD] IDENTIFIER}] ')' STATBLOCK
LITERAL       ::= NUMBER | STRING | BITS | 'true' | 'false' | 'null'
FUNCCALL      ::= SCOPE IDENTIFIER ARGLIST
VARACCESS     ::= SCOPE IDENTIFIER
ARGLIST       ::= '(' [IDENTIFIER ':'] ASSIGN {',' [IDENTIFIER ':'] ASSIGN} ')'
ASSIGN        ::= CONDITION [ ASSIGNOP ASSIGN ]
CONDITION     ::= EXPR ['?' ASSIGN ':' ASSIGN]
EXPROP        ::= MATHOP | COMPOP | LOGICOP | BITOP
BITOP         ::= '&' | '|' | '^' | '<<' | '>>' | '>>>'
MATHOP        ::= '+' | '-' | '*' | '/' | '' | '**'
COMPOP        ::= '==' | '!=' | '<' | '<=' | '>' | '>=' | 'is' | '!is'
LOGICOP       ::= '&&' | '||' | '^^' | 'and' | 'or' | 'xor'
ASSIGNOP      ::= '=' | '+=' | '-=' | '*=' | '/=' | '|=' | '&=' | '^=' | '%=' | '**=' | '<<=' | '>>=' | '>>>='
IDENTIFIER    ::= single token:  starts with letter or _, can include any letter and digit, same as in C++
NUMBER        ::= single token:  includes integers and real numbers, same as C++
STRING        ::= single token:  single quoted ', double quoted ", or heredoc multi-line string """
BITS          ::= single token:  binary 0b or 0B, octal 0o or 0O, decimal 0d or 0D, hexadecimal 0x or 0X
 */

struct ScriptNode : LocationInfo
{
    std::string value;
};

struct FuncNode : LocationInfo
{
    std::string value;
};

struct InterfaceNode : LocationInfo
{
    std::string value;
};

struct VarNode : LocationInfo
{
    std::string value;
};

struct ImportNode : LocationInfo
{
    std::string value;
};

struct EnumNode : LocationInfo
{
    std::string value;
};

struct FuncdefNode : LocationInfo
{
    std::string value;
};

struct VirtpropNode : LocationInfo
{
    std::string value;
};

struct MixinNode : LocationInfo
{
    std::string value;
};

struct IntfmthdNode : LocationInfo
{
    std::string value;
};

struct StatblockNode : LocationInfo
{
    std::string value;
};

struct ParamlistNode : LocationInfo
{
    std::string value;
};

struct TypemodNode : LocationInfo
{
    // typemodRule = qi::eps >> -(string("&") >> -(string("in") | string("out") | string("inout")));
    std::string isRef;
    boost::optional<std::string> inout;
//    std::string value;
};

struct InitlistNode: LocationInfo
{
    std::string value;
};

struct ScopeNode: LocationInfo
{
    std::string value;
};

struct PrimtypeNode: LocationInfo
{
    std::string value;
};

struct FuncattrNode: LocationInfo
{
    FuncattrNode() = default;

    // funcattrRule = *(string("override") | string("final") | string("explicit") | string("property"));
    std::vector<std::string> value;
//    std::string value;
};

struct StatementNode: LocationInfo
{
    std::string value;
};

struct SwitchNode: LocationInfo
{
    std::string value;
};

struct BreakNode: LocationInfo
{
    std::string value;
};

struct ForNode: LocationInfo
{
    std::string value;
};

struct WhileNode: LocationInfo
{
    std::string value;
};

struct DowhileNode: LocationInfo
{
    std::string value;
};

struct IfNode: LocationInfo
{
    std::string value;
};

struct ContinueNode: LocationInfo
{
    std::string value;
};

struct ExprstatNode: LocationInfo
{
    std::string value;
};

struct TryNode: LocationInfo
{
    std::string value;
};

struct ReturnNode: LocationInfo
{
    std::string value;
};

struct CaseNode: LocationInfo
{
    std::string value;
};

struct ExprNode: LocationInfo
{
    std::string value;
};

struct ExprtermNode: LocationInfo
{
    std::string value;
};

struct ConstructcallNode;
struct FunccallNode;
struct VaraccessNode;
struct CastNode;
struct LiteralNode;
struct AssignNode;
struct LambdaNode;

struct ExprvalueNode: LocationInfo
{
    // (string("void") | constructcallRule | funccallRule | varaccessRule | castRule | literalRule | (lit("(") >> assignRule >> lit(")")) | lambdaRule);
    boost::variant<
            monostate,
            std::string,
            boost::recursive_wrapper<ConstructcallNode>,
            boost::recursive_wrapper<FunccallNode>,
            boost::recursive_wrapper<VaraccessNode>,
            boost::recursive_wrapper<CastNode>,
            boost::recursive_wrapper<LiteralNode>,
            boost::recursive_wrapper<AssignNode>,
            boost::recursive_wrapper<LambdaNode>
    > value;
//    std::string value;
};

struct TypeNode;
struct ArglistNode;

struct ConstructcallNode: LocationInfo
{
    boost::recursive_wrapper<TypeNode> typeNode;
    boost::recursive_wrapper<ArglistNode> arglistNode;
//    std::string value;
};

struct ExprpreopNode: LocationInfo
{
    std::string value;
};

struct FunccallNode;
struct IdentifierNode;
struct AssignNode;
struct ArglistNode;

struct ExprpostopNode: LocationInfo
{
    // (funccallRule | identifierRule)
    // | (-(identifierRule >> lit(":")) >> assignRule >> *(lit(",") >> -(identifierRule >> lit(":")) >> assignRule))
    // | arglistRule
    // | string("++")
    // | string("--");
    boost::variant<
            monostate,
            boost::variant<monostate, boost::recursive_wrapper<FunccallNode>, boost::recursive_wrapper<IdentifierNode>>,
            boost::tuple<
                    boost::optional<boost::recursive_wrapper<IdentifierNode>>,
                    boost::recursive_wrapper<AssignNode>,
                    std::vector<
                            boost::tuple<
                                    boost::optional<boost::recursive_wrapper<IdentifierNode>>,
                                    boost::recursive_wrapper<AssignNode>
                            >
                    >
            >,
            boost::recursive_wrapper<ArglistNode>,
            std::string

    > value;
//    std::string value;
};

//boost::fusion::vector<
//        boost::optional<ice_script::parser::IdentifierNode>,
//        ice_script::parser::AssignNode,
//        std::vector<
//                boost::fusion::vector<
//                        boost::optional<ice_script::parser::IdentifierNode>,
//                        ice_script::parser::AssignNode
//                >,
//                std::allocator<>
//        >
//>
//
//boost::variant<
//        boost::variant<boost::recursive_wrapper<ice_script::parser::FunccallNode>,boost::recursive_wrapper<ice_script::parser::IdentifierNode>>,
//        boost::tuples::tuple<
//                boost::optional<boost::recursive_wrapper<ice_script::parser::IdentifierNode>>,
//                boost::recursive_wrapper<ice_script::parser::AssignNode>,
//                std::vector<
//                        boost::tuples::tuple<
//                                boost::optional<boost::recursive_wrapper<ice_script::parser::IdentifierNode>>,
//                                boost::recursive_wrapper<ice_script::parser::AssignNode>,
//                                boost::tuples::null_type,
//                                boost::tuples::null_type,
//                                boost::tuples::null_type,
//                                boost::tuples::null_type,
//                                boost::tuples::null_type,
//                                boost::tuples::null_type,
//                                boost::tuples::null_type,
//                                boost::tuples::null_type
//                        >,
//                        std::allocator<>
//                >,
//                boost::tuples::null_type,
//                boost::tuples::null_type,
//                boost::tuples::null_type,
//                boost::tuples::null_type,
//                boost::tuples::null_type,
//                boost::tuples::null_type,
//                boost::tuples::null_type
//        >,
//        boost::recursive_wrapper<ice_script::parser::ArglistNode>,
//        std::string,
//        std::string
//>

struct TypeNode;
struct AssignNode;

struct CastNode: LocationInfo
{
    // typeRule >> string(">") >> string("(") >> assignRule >> string(")");
    boost::recursive_wrapper<TypeNode> typeNode;
    boost::recursive_wrapper<AssignNode> assignNode;
//    std::string value;
};

struct TypeNode;
struct TypemodNode;
struct IdentifierNode;
struct StatblockNode;

struct LambdaNode: LocationInfo
{
    // -(-(typeRule >> typemodRule) >> identifierRule >> *(lit(",") >> -(typeRule >> typemodRule) >> identifierRule)) >> lit(")" >> statblockRule;
    boost::optional<
            boost::tuple<
                    boost::optional<
                            boost::tuple<boost::recursive_wrapper<TypeNode>, boost::recursive_wrapper<TypemodNode>>
                    >,
                    boost::recursive_wrapper<IdentifierNode>,
                    std::vector<
                            boost::tuple<
                                    boost::optional<
                                            boost::tuple<boost::recursive_wrapper<TypeNode>, boost::recursive_wrapper<TypemodNode>>
                                    >,
                                    boost::recursive_wrapper<IdentifierNode>
                            >
                    >
            >
    > typeNodeStuff;
    boost::recursive_wrapper<StatblockNode> statblockNode;
//    std::string value;
};

struct ScopeNode;
struct IdentifierNode;
struct ArglistNode;

struct FunccallNode: LocationInfo
{
    // funccallRule = qi::eps >> scopeRule >> identifierRule >> arglistRule;
    boost::recursive_wrapper<ScopeNode> scopeNode;
    boost::recursive_wrapper<IdentifierNode> identifierNode;
    boost::recursive_wrapper<ArglistNode> arglistNode;
//    std::string value;
};

struct ScopeNode;
struct IdentifierNode;

struct VaraccessNode: LocationInfo
{
    // varaccessRule = qi::eps >> scopeRule >> identifierRule;
    boost::recursive_wrapper<ScopeNode> scopeNode;
    boost::recursive_wrapper<IdentifierNode> identifierNode;
//    std::string value;
};

struct IdentifierNode;
struct AssignNode;

struct ArglistNode: LocationInfo
{
    // arglistRule = -(identifierRule >>  string(":")) >> assignRule >> *(lit(",") >> -(identifierRule >> string(":")) >> assignRule);
    boost::optional<boost::tuple<boost::recursive_wrapper<IdentifierNode>, std::string>> identifierNode1;
    boost::recursive_wrapper<AssignNode> assignNode1;
    std::vector<
            boost::tuple<
                    boost::optional<
                            boost::tuple<
                                    boost::recursive_wrapper<IdentifierNode>,
                                    std::string
                            >
                    >,
                    boost::recursive_wrapper<AssignNode>
            >
    > identifierNodeAssignNode2;
//    std::string value;
};

struct ConditionNode;
struct AssignopNode;

struct AssignNode: LocationInfo
{
    // assignRule = qi::eps >> conditionRule >> -(assignopRule >> assignRule);
    boost::recursive_wrapper<ConditionNode> conditionNode;
    boost::optional<boost::tuple<boost::recursive_wrapper<AssignopNode>, boost::recursive_wrapper<AssignNode>>> assignopNodeAssignNode;
//    std::string value;
};

struct ConditionNode: LocationInfo
{
    // conditionRule = qi::eps >> exprRule >> -(string("?") >> assignRule >> string(":") >> assignRule);
    ExprNode exprNode;
    boost::optional<
            boost::tuple<std::string, boost::recursive_wrapper<AssignNode>, std::string, boost::recursive_wrapper<AssignNode>>
    > assignNode;
//    std::string value;
};

struct BitopNode: LocationInfo
{
    std::string value;
};

struct MathopNode: LocationInfo
{
    std::string value;
};

struct CompopNode: LocationInfo
{
    std::string value;
};

struct LogicopNode: LocationInfo
{
    std::string value;
};

struct ExpropNode: LocationInfo
{
//    EXPROP        ::= MATHOP | COMPOP | LOGICOP | BITOP
    boost::variant<monostate, BitopNode, MathopNode, CompopNode, LogicopNode> value;
//    std::string value;
};

struct AssignopNode: LocationInfo
{
    std::string value;
};

struct StringNode: LocationInfo
{
    std::string value;
};

struct NumberNode;
//struct BitsNode;

struct LiteralNode: LocationInfo
{
    // literalRule = qi::eps >> (numberRule | stringRule | bitsRule | string("true") | string("false") | string("null"));
    boost::variant<monostate, boost::recursive_wrapper<NumberNode>, StringNode, boost::recursive_wrapper<ast::BitsNode>, std::string> value;
//    std::string value;
};

struct IdentifierNode: LocationInfo
{
    std::string value;
};

struct DatatypeNode: LocationInfo
{
    // DATATYPE      ::= (IDENTIFIER | PRIMTYPE | '?' | 'auto')
    boost::variant<
            monostate,
            IdentifierNode,
            PrimtypeNode,
            std::string
    > value;
//    std::string value;
};

struct TypeNode;

typedef boost::optional<std::vector<boost::recursive_wrapper<TypeNode>>> TypeNodeTemplates;

struct TypeNode: LocationInfo
{
    // TYPE          ::= ['const'] SCOPE DATATYPE ['<' TYPE {',' TYPE} '>'] { ('[' ']') | ('@' ['const']) }
    boost::optional<std::string> isConst;
    ScopeNode scopeNode;
    DatatypeNode datatypeNode;
    TypeNodeTemplates templates;
//    std::vector<
//        boost::variant<
//            std::string,
//            boost::tuple<std::string, boost::optional<std::string>>
//        >
//    > type;
    //    std::string value;
};

struct TypedefNode: LocationInfo
{
    // // TYPEDEF       ::= 'typedef' PRIMTYPE IDENTIFIER ';'
    PrimtypeNode primTypeNode;
    IdentifierNode identifierNode;
//    std::string value;
};

struct NumberNode: LocationInfo
{
    std::string value;
};

//struct BitsNode: LocationInfo
//{
//    std::string value;
//};

struct Node;

//typedef boost::variant<
//        NumberNode,
//        BitsNode
//>
//        Value3;
//
//typedef boost::variant<
//        ConstructcallNode,
//        ExprpreopNode,
//        ExprpostopNode,
//        CastNode,
//        LambdaNode,
//        LiteralNode,
//        FunccallNode,
//        VaraccessNode,
//        ArglistNode,
//        AssignNode,
//        ConditionNode,
//        ExpropNode,
//        BitopNode,
//        MathopNode,
//        CompopNode,
//        LogicopNode,
//        AssignopNode,
//        StringNode,
//        IdentifierNode,
//        Value3
//>
//        Value2;
//
//typedef boost::variant<
//        ScopeNode,
//        DatatypeNode,
//        PrimtypeNode,
//        FuncattrNode,
//        StatementNode,
//        SwitchNode,
//        BreakNode,
//        ForNode,
//        WhileNode,
//        DowhileNode,
//        IfNode,
//        ContinueNode,
//        ExprstatNode,
//        TryNode,
//        ReturnNode,
//        CaseNode,
//        ExprNode,
//        ExprtermNode,
//        ExprvalueNode,
//        Value2
//>
//        Value1;
//
//typedef boost::variant<
//        boost::recursive_wrapper<Node>,
//        ScriptNode,
//        ClassNode,
//        TypedefNode,
//        NamespaceNode,
//        FuncNode,
//        InterfaceNode,
//        VarNode,
//        ImportNode,
//        EnumNode,
//        FuncdefNode,
//        VirtpropNode,
//        MixinNode,
//        IntfmthdNode,
//        StatblockNode,
//        ParamlistNode,
//        TypemodNode,
//        TypeNode,
//        InitlistNode,
//        Value1
//>
//        Value;

//typedef boost::variant<
//        boost::recursive_wrapper<Node>,
////        ScriptNode,
////        ClassNode,
////        TypedefNode,
////        NamespaceNode,
////        FuncNode,
////        InterfaceNode,
////        VarNode,
////        ImportNode,
////        EnumNode,
////        FuncdefNode,
////        VirtpropNode,
////        MixinNode,
////        IntfmthdNode,
////        StatblockNode,
////        ParamlistNode,
//        TypemodNode,
//        TypeNode,
//        InitlistNode,
//        ScopeNode,
//        DatatypeNode,
//        PrimtypeNode,
//        FuncattrNode,
//        StatementNode,
//        SwitchNode,
//        BreakNode,
//        ForNode,
//        WhileNode,
//        DowhileNode,
//        IfNode,
//        ContinueNode,
//        ExprstatNode,
//        TryNode,
//        ReturnNode,
//        CaseNode,
//        ExprNode,
//        ExprtermNode,
//        ExprvalueNode,
//        ConstructcallNode,
//        ExprpreopNode,
//        ExprpostopNode,
//        CastNode,
//        LambdaNode,
//        LiteralNode,
//        FunccallNode,
//        VaraccessNode,
//        ArglistNode,
//        AssignNode,
//        ConditionNode,
//        ExpropNode,
////        BitopNode,
////        MathopNode,
////        CompopNode,
////        LogicopNode,
//        AssignopNode,
//        StringNode,
//        IdentifierNode,
//        NumberNode,
//        ast::BitsNode
//>
//        Value;
//
//struct Node: LocationInfo
//{
//    std::vector<Value> values;
//};
//
//struct Ast
//{
//    Node root;
////    std::vector<Node> children;
//};

}}

//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::Node,
//        values
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::ScriptNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::ClassNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::TypedefNode,
//        primTypeNode,
//        identifierNode
////        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::NamespaceNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::FuncNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::InterfaceNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::VarNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::ImportNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::EnumNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::FuncdefNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::VirtpropNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::MixinNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::IntfmthdNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::StatblockNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::ParamlistNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::TypemodNode,
//        isRef,
//        inout
////        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::TypeNode,
//        isConst,
//        scopeNode,
//        datatypeNode,
//        templates//,
////        type
////        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::InitlistNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::ScopeNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::DatatypeNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::PrimtypeNode,
//        value
//)
////BOOST_FUSION_ADAPT_STRUCT(
////        ice_script::ast::FuncattrNode,
////        value
////)
//namespace boost{ namespace spirit{ namespace traits
//{
//template<>
//struct is_container<ice_script::ast::FuncattrNode> : boost::mpl::true_
//{};
//
//template<>
//struct container_value<ice_script::ast::FuncattrNode>
//{
//    typedef std::string type;
//};
//
//template<>
//struct push_back_container<ice_script::ast::FuncattrNode, std::string>
//{
//    static bool call(ice_script::ast::FuncattrNode& c, std::string val)
//    {
//        c.value.push_back(val);
//        return true;
//    }
//};
//}}}
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::StatementNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::SwitchNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::BreakNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::ForNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::WhileNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::DowhileNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::IfNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::ContinueNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::ExprstatNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::TryNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::ReturnNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::CaseNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::ExprNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::ExprtermNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::ExprvalueNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::ConstructcallNode,
//        typeNode,
//        arglistNode
////        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::ExprpreopNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::ExprpostopNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::CastNode,
//        typeNode,
//        assignNode
////        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::LambdaNode,
//        typeNodeStuff,
//        statblockNode
////        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::LiteralNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::FunccallNode,
//        scopeNode,
//        identifierNode,
//        arglistNode
////        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::VaraccessNode,
//        scopeNode,
//        identifierNode
////        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::ArglistNode,
//        identifierNode1,
//        assignNode1,
//        identifierNodeAssignNode2
////        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::AssignNode,
//        conditionNode,
//        assignopNodeAssignNode
////        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::ConditionNode,
//        exprNode,
//        assignNode
////        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::ExpropNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::BitopNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::MathopNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::CompopNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::LogicopNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::AssignopNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::StringNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::IdentifierNode,
//        value
//)
//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::NumberNode,
//        value
//)
////BOOST_FUSION_ADAPT_STRUCT(
////        ice_script::ast::BitsNode,
////        value
////)

#endif //ICE_SCRIPT_ASTALL_HPP
