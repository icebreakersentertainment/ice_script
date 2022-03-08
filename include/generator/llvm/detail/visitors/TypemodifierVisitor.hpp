#ifndef ICE_SCRIPT_GENERATOR_TYPEMODIFIERVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_TYPEMODIFIERVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using TypemodifierVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class TypemodifierVisitor : public AbstractVisitor<TypemodifierVisitor, TypemodifierVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_TYPEMODIFIERVISITOR_HPP
