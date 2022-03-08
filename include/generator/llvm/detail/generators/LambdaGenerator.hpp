#ifndef ICE_SCRIPT_GENERATOR_LAMBDAGENERATOR_HPP
#define ICE_SCRIPT_GENERATOR_LAMBDAGENERATOR_HPP

#include "asg/Lambda.hpp"

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Lambda& lambda);

}}}}

#endif //ICE_SCRIPT_GENERATOR_LAMBDAGENERATOR_HPP
