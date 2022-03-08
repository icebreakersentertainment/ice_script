#ifndef ICE_SCRIPT_GENERATOR_MIXINVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_MIXINVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using MixinVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class MixinVisitor : public AbstractVisitor<MixinVisitor, MixinVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        MixinVisitorResultType operator()(const asg::Class& classData);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_MIXINVISITOR_HPP
