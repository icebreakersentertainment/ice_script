#ifndef ICE_SCRIPT_GENERATOR_TYPEMODIFIERGENERATOR_HPP
#define ICE_SCRIPT_GENERATOR_TYPEMODIFIERGENERATOR_HPP

#include "asg/Typemodifier.hpp"

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Typemodifier& typemodifier);

}}}}

#endif //ICE_SCRIPT_GENERATOR_TYPEMODIFIERGENERATOR_HPP
