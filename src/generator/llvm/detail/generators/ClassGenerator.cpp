#include "generator/llvm/detail/generators/ClassGenerator.hpp"

#include "generator/llvm/detail/generators/FunctionGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

class MyClass {};

void test() {}

void MyClass() {
    int test = 0;
}

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Class& classData)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(classData).name())

    Scope& scope = context.scope();
    
    // for (const auto& virtualproperatorerty : classData.virtualproperatorerties)
    // {
        
    // }
    
    for (const auto& function : classData.functions)
    {
        process(context, llvm, function.get());
    }

    // for (const auto& variable : classData.variables)
    // {
        
    // }

    // for (const auto& functiondefinition : classData.functiondefinitions)
    // {
        
    // }

    return nullptr;
}

}}}}