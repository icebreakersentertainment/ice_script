#ifndef ICE_SCRIPT_GENERATOR_STATBLOCKGENERATOR_HPP
#define ICE_SCRIPT_GENERATOR_STATBLOCKGENERATOR_HPP

#include "asg/Statblock.hpp"

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Statblock& statblock);

}}}}

#endif //ICE_SCRIPT_GENERATOR_STATBLOCKGENERATOR_HPP
