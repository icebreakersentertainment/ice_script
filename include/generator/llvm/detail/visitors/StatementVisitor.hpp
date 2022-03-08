#ifndef ICE_SCRIPT_GENERATOR_STATEMENTVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_STATEMENTVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

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

        StatementVisitorResultType operator()(const asg::If& ifStatement);
    StatementVisitorResultType operator()(const asg::For& forLoop);
    StatementVisitorResultType operator()(const asg::While& whileStatement);
    StatementVisitorResultType operator()(const asg::Return& returnStatement);
    StatementVisitorResultType operator()(const asg::Statblock& statblock);
    StatementVisitorResultType operator()(const asg::Break& breakStatement);
    StatementVisitorResultType operator()(const asg::Continue& continueStatement);
    StatementVisitorResultType operator()(const asg::Dowhile& dowhile);
    StatementVisitorResultType operator()(const asg::Switch& switchStatement);
    StatementVisitorResultType operator()(const asg::Expressionstat& expressionstat);
    StatementVisitorResultType operator()(const asg::Try& tryStatement);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_STATEMENTVISITOR_HPP
