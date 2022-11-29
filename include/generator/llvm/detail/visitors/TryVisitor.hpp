#ifndef ICE_SCRIPT_GENERATOR_TRYVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_TRYVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/StatblockGenerator.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using TryVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class TryVisitor : public AbstractVisitor<TryVisitor, TryVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    TryVisitorResultType operator()(const asg::Statblock& statblock)
    {
        return process(*context_, *llvm_, statblock);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_TRYVISITOR_HPP
