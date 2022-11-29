#ifndef ICE_SCRIPT_GENERATOR_IFVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_IFVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/AssignGenerator.hpp"
#include "generator/llvm/detail/generators/StatementGenerator.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using IfVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class IfVisitor : public AbstractVisitor<IfVisitor, IfVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    IfVisitorResultType operator()(const asg::Assign& assign)
    {
        return process(*context_, *llvm_, assign);
    }

    IfVisitorResultType operator()(const asg::Statement& statement)
    {
        return process(*context_, *llvm_, statement);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_IFVISITOR_HPP
