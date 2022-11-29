#ifndef ICE_SCRIPT_GENERATOR_CASEVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_CASEVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/ExpressionGenerator.hpp"
#include "generator/llvm/detail/generators/StatementGenerator.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using CaseVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class CaseVisitor : public AbstractVisitor<CaseVisitor, CaseVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    CaseVisitorResultType operator()(const asg::Expression& expression)
    {
        return process(*context_, *llvm_, expression);
    }

    CaseVisitorResultType operator()(const asg::Statement& statement)
    {
        return process(*context_, *llvm_, statement);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_CASEVISITOR_HPP
