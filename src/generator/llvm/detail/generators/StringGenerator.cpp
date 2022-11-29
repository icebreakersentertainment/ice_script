#include "generator/llvm/detail/generators/StringGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::String& string)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(string).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}