#ifndef ICE_SCRIPT_GENERATOR_PRIMATIVETYPEVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_PRIMATIVETYPEVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using PrimativetypeVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class PrimativetypeVisitor : public AbstractVisitor<PrimativetypeVisitor, PrimativetypeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_PRIMATIVETYPEVISITOR_HPP
