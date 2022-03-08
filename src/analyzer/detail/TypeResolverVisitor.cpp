#include "analyzer/detail/TypeResolverVisitor.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

std::shared_ptr<Type> TypeResolverVisitor::operator()(const Void& voidType)
{
    return context_->typeTable().get(Type::TypeId::VOID_T);
}

std::shared_ptr<Type> TypeResolverVisitor::operator()(const Constructcall& constructcall)
{
    return std::shared_ptr<Type>();
}

std::shared_ptr<Type> TypeResolverVisitor::operator()(const Functioncall& functioncall)
{
    return std::shared_ptr<Type>();
}

std::shared_ptr<Type> TypeResolverVisitor::operator()(const Variableaccess& variableaccess)
{
    const auto& symbol = context_->scope().symbolTable().get(variableaccess.name);

    return symbol->type();
}

std::shared_ptr<Type> TypeResolverVisitor::operator()(const Cast& cast)
{
    return std::shared_ptr<Type>();
}

std::shared_ptr<Type> TypeResolverVisitor::operator()(const Literal& literal)
{
    return boost::apply_visitor(*this, literal.value);
}

std::shared_ptr<Type> TypeResolverVisitor::operator()(const Assign& assign)
{
    return std::shared_ptr<Type>();
}

std::shared_ptr<Type> TypeResolverVisitor::operator()(const Lambda& lambda)
{
    return std::shared_ptr<Type>();
}

std::shared_ptr<asg::Type> TypeResolverVisitor::operator()(const Variable& variable)
{
    return variable.type;
}

std::shared_ptr<asg::Type> TypeResolverVisitor::operator()(const Number& number)
{
    return number.type;
}

std::shared_ptr<asg::Type> TypeResolverVisitor::operator()(const String& string)
{
    return std::shared_ptr<asg::Type>();
}

std::shared_ptr<asg::Type> TypeResolverVisitor::operator()(const Bits& bits)
{
    return std::shared_ptr<asg::Type>();
}

std::shared_ptr<asg::Type> TypeResolverVisitor::operator()(const Boolean& boolean)
{
    return std::shared_ptr<asg::Type>();
}

std::shared_ptr<asg::Type> TypeResolverVisitor::operator()(const Null& null)
{
    return std::shared_ptr<asg::Type>();
}

}}}