#ifndef ICE_SCRIPT_GENERATOR_TYPEDEFINITIONGENERATOR_HPP
#define ICE_SCRIPT_GENERATOR_TYPEDEFINITIONGENERATOR_HPP

#include "asg/Typedefinition.hpp"

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Typedefinition& typedefinition);

}}}}

#endif //ICE_SCRIPT_GENERATOR_TYPEDEFINITIONGENERATOR_HPP
