#ifndef ICE_SCRIPT_GENERATOR_STATBLOCKVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_STATBLOCKVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

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

        StatblockVisitorResultType operator()(const asg::Variable& variable);
    StatblockVisitorResultType operator()(const asg::Statement& statement);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_STATBLOCKVISITOR_HPP
