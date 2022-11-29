#ifndef ICE_SCRIPT_GENERATOR_DATATYPEVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_DATATYPEVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/PrimativetypeGenerator.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using DatatypeVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class DatatypeVisitor : public AbstractVisitor<DatatypeVisitor, DatatypeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    DatatypeVisitorResultType operator()(const asg::Identifier& identifier)
    {
        return process(*context_, *llvm_, identifier);
    }

    DatatypeVisitorResultType operator()(const asg::Primativetype& primativetype)
    {
        return process(*context_, *llvm_, primativetype);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_DATATYPEVISITOR_HPP
