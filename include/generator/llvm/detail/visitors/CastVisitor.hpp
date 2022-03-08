#ifndef ICE_SCRIPT_GENERATOR_CASTVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_CASTVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using CastVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class CastVisitor : public AbstractVisitor<CastVisitor, CastVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        CastVisitorResultType operator()(const asg::Type& type);
    CastVisitorResultType operator()(const asg::Assign& assign);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_CASTVISITOR_HPP
