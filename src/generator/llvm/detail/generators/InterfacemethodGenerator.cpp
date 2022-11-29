#include "generator/llvm/detail/generators/InterfacemethodGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Interfacemethod& interfacemethod)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(interfacemethod).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}