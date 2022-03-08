#ifndef ICE_SCRIPT_GENERATOR_NUMBERVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_NUMBERVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using NumberVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class NumberVisitor : public AbstractVisitor<NumberVisitor, NumberVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    NumberVisitorResultType operator()(const asg::Integer8& integer8);
    NumberVisitorResultType operator()(const asg::Integer16& integer16);
    NumberVisitorResultType operator()(const asg::Integer32& integer32);
    NumberVisitorResultType operator()(const asg::Integer& integer);
    NumberVisitorResultType operator()(const asg::Integer64& integer64);
    NumberVisitorResultType operator()(const asg::UInteger8& uinteger8);
    NumberVisitorResultType operator()(const asg::UInteger16& uinteger16);
    NumberVisitorResultType operator()(const asg::UInteger32& uinteger32);
    NumberVisitorResultType operator()(const asg::UInteger& uinteger);
    NumberVisitorResultType operator()(const asg::UInteger64& uinteger64);
    NumberVisitorResultType operator()(const asg::Float& floatValue);
    NumberVisitorResultType operator()(const asg::Double& doubleValue);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_NUMBERVISITOR_HPP
