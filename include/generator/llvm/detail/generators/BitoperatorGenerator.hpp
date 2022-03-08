#ifndef ICE_SCRIPT_GENERATOR_BITOPERATORGENERATOR_HPP
#define ICE_SCRIPT_GENERATOR_BITOPERATORGENERATOR_HPP

#include "asg/Bitoperator.hpp"

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "generator/llvm/detail/BinaryOperatorFactory.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

BinaryOperatorFactory process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Bitoperator& bitoperator);

}}}}

#endif //ICE_SCRIPT_GENERATOR_BITOPERATORGENERATOR_HPP
