#ifndef ICE_SCRIPT_GENERATOR_MATHOPERATORGENERATOR_HPP
#define ICE_SCRIPT_GENERATOR_MATHOPERATORGENERATOR_HPP

#include "asg/Mathoperator.hpp"

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "generator/llvm/detail/BinaryOperatorFactory.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

BinaryOperatorFactory process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Mathoperator& mathoperator);

}}}}

#endif //ICE_SCRIPT_GENERATOR_MATHOPERATORGENERATOR_HPP
