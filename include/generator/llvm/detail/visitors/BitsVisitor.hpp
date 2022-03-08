#ifndef ICE_SCRIPT_GENERATOR_BITSVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_BITSVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using BitsVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class BitsVisitor : public AbstractVisitor<BitsVisitor, BitsVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_BITSVISITOR_HPP
