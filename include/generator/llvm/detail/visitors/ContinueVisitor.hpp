#ifndef ICE_SCRIPT_GENERATOR_CONTINUEVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_CONTINUEVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using ContinueVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class ContinueVisitor : public AbstractVisitor<ContinueVisitor, ContinueVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_CONTINUEVISITOR_HPP
