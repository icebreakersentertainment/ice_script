#ifndef ICE_SCRIPT_GENERATOR_EXPRESSIONOPERATORERTYGENERATOR_HPP
#define ICE_SCRIPT_GENERATOR_EXPRESSIONOPERATORERTYGENERATOR_HPP

#include "asg/Expressionoperatorerty.hpp"

#include "generator/llvm/detail/visitors/ExpressionoperatorertyVisitor.hpp"

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

ExpressionoperatorertyVisitorResultType process(Context& context, Llvm& llvm, const asg::Expressionoperatorerty& expressionoperatorerty);

}}}}

#endif //ICE_SCRIPT_GENERATOR_EXPRESSIONOPERATORERTYGENERATOR_HPP
