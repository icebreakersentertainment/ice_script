#ifndef ICE_SCRIPT_GENERATOR_WHILEVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_WHILEVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using WhileVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class WhileVisitor : public AbstractVisitor<WhileVisitor, WhileVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        WhileVisitorResultType operator()(const asg::Assign& assign);
    WhileVisitorResultType operator()(const asg::Statement& statement);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_WHILEVISITOR_HPP
