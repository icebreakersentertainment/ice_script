#ifndef ICE_SCRIPT_GENERATOR_CASEGENERATOR_HPP
#define ICE_SCRIPT_GENERATOR_CASEGENERATOR_HPP

#include "asg/Case.hpp"

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Case& caseStatement);

}}}}

#endif //ICE_SCRIPT_GENERATOR_CASEGENERATOR_HPP
