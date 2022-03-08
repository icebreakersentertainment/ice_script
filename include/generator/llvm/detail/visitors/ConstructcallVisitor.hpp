#ifndef ICE_SCRIPT_GENERATOR_CONSTRUCTCALLVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_CONSTRUCTCALLVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using ConstructcallVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class ConstructcallVisitor : public AbstractVisitor<ConstructcallVisitor, ConstructcallVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        ConstructcallVisitorResultType operator()(const asg::Type& type);
    ConstructcallVisitorResultType operator()(const asg::Arglist& arglist);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_CONSTRUCTCALLVISITOR_HPP
