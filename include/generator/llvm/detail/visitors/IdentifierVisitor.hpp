#ifndef ICE_SCRIPT_GENERATOR_IDENTIFIERVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_IDENTIFIERVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using IdentifierVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class IdentifierVisitor : public AbstractVisitor<IdentifierVisitor, IdentifierVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_IDENTIFIERVISITOR_HPP
