#ifndef ICE_SCRIPT_GENERATOR_FORVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_FORVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using ForVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class ForVisitor : public AbstractVisitor<ForVisitor, ForVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        ForVisitorResultType operator()(const asg::Variable& variable);
    ForVisitorResultType operator()(const asg::Expressionstat& expressionstat);
    ForVisitorResultType operator()(const asg::Assign& assign);
    ForVisitorResultType operator()(const asg::Statement& statement);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_FORVISITOR_HPP
