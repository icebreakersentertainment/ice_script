#ifndef ICE_SCRIPT_GENERATOR_IFGENERATOR_HPP
#define ICE_SCRIPT_GENERATOR_IFGENERATOR_HPP

#include "asg/If.hpp"

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::If& ifStatement);

}}}}

#endif //ICE_SCRIPT_GENERATOR_IFGENERATOR_HPP
