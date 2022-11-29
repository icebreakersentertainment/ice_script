#ifndef ICE_SCRIPT_GENERATOR_TYPEVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_TYPEVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/ScoperatoreGenerator.hpp"
#include "generator/llvm/detail/generators/DatatypeGenerator.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using TypeVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class TypeVisitor : public AbstractVisitor<TypeVisitor, TypeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    TypeVisitorResultType operator()(const asg::Scoperatore& scoperatore)
    {
        return process(*context_, *llvm_, scoperatore);
    }

    TypeVisitorResultType operator()(const asg::Datatype& datatype)
    {
        return process(*context_, *llvm_, datatype);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_TYPEVISITOR_HPP
