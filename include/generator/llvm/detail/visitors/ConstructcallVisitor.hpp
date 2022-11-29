#ifndef ICE_SCRIPT_GENERATOR_CONSTRUCTCALLVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_CONSTRUCTCALLVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/TypeGenerator.hpp"
#include "generator/llvm/detail/generators/ArglistGenerator.hpp"

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

    ConstructcallVisitorResultType operator()(const Type& type)
    {
        return process(*context_, *llvm_, type);
    }

    ConstructcallVisitorResultType operator()(const asg::Arglist& arglist)
    {
        return process(*context_, *llvm_, arglist);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_CONSTRUCTCALLVISITOR_HPP
