#ifndef ICE_SCRIPT_GENERATOR_CLASSVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_CLASSVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using ClassVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class ClassVisitor : public AbstractVisitor<ClassVisitor, ClassVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        ClassVisitorResultType operator()(const asg::Identifier& identifier);
    ClassVisitorResultType operator()(const asg::Virtualproperatorerty& virtualproperatorerty);
    ClassVisitorResultType operator()(const asg::Function& function);
    ClassVisitorResultType operator()(const asg::Variable& variable);
    ClassVisitorResultType operator()(const asg::Functiondefinition& functiondefinition);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_CLASSVISITOR_HPP
