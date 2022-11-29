#ifndef ICE_SCRIPT_GENERATOR_GENERATETYPES_HPP
#define ICE_SCRIPT_GENERATOR_GENERATETYPES_HPP

#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

void generateTypes(Context& context, Llvm& llvm);

}}}}

#endif //ICE_SCRIPT_GENERATOR_GENERATETYPES_HPP
