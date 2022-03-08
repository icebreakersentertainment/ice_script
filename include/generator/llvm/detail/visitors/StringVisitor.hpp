#ifndef ICE_SCRIPT_GENERATOR_STRINGVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_STRINGVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using StringVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class StringVisitor : public AbstractVisitor<StringVisitor, StringVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_STRINGVISITOR_HPP
