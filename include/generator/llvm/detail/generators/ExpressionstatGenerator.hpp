#ifndef ICE_SCRIPT_GENERATOR_EXPRESSIONSTATGENERATOR_HPP
#define ICE_SCRIPT_GENERATOR_EXPRESSIONSTATGENERATOR_HPP

#include "asg/Expressionstat.hpp"

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Expressionstat& expressionstat);

}}}}

#endif //ICE_SCRIPT_GENERATOR_EXPRESSIONSTATGENERATOR_HPP
