#ifndef ICE_SCRIPT_GENERATOR_RETURNVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_RETURNVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/AssignGenerator.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using ReturnVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class ReturnVisitor : public AbstractVisitor<ReturnVisitor, ReturnVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    ReturnVisitorResultType operator()(const asg::Assign& assign)
    {
        return process(*context_, *llvm_, assign);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_RETURNVISITOR_HPP
