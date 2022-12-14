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

    NumberVisitorResultType operator()(const asg::Integer8& integer8)
    {
        return llvm_->builder().getInt8(integer8.value);
    }

    NumberVisitorResultType operator()(const asg::Integer16& integer16)
    {
        return llvm_->builder().getInt16(integer16.value);
    }

    NumberVisitorResultType operator()(const asg::Integer32& integer32)
    {
        return llvm_->builder().getInt32(integer32.value);
    }

    NumberVisitorResultType operator()(const asg::Integer& integer)
    {
        return llvm_->builder().getInt32(integer.value);
    }

    NumberVisitorResultType operator()(const asg::Integer64& integer64)
    {
        return llvm_->builder().getInt64(integer64.value);
    }

    NumberVisitorResultType operator()(const asg::UInteger8& uinteger8)
    {
        return llvm_->builder().getInt8(uinteger8.value);
    }

    NumberVisitorResultType operator()(const asg::UInteger16& uinteger16)
    {
        return llvm_->builder().getInt16(uinteger16.value);
    }

    NumberVisitorResultType operator()(const asg::UInteger32& uinteger32)
    {
        return llvm_->builder().getInt32(uinteger32.value);
    }

    NumberVisitorResultType operator()(const asg::UInteger& uinteger)
    {
        return llvm_->builder().getInt32(uinteger.value);
    }

    NumberVisitorResultType operator()(const asg::UInteger64& uinteger64)
    {
        return llvm_->builder().getInt64(uinteger64.value);
    }

    NumberVisitorResultType operator()(const asg::Float& floatValue)
    {
        return ::llvm::ConstantFP::get(llvm_->context(), ::llvm::APFloat(floatValue.value));
    //    return llvm_->builder().get(uinteger64.value);
    }

    NumberVisitorResultType operator()(const asg::Double& doubleValue)
    {
        return ::llvm::ConstantFP::get(llvm_->context(), ::llvm::APFloat(doubleValue.value));
    //    return llvm_->builder().getInt64(uinteger64.value);
    }
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_NUMBERVISITOR_HPP
