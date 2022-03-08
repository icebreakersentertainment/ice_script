#ifndef ICE_SCRIPT_GENERATOR_EXPRESSIONPREOPERATORGENERATOR_HPP
#define ICE_SCRIPT_GENERATOR_EXPRESSIONPREOPERATORGENERATOR_HPP

#include "asg/Expressionpreoperator.hpp"

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Expressionpreoperator& expressionpreoperator);

}}}}

#endif //ICE_SCRIPT_GENERATOR_EXPRESSIONPREOPERATORGENERATOR_HPP
