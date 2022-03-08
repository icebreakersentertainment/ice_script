#ifndef ICE_SCRIPT_GENERATOR_EXPRESSIONTERMGENERATOR_HPP
#define ICE_SCRIPT_GENERATOR_EXPRESSIONTERMGENERATOR_HPP

#include "asg/Expressionterm.hpp"

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Expressionterm& expressionterm);
::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::VectorExprpreopExprvalueVectorExprpreopType& vectorExprpreopExprvalueVectorExprpreop);

}}}}

#endif //ICE_SCRIPT_GENERATOR_EXPRESSIONTERMGENERATOR_HPP
