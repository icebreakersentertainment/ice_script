#ifndef ICE_SCRIPT_GENERATOR_ARGLISTVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_ARGLISTVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using ArglistVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class ArglistVisitor : public AbstractVisitor<ArglistVisitor, ArglistVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        ArglistVisitorResultType operator()(const asg::Identifier& identifier);
    ArglistVisitorResultType operator()(const asg::Assign& assign);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_ARGLISTVISITOR_HPP
