#ifndef ICE_SCRIPT_GENERATOR_CASEVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_CASEVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

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

        CaseVisitorResultType operator()(const asg::Expression& expression);
    CaseVisitorResultType operator()(const asg::Statement& statement);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_CASEVISITOR_HPP
