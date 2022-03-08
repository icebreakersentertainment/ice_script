#ifndef ICE_SCRIPT_GENERATOR_INITLISTVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_INITLISTVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using InitlistVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class InitlistVisitor : public AbstractVisitor<InitlistVisitor, InitlistVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        InitlistVisitorResultType operator()(const asg::Assign& assign);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_INITLISTVISITOR_HPP
