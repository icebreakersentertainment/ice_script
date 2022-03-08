#ifndef ICE_SCRIPT_GENERATOR_COMPARISONOPERATORVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_COMPARISONOPERATORVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using ComparisonoperatorVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class ComparisonoperatorVisitor : public AbstractVisitor<ComparisonoperatorVisitor, ComparisonoperatorVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_COMPARISONOPERATORVISITOR_HPP
