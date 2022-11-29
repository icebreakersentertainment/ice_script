#ifndef ICE_SCRIPT_GENERATOR_INTERFACEMETHODGENERATOR_HPP
#define ICE_SCRIPT_GENERATOR_INTERFACEMETHODGENERATOR_HPP

#include "asg/Interfacemethod.hpp"

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Interfacemethod& interfacemethod);

}}}}

#endif //ICE_SCRIPT_GENERATOR_INTERFACEMETHODGENERATOR_HPP
