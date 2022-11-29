#ifndef ICE_SCRIPT_GENERATOR_STATBLOCKVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_STATBLOCKVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/VariableGenerator.hpp"
#include "generator/llvm/detail/generators/StatementGenerator.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using StatblockVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class StatblockVisitor : public AbstractVisitor<StatblockVisitor, StatblockVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    StatblockVisitorResultType operator()(const asg::Variable& variable)
    {
        return process(*context_, *llvm_, variable);
    }

    StatblockVisitorResultType operator()(const asg::Statement& statement)
    {
        return process(*context_, *llvm_, statement);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_STATBLOCKVISITOR_HPP
