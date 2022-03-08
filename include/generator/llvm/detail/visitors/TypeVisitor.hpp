#ifndef ICE_SCRIPT_GENERATOR_TYPEVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_TYPEVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

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

        TypeVisitorResultType operator()(const asg::Scoperatore& scoperatore);
    TypeVisitorResultType operator()(const asg::Datatype& datatype);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_TYPEVISITOR_HPP
