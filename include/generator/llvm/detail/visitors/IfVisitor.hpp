#ifndef ICE_SCRIPT_GENERATOR_IFVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_IFVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using IfVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class IfVisitor : public AbstractVisitor<IfVisitor, IfVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        IfVisitorResultType operator()(const asg::Assign& assign);
    IfVisitorResultType operator()(const asg::Statement& statement);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_IFVISITOR_HPP
