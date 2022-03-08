#ifndef ICE_SCRIPT_GENERATOR_SWITCHVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_SWITCHVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

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

        SwitchVisitorResultType operator()(const asg::Assign& assign);
    SwitchVisitorResultType operator()(const asg::Case& caseStatement);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_SWITCHVISITOR_HPP
