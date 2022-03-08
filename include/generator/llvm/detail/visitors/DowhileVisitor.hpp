#ifndef ICE_SCRIPT_GENERATOR_DOWHILEVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_DOWHILEVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using DowhileVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class DowhileVisitor : public AbstractVisitor<DowhileVisitor, DowhileVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        DowhileVisitorResultType operator()(const asg::Statement& statement);
    DowhileVisitorResultType operator()(const asg::Assign& assign);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_DOWHILEVISITOR_HPP
