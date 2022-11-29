#include "analyzer/detail/analyzers/VarNodeAnalyzer.hpp"

#include "analyzer/detail/visitors/VarNodeVisitor.hpp"
#include "analyzer/detail/SymbolKeyResolver.hpp"
#include "analyzer/detail/TypeKeyResolver.hpp"

#include "analyzer/detail/TypeResolver.hpp"

#include "detail/SymbolKeyResolver.hpp"
#include "detail/monostate.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;
using namespace ice_script::detail;

auto toExpression(Context& context, ExpressionValueType value)
{
    Expression expression{};
    Expressionvalue expressionvalue{};
    expressionvalue.value = value;
    expression.expressionterm.get().value = asg::ExprpreopsExprvalueExprpostops({}, expressionvalue, {});

    return expression;
}

auto toLiteral(Context& context, asg::Number value)
{
    Literal literal{};
    
    literal.value = value;

    return literal;
}

auto toNumber(Context& context, int8_t value)
{
    asg::Number number{};

    return number;
}

auto toInteger8(Context& context, int8_t value)
{
    asg::Integer8 integer8{};

    integer8.type = context.typeTable().get(ast::PrimitiveType::INT8);
    integer8.value = value;

    return integer8;
}

template <typename T, typename V>
auto toNumberType(Context& context, std::shared_ptr<Type> type, V value)
{
    T numberType{};

    numberType.type = std::move(type);
    numberType.value = value;

    return numberType;
}

boost::variant<monostate, boost::recursive_wrapper<Initlist>, boost::recursive_wrapper<Expression>, boost::recursive_wrapper<Arglist>> createDefaultInitializer(Context& context, const Symbol& symbol)
{
    switch (symbol.type()->typeId())
    {
        case Type::TypeId::VOID_T: return toExpression(context, ast::Void());
        case Type::TypeId::INTEGER8: return toExpression(context, toLiteral(context, asg::Number(toNumberType<asg::Integer8>(context, symbol.type(), 0))));
        case Type::TypeId::INTEGER16: return toExpression(context, toLiteral(context, asg::Number(toNumberType<asg::Integer16>(context, symbol.type(), 0))));
        case Type::TypeId::INTEGER32: return toExpression(context, toLiteral(context, asg::Number(toNumberType<asg::Integer32>(context, symbol.type(), 0))));
        case Type::TypeId::INTEGER: return toExpression(context, toLiteral(context, asg::Number(toNumberType<asg::Integer>(context, symbol.type(), 0))));
        case Type::TypeId::INTEGER64: return toExpression(context, toLiteral(context, asg::Number(toNumberType<asg::Integer64>(context, symbol.type(), 0))));
        case Type::TypeId::UINTEGER8: return toExpression(context, toLiteral(context, asg::Number(toNumberType<asg::UInteger8>(context, symbol.type(), 0))));
        case Type::TypeId::UINTEGER16: return toExpression(context, toLiteral(context, asg::Number(toNumberType<asg::UInteger16>(context, symbol.type(), 0))));
        case Type::TypeId::UINTEGER32: return toExpression(context, toLiteral(context, asg::Number(toNumberType<asg::UInteger32>(context, symbol.type(), 0))));
        case Type::TypeId::UINTEGER: return toExpression(context, toLiteral(context, asg::Number(toNumberType<asg::UInteger>(context, symbol.type(), 0))));
        case Type::TypeId::UINTEGER64: return toExpression(context, toLiteral(context, asg::Number(toNumberType<asg::UInteger64>(context, symbol.type(), 0))));
        case Type::TypeId::FLOAT: return toExpression(context, toLiteral(context, asg::Number(toNumberType<asg::Float>(context, symbol.type(), 0.0f))));
        case Type::TypeId::DOUBLE: return toExpression(context, toLiteral(context, asg::Number(toNumberType<asg::Double>(context, symbol.type(), 0.0))));
        case Type::TypeId::ARRAY:
        {
            // const auto classSymbol = dynamic_cast<const ClassSymbol&>(symbol);
            const auto arrayType = std::dynamic_pointer_cast<ArrayType>(symbol.type());
            
            ICE_SCRIPT_ASSERT(arrayType);

            // const auto& constructors = arrayType->constructors();
            // std::shared_ptr<FunctionType> defaultConstructor{};

            // for (const auto& constructor : constructors)
            // {
            //     if (constructor->parameters().empty())
            //     {
            //         defaultConstructor = constructor;
            //         break;
            //     }
            // }

            // if (!defaultConstructor) throw RuntimeException(format("No default constructor available for type '%s'", arrayType));
            
            // const auto symbolKey = resolveSymbolKey(context, arrayType);
            const auto symbolKey = ice_script::detail::resolveSymbolKey(arrayType);
            
            const auto& arraySymbol = context.symbolTable().getArrayByKey(symbolKey);

            const auto& constructors = arraySymbol->constructors();
            std::shared_ptr<FunctionSymbol> defaultConstructor{};

            for (const auto& constructor : constructors)
            {
                if (constructor->parameters().empty())
                {
                    defaultConstructor = constructor;
                    break;
                }
            }

            if (!defaultConstructor) throw RuntimeException(format("No default constructor available for type '%s'", arrayType));

            Constructcall constructcall{};
            constructcall.symbol = defaultConstructor;
            return toExpression(context, constructcall);
        }
        
        case Type::TypeId::CLASS:
        {
            // const auto classSymbol = dynamic_cast<const ClassSymbol&>(symbol);
            const auto classType = std::dynamic_pointer_cast<ClassType>(symbol.type());
            
            ICE_SCRIPT_ASSERT(classType);

            // const auto& constructors = classType->constructors();
            // std::shared_ptr<FunctionType> defaultConstructor{};

            // for (const auto& constructor : constructors)
            // {
            //     if (constructor->parameters().empty())
            //     {
            //         defaultConstructor = constructor;
            //         break;
            //     }
            // }

            // if (!defaultConstructor) throw RuntimeException(format("No default constructor available for type '%s'", classType));
            
            // const auto symbolKey = resolveSymbolKey(context, classType);
            const auto symbolKey = ice_script::detail::resolveSymbolKey(classType);
            
            const auto& classSymbol = context.symbolTable().getClassByKey(symbolKey);

            const auto& constructors = classSymbol->constructors();
            std::shared_ptr<FunctionSymbol> defaultConstructor{};

            for (const auto& constructor : constructors)
            {
                if (constructor->parameters().empty())
                {
                    defaultConstructor = constructor;
                    break;
                }
            }

            if (!defaultConstructor) throw RuntimeException(format("No default constructor available for type '%s'", classType));

            Constructcall constructcall{};
            constructcall.symbol = defaultConstructor;
            return toExpression(context, constructcall);
        }
//        case Type::TypeId::FUNCTION: return ::llvm::Type::getDoubleTy(context);
//        case Type::TypeId::OPERATOR: return ::llvm::Type::getDoubleTy(context);

        default:
            throw RuntimeException(format("Unknown type id '%s'", symbol.type()->typeId()));
    }
}

