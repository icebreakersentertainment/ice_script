#ifndef ICE_SCRIPT_GENERATOR_ASSIGNVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_ASSIGNVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using AssignVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class AssignVisitor : public AbstractVisitor<AssignVisitor, AssignVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        AssignVisitorResultType operator()(const asg::Condition& condition);
    AssignVisitorResultType operator()(const asg::Assignoperator& assignoperator);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_ASSIGNVISITOR_HPP
