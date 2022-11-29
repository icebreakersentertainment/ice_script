#ifndef ICE_SCRIPT_GENERATOR_COMPARISONOPERATORGENERATOR_HPP
#define ICE_SCRIPT_GENERATOR_COMPARISONOPERATORGENERATOR_HPP

#include "asg/Comparisonoperator.hpp"

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "generator/llvm/detail/BinaryOperatorFactory.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

BinaryOperatorFactory process(Context& context, Llvm& llvm, const asg::Comparisonoperator& comparisonoperator);

}}}}

#endif //ICE_SCRIPT_GENERATOR_COMPARISONOPERATORGENERATOR_HPP
