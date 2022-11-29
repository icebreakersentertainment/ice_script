#ifndef ICE_SCRIPT_GENERATOR_IMPORTVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_IMPORTVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/TypeGenerator.hpp"
#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/ParameterlistGenerator.hpp"
#include "generator/llvm/detail/generators/FunctionattributeGenerator.hpp"
#include "generator/llvm/detail/generators/StringGenerator.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using ImportVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class ImportVisitor : public AbstractVisitor<ImportVisitor, ImportVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    ImportVisitorResultType operator()(const Type& type)
    {
        return process(*context_, *llvm_, type);
    }

    ImportVisitorResultType operator()(const asg::Identifier& identifier)
    {
        return process(*context_, *llvm_, identifier);
    }

    ImportVisitorResultType operator()(const asg::Parameterlist& parameterlist)
    {
        return process(*context_, *llvm_, parameterlist);
    }

    ImportVisitorResultType operator()(const asg::Functionattribute& functionattribute)
    {
        return process(*context_, *llvm_, functionattribute);
    }

    ImportVisitorResultType operator()(const asg::String& string)
    {
        return process(*context_, *llvm_, string);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_IMPORTVISITOR_HPP
