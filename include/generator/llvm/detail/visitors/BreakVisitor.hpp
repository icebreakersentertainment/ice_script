#ifndef ICE_SCRIPT_GENERATOR_BREAKVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_BREAKVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using BreakVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class BreakVisitor : public AbstractVisitor<BreakVisitor, BreakVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_BREAKVISITOR_HPP
