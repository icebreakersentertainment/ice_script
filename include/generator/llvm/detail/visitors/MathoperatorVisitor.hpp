#ifndef ICE_SCRIPT_GENERATOR_MATHOPERATORVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_MATHOPERATORVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using MathoperatorVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class MathoperatorVisitor : public AbstractVisitor<MathoperatorVisitor, MathoperatorVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_MATHOPERATORVISITOR_HPP
