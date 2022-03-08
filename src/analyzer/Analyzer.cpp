#include "analyzer/Analyzer.hpp"
#include "analyzer/AnalyzerVisitor.hpp"

#include "asg/OperatorType.hpp"

#include "detail/Format.hpp"

namespace ice_script { namespace analyzer {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Asg Analyzer::parse(const ast::Ast& ast)
{
    using namespace boost::spirit::qi;
    using boost::spirit::ascii::space;

    Asg asg;

    Context context{};
    Scope scope{};
    SymbolTable symbolTable{};

    TypeTable& typeTable = context.typeTable();

    auto primitiveTypeInt8 = std::make_shared<asg::PrimitiveType>(ast::PrimitiveType::INT8);
    auto primitiveTypeInt16 = std::make_shared<asg::PrimitiveType>(ast::PrimitiveType::INT16);
    auto primitiveTypeInt32 = std::make_shared<asg::PrimitiveType>(ast::PrimitiveType::INT32);
    auto primitiveTypeInt = std::make_shared<asg::PrimitiveType>(ast::PrimitiveType::INT);
    auto primitiveTypeInt64 = std::make_shared<asg::PrimitiveType>(ast::PrimitiveType::INT64);
    auto primitiveTypeUint8 = std::make_shared<asg::PrimitiveType>(ast::PrimitiveType::UINT8);
    auto primitiveTypeUint16 = std::make_shared<asg::PrimitiveType>(ast::PrimitiveType::UINT16);
    auto primitiveTypeUint32 = std::make_shared<asg::PrimitiveType>(ast::PrimitiveType::UINT32);
    auto primitiveTypeUint = std::make_shared<asg::PrimitiveType>(ast::PrimitiveType::UINT);
    auto primitiveTypeUint64 = std::make_shared<asg::PrimitiveType>(ast::PrimitiveType::UINT64);
    auto primitiveTypeFloat = std::make_shared<asg::PrimitiveType>(ast::PrimitiveType::FLOAT);
    auto primitiveTypeDouble = std::make_shared<asg::PrimitiveType>(ast::PrimitiveType::DOUBLE);

    {
        std::vector<std::shared_ptr<OperatorType>> operators{};

        auto _operator = std::make_shared<OperatorType>(OperatorTypeId::IMPLICIT_CONVERSION);
        _operator->setReturnType(primitiveTypeInt32);

        operators.push_back(_operator);

        primitiveTypeInt8->setName("int8");
        primitiveTypeInt8->setOperators(operators);
    }

    {
        std::vector<std::shared_ptr<OperatorType>> operators{};

        auto _operator = std::make_shared<OperatorType>(OperatorTypeId::IMPLICIT_CONVERSION);
        _operator->setReturnType(primitiveTypeUint8);

        operators.push_back(_operator);

        primitiveTypeFloat->setName("float");
        primitiveTypeFloat->setOperators(operators);
    }

    {
        std::vector<std::shared_ptr<OperatorType>> operators{};

        auto _operator = std::make_shared<OperatorType>(OperatorTypeId::IMPLICIT_CONVERSION);
        _operator->setReturnType(primitiveTypeUint8);

        operators.push_back(_operator);

        primitiveTypeDouble->setName("double");
        primitiveTypeDouble->setOperators(operators);
    }

    {
        std::vector<std::shared_ptr<OperatorType>> operators{};

        auto _operator = std::make_shared<OperatorType>(OperatorTypeId::IMPLICIT_CONVERSION);
        _operator->setReturnType(primitiveTypeInt);

        operators.push_back(_operator);

        _operator = std::make_shared<OperatorType>(OperatorTypeId::IMPLICIT_CONVERSION);
        _operator->setReturnType(primitiveTypeInt32);

        operators.push_back(_operator);

        primitiveTypeUint32->setName("uint32");
        primitiveTypeUint32->setOperators(operators);
    }

    primitiveTypeInt8->setName("int8");
    primitiveTypeInt16->setName("int16");
    primitiveTypeInt32->setName("int32");
    primitiveTypeInt->setName("int");
    primitiveTypeInt64->setName("int64");
    primitiveTypeUint8->setName("uint8");
    primitiveTypeUint16->setName("uint16");
    primitiveTypeUint32->setName("uint32");
    primitiveTypeUint->setName("uint");
    primitiveTypeUint64->setName("uint64");
    primitiveTypeFloat->setName("float");
    primitiveTypeDouble->setName("double");


    typeTable.add(primitiveTypeInt8);
    typeTable.add(primitiveTypeInt16);
    typeTable.add(primitiveTypeInt32);
    typeTable.add(primitiveTypeInt);
    typeTable.add(primitiveTypeInt64);
    typeTable.add(primitiveTypeUint8);
    typeTable.add(primitiveTypeUint16);
    typeTable.add(primitiveTypeUint32);
    typeTable.add(primitiveTypeUint);
    typeTable.add(primitiveTypeUint64);
    typeTable.add(primitiveTypeFloat);
    typeTable.add(primitiveTypeDouble);

    AnalyzerVisitor analyzerVisitor{*logger_, context, scope, symbolTable};

//    std::cout << context << std::endl;

    for (const auto& value : ast.root.scriptNode.value)
    {
        asg.root.nodes.push_back(boost::apply_visitor(analyzerVisitor, value));
    }

    return asg;
}

}}