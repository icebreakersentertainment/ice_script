#ifndef ICE_SCRIPT_GENERATOR_FUNCTIONATTRIBUTEGENERATOR_HPP
#define ICE_SCRIPT_GENERATOR_FUNCTIONATTRIBUTEGENERATOR_HPP

#include "asg/Functionattribute.hpp"

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Functionattribute& functionattribute);

}}}}

#endif //ICE_SCRIPT_GENERATOR_FUNCTIONATTRIBUTEGENERATOR_HPP
