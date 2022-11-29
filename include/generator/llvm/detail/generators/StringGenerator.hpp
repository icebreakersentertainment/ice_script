#ifndef ICE_SCRIPT_GENERATOR_STRINGGENERATOR_HPP
#define ICE_SCRIPT_GENERATOR_STRINGGENERATOR_HPP

#include "asg/String.hpp"

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

::llvm::Value* process(Context& context, Llvm& llvm, const asg::String& string);

}}}}

#endif //ICE_SCRIPT_GENERATOR_STRINGGENERATOR_HPP
