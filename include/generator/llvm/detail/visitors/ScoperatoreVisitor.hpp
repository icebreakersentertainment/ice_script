#ifndef ICE_SCRIPT_GENERATOR_SCOPERATOREVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_SCOPERATOREVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using ScoperatoreVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class ScoperatoreVisitor : public AbstractVisitor<ScoperatoreVisitor, ScoperatoreVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        ScoperatoreVisitorResultType operator()(const asg::Identifier& identifier);
    ScoperatoreVisitorResultType operator()(const asg::Type& type);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_SCOPERATOREVISITOR_HPP
