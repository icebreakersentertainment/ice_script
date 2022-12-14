#include "generator/llvm/detail/generators/NamespaceGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Namespace& namespaceDefinition)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(namespaceDefinition).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}