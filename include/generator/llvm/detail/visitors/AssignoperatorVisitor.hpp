#ifndef ICE_SCRIPT_GENERATOR_ASSIGNOPERATORVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_ASSIGNOPERATORVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using AssignoperatorVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class AssignoperatorVisitor : public AbstractVisitor<AssignoperatorVisitor, AssignoperatorVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_ASSIGNOPERATORVISITOR_HPP