inline std::shared_ptr<Symbol> createSymbol(Context& context, const VarNode& node)
{
    const auto typeKey = resolveTypeKey(context, node);
    
    const auto type = context.typeTable().getByKey(typeKey);
    
    const auto name = node.identifierNode.get().value;

    auto symbol = std::make_shared<Symbol>(name);
    
    if (context.scope().valueSymbol())
    {
        symbol->setOwnerSymbol(context.scope().valueSymbol());
    }
    
    symbol->setType(type);
    // symbol->setFullyQualifiedScopeName(context.scope().fullyQualifiedName());

    return symbol;
}

asg::Variable process(Context& context, const ast::VarNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    const auto variableName = node.identifierNode.get().value;
    const auto symbolKey = resolveSymbolKey(context, node);
    
    auto symbol = scope.symbolTable().findByKey(symbolKey);
    
    if (!symbol)
    {
        symbol = context.symbolTable().findByKey(symbolKey);
    
        if (!symbol) symbol = createSymbol(context, node);
        
        scope.symbolTable().add(symbol);
    }

    scope.pushExpectedTypes({symbol->type()});

    Variable variable{};

//        if (node.visibility && scope.type() != ScopeType::CLASS)
//        {
//            throw IllegalStartOfExpressionException(node);
//        }

//        variable.visibility = node.visibility ? node.visibility.get() : ast::Visibility::PUBLIC;

    variable.symbol = symbol;
    variable.name = variableName;

    if (node.initListOrExprOrArgList)
    {
        VarNodeVisitor visitor{context};
        variable.value = boost::apply_visitor(visitor, node.initListOrExprOrArgList.get());
    }
    else
    {
        variable.value = createDefaultInitializer(context, *symbol);
    }

    scope.popExpectedTypes();

    return variable;
}

}}}