#ifndef ICE_SCRIPT_GENERATOR_TYPEDEFINITIONVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_TYPEDEFINITIONVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/PrimativetypeGenerator.hpp"
#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"

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

    TypedefinitionVisitorResultType operator()(const asg::Primativetype& primativetype)
    {
        return process(*context_, *llvm_, primativetype);
    }

    TypedefinitionVisitorResultType operator()(const asg::Identifier& identifier)
    {
        return process(*context_, *llvm_, identifier);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_TYPEDEFINITIONVISITOR_HPP
