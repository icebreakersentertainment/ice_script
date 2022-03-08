#ifndef ICE_SCRIPT_GENERATOR_BITOPERATORVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_BITOPERATORVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using BitoperatorVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class BitoperatorVisitor : public AbstractVisitor<BitoperatorVisitor, BitoperatorVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_BITOPERATORVISITOR_HPP
