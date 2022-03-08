#include "generator/llvm/detail/generators/NumberGenerator.hpp"

#include "generator/llvm/detail/visitors/NumberVisitor.hpp"

#include "asg/Type.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ::llvm;
using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Number& number)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(number).name())

    Scope& scope = context.scope();

    NumberVisitor numberVisitor{logger, context, llvm};

    return boost::get<::llvm::Value*>(boost::apply_visitor(numberVisitor, number.value));

//    return ConstantInt::get(IntegerType::getInt64Ty(llvm.context()), value);
}

}}}}