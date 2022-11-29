#ifndef ICE_SCRIPT_TYPERESOLVERVISITOR_HPP
#define ICE_SCRIPT_TYPERESOLVERVISITOR_HPP

#include "type/Type.hpp"
#include "asg/Expressionvalue.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/TypeResolver.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

class TypeResolverVisitor : public AbstractVisitor<TypeResolverVisitor, std::shared_ptr<Type>>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    std::shared_ptr<Type> operator()(const ast::Void& voidType) const
    {
        return context_->typeTable().get(Type::TypeId::VOID_T)[0];
    }

    std::shared_ptr<Type> operator()(const asg::Constructcall& constructcall) const
    {
        return constructcall.symbol->type()->returnType();
    }

    std::shared_ptr<Type> operator()(const asg::Functioncall& functioncall) const
    {
        if (functioncall.type) return functioncall.type->returnType();
        
        return functioncall.symbol->type()->returnType();
    }

    std::shared_ptr<Type> operator()(const asg::Variableaccess& variableaccess) const
    {
        return variableaccess.symbol->type();
    }

    std::shared_ptr<Type> operator()(const asg::Cast& cast) const
    {
        return {};
    }

    std::shared_ptr<Type> operator()(const asg::Literal& literal) const
    {
        return boost::apply_visitor(*this, literal.value);
    }

    std::shared_ptr<Type> operator()(const asg::Assign& assign) const
    {
        return operator()(assign.condition);
    }

    std::shared_ptr<Type> operator()(const asg::Lambda& lambda) const
    {
        return {};
    }

    std::shared_ptr<Type> operator()(const asg::Condition& condition) const
    {
        return resolveType(*context_, condition.expression.get());
    }

    std::shared_ptr<Type> operator()(const asg::Variable& variable) const
    {
        return variable.symbol->type();
    }

    std::shared_ptr<Type> operator()(const asg::Number& number) const
    {
//        return number.type;
        return boost::apply_visitor(*this, number.value);
    }

    std::shared_ptr<Type> operator()(const asg::String& string) const
    {
        return {};
    }

    std::shared_ptr<Type> operator()(const asg::Bits& bits) const
    {
        return {};
    }

    std::shared_ptr<Type> operator()(const ast::Boolean& boolean) const
    {
        return {};
    }

    std::shared_ptr<Type> operator()(const ast::Null& null) const
    {
        return {};
    }

    std::shared_ptr<Type> operator()(const asg::Integer8& integer8) const
    {
        return context_->typeTable().get(Type::TypeId::INTEGER8)[0];
    }

    std::shared_ptr<Type> operator()(const asg::Integer16& integer16) const
    {
        return context_->typeTable().get(Type::TypeId::INTEGER16)[0];
    }

    std::shared_ptr<Type> operator()(const asg::Integer32& integer32) const
    {
        return context_->typeTable().get(Type::TypeId::INTEGER32)[0];
    }

    std::shared_ptr<Type> operator()(const asg::Integer& integer) const
    {
        return context_->typeTable().get(Type::TypeId::INTEGER)[0];
    }

    std::shared_ptr<Type> operator()(const asg::Integer64& integer64) const
    {
        return context_->typeTable().get(Type::TypeId::INTEGER64)[0];
    }

    std::shared_ptr<Type> operator()(const asg::UInteger8& uInteger8) const
    {
        return context_->typeTable().get(Type::TypeId::UINTEGER8)[0];
    }

    std::shared_ptr<Type> operator()(const asg::UInteger16& uInteger16) const
    {
        return context_->typeTable().get(Type::TypeId::UINTEGER16)[0];
    }

    std::shared_ptr<Type> operator()(const asg::UInteger32& uInteger32) const
    {
        return context_->typeTable().get(Type::TypeId::UINTEGER32)[0];
    }

    std::shared_ptr<Type> operator()(const asg::UInteger& uInteger) const
    {
        return context_->typeTable().get(Type::TypeId::UINTEGER)[0];
    }

    std::shared_ptr<Type> operator()(const asg::UInteger64& uInteger64) const
    {
        return context_->typeTable().get(Type::TypeId::UINTEGER64)[0];
    }

    std::shared_ptr<Type> operator()(const asg::Float& floatType) const
    {
        return context_->typeTable().get(Type::TypeId::FLOAT)[0];
    }

    std::shared_ptr<Type> operator()(const asg::Double& doubleType) const
    {
        return context_->typeTable().get(Type::TypeId::DOUBLE)[0];
    }
};

}}}

#endif //ICE_SCRIPT_TYPERESOLVERVISITOR_HPP
