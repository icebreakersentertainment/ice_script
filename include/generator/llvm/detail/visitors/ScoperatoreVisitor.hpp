#ifndef ICE_SCRIPT_GENERATOR_SCOPERATOREVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_SCOPERATOREVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/TypeGenerator.hpp"

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

    ScoperatoreVisitorResultType operator()(const asg::Identifier& identifier)
    {
        return process(*context_, *llvm_, identifier);
    }

    ScoperatoreVisitorResultType operator()(const Type& type)
    {
        return process(*context_, *llvm_, type);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_SCOPERATOREVISITOR_HPP
