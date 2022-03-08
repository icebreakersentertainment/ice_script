#ifndef ICE_SCRIPT_GENERATOR_IMPORTVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_IMPORTVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

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

        ImportVisitorResultType operator()(const asg::Type& type);
    ImportVisitorResultType operator()(const asg::Identifier& identifier);
    ImportVisitorResultType operator()(const asg::Parameterlist& parameterlist);
    ImportVisitorResultType operator()(const asg::Functionattribute& functionattribute);
    ImportVisitorResultType operator()(const asg::String& string);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_IMPORTVISITOR_HPP
