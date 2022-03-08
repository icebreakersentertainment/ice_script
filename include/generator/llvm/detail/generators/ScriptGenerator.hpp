#ifndef ICE_SCRIPT_GENERATOR_SCRIPTGENERATOR_HPP
#define ICE_SCRIPT_GENERATOR_SCRIPTGENERATOR_HPP

#include "asg/Script.hpp"

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Script& script);

}}}}

#endif //ICE_SCRIPT_GENERATOR_SCRIPTGENERATOR_HPP
