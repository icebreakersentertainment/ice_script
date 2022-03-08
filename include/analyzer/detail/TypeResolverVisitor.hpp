#ifndef ICE_SCRIPT_TYPERESOLVERVISITOR_HPP
#define ICE_SCRIPT_TYPERESOLVERVISITOR_HPP

#include "asg/Type.hpp"
#include "asg/Expressionvalue.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

class TypeResolverVisitor : public AbstractVisitor<TypeResolverVisitor, std::shared_ptr<asg::Type>>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    std::shared_ptr<asg::Type> operator()(const ast::Void& voidType);
    std::shared_ptr<asg::Type> operator()(const asg::Constructcall& constructcall);
    std::shared_ptr<asg::Type> operator()(const asg::Functioncall& functioncall);
    std::shared_ptr<asg::Type> operator()(const asg::Variableaccess& variableaccess);
    std::shared_ptr<asg::Type> operator()(const asg::Cast& cast);
    std::shared_ptr<asg::Type> operator()(const asg::Literal& literal);
    std::shared_ptr<asg::Type> operator()(const asg::Assign& assign);
    std::shared_ptr<asg::Type> operator()(const asg::Lambda& lambda);
    std::shared_ptr<asg::Type> operator()(const asg::Variable& variable);
    std::shared_ptr<asg::Type> operator()(const asg::Number& number);
    std::shared_ptr<asg::Type> operator()(const asg::String& string);
    std::shared_ptr<asg::Type> operator()(const asg::Bits& bits);
    std::shared_ptr<asg::Type> operator()(const ast::Boolean& boolean);
    std::shared_ptr<asg::Type> operator()(const ast::Null& null);
};

}}}

#endif //ICE_SCRIPT_TYPERESOLVERVISITOR_HPP
