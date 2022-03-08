#ifndef ICE_SCRIPT_GENERATOR_LOGICOPERATORVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_LOGICOPERATORVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using LogicoperatorVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class LogicoperatorVisitor : public AbstractVisitor<LogicoperatorVisitor, LogicoperatorVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_LOGICOPERATORVISITOR_HPP
