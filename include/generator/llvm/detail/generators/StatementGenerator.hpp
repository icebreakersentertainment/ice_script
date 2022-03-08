#ifndef ICE_SCRIPT_GENERATOR_STATEMENTGENERATOR_HPP
#define ICE_SCRIPT_GENERATOR_STATEMENTGENERATOR_HPP

#include "asg/Statement.hpp"

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Statement& statement);

}}}}

#endif //ICE_SCRIPT_GENERATOR_STATEMENTGENERATOR_HPP
