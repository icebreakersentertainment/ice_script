#ifndef ICE_SCRIPT_GENERATOR_LOGICOPERATORGENERATOR_HPP
#define ICE_SCRIPT_GENERATOR_LOGICOPERATORGENERATOR_HPP

#include "asg/Logicoperator.hpp"

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "generator/llvm/detail/BinaryOperatorFactory.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

BinaryOperatorFactory process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Logicoperator& logicoperator);

}}}}

#endif //ICE_SCRIPT_GENERATOR_LOGICOPERATORGENERATOR_HPP
