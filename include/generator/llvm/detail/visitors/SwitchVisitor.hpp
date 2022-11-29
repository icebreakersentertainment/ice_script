#ifndef ICE_SCRIPT_GENERATOR_SWITCHVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_SWITCHVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/AssignGenerator.hpp"
#include "generator/llvm/detail/generators/CaseGenerator.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using SwitchVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class SwitchVisitor : public AbstractVisitor<SwitchVisitor, SwitchVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    SwitchVisitorResultType operator()(const asg::Assign& assign)
    {
        return process(*context_, *llvm_, assign);
    }

    SwitchVisitorResultType operator()(const asg::Case& case)
    {
        return process(*context_, *llvm_, case);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_SWITCHVISITOR_HPP
