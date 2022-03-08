#ifndef ICE_SCRIPT_GENERATOR_TYPEDEFINITIONVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_TYPEDEFINITIONVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using TypedefinitionVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class TypedefinitionVisitor : public AbstractVisitor<TypedefinitionVisitor, TypedefinitionVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        TypedefinitionVisitorResultType operator()(const asg::Primativetype& primativetype);
    TypedefinitionVisitorResultType operator()(const asg::Identifier& identifier);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_TYPEDEFINITIONVISITOR_HPP
