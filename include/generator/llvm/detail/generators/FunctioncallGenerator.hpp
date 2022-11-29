#ifndef ICE_SCRIPT_GENERATOR_FUNCTIONCALLGENERATOR_HPP
#define ICE_SCRIPT_GENERATOR_FUNCTIONCALLGENERATOR_HPP

#include "asg/Functioncall.hpp"

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Functioncall& functioncall);

}}}}

#endif //ICE_SCRIPT_GENERATOR_FUNCTIONCALLGENERATOR_HPP
