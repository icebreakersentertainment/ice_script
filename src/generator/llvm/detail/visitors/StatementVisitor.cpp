#include "generator/llvm/detail/visitors/StatementVisitor.hpp"

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

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

StatementVisitorResultType StatementVisitor::operator()(const asg::If& ifStatement)
{
    return process(*logger_, *context_, *llvm_, ifStatement);
}

StatementVisitorResultType StatementVisitor::operator()(const asg::For& forLoop)
{
    return process(*logger_, *context_, *llvm_, forLoop);
}

StatementVisitorResultType StatementVisitor::operator()(const asg::While& whileStatement)
{
    return process(*logger_, *context_, *llvm_, whileStatement);
}

StatementVisitorResultType StatementVisitor::operator()(const asg::Return& returnStatement)
{
    return process(*logger_, *context_, *llvm_, returnStatement);
}

StatementVisitorResultType StatementVisitor::operator()(const asg::Statblock& statblock)
{
    return process(*logger_, *context_, *llvm_, statblock);
}

StatementVisitorResultType StatementVisitor::operator()(const asg::Break& breakStatement)
{
    return process(*logger_, *context_, *llvm_, breakStatement);
}

StatementVisitorResultType StatementVisitor::operator()(const asg::Continue& continueStatement)
{
    return process(*logger_, *context_, *llvm_, continueStatement);
}

StatementVisitorResultType StatementVisitor::operator()(const asg::Dowhile& dowhile)
{
    return process(*logger_, *context_, *llvm_, dowhile);
}

StatementVisitorResultType StatementVisitor::operator()(const asg::Switch& switchStatement)
{
    return process(*logger_, *context_, *llvm_, switchStatement);
}

StatementVisitorResultType StatementVisitor::operator()(const asg::Expressionstat& expressionstat)
{
    return process(*logger_, *context_, *llvm_, expressionstat);
}

StatementVisitorResultType StatementVisitor::operator()(const asg::Try& tryStatement)
{
    return process(*logger_, *context_, *llvm_, tryStatement);
}


}}}}