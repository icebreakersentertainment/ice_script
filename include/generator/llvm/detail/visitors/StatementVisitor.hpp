#ifndef ICE_SCRIPT_GENERATOR_STATEMENTVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_STATEMENTVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/IfGenerator.hpp"
#include "generator/llvm/detail/generators/ForGenerator.hpp"
#include "generator/llvm/detail/generators/WhileGenerator.hpp"
#include "generator/llvm/detail/generators/ReturnGenerator.hpp"
#include "generator/llvm/detail/generators/StatblockGenerator.hpp"
#include "generator/llvm/detail/generators/BreakGenerator.hpp"
#include "generator/llvm/detail/generators/ContinueGenerator.hpp"
#include "generator/llvm/detail/generators/DowhileGenerator.hpp"
#include "generator/llvm/detail/generators/SwitchGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionstatGenerator.hpp"
#include "generator/llvm/detail/generators/TryGenerator.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using StatementVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class StatementVisitor : public AbstractVisitor<StatementVisitor, StatementVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    StatementVisitorResultType operator()(const asg::If& ifStatement)
    {
        return process(*context_, *llvm_, ifStatement);
    }

    StatementVisitorResultType operator()(const asg::For& forLoop)
    {
        return process(*context_, *llvm_, forLoop);
    }

    StatementVisitorResultType operator()(const asg::While& whileLoop)
    {
        return process(*context_, *llvm_, whileLoop);
    }

    StatementVisitorResultType operator()(const asg::Return& returnStatement)
    {
        return process(*context_, *llvm_, returnStatement);
    }

    StatementVisitorResultType operator()(const asg::Statblock& statblock)
    {
        return process(*context_, *llvm_, statblock);
    }

    StatementVisitorResultType operator()(const asg::Break& breakStatement)
    {
        return process(*context_, *llvm_, breakStatement);
    }

    StatementVisitorResultType operator()(const asg::Continue& continueStatement)
    {
        return process(*context_, *llvm_, continueStatement);
    }

    StatementVisitorResultType operator()(const asg::Dowhile& dowhile)
    {
        return process(*context_, *llvm_, dowhile);
    }

    StatementVisitorResultType operator()(const asg::Switch& switchStatement)
    {
        return process(*context_, *llvm_, switchStatement);
    }

    StatementVisitorResultType operator()(const asg::Expressionstat& expressionstat)
    {
        return process(*context_, *llvm_, expressionstat);
    }

    StatementVisitorResultType operator()(const asg::Try& tryStatement)
    {
        return process(*context_, *llvm_, tryStatement);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_STATEMENTVISITOR_HPP
