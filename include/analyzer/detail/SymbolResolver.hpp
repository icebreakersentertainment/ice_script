#ifndef ICE_SCRIPT_ANALYZER_DETAIL_SYMBOLRESOLVER_HPP
#define ICE_SCRIPT_ANALYZER_DETAIL_SYMBOLRESOLVER_HPP

#include "analyzer/detail/SymbolResolverVisitor.hpp"

#include "symbol/Symbol.hpp"

#include "asg/Expressionvalue.hpp"
#include "asg/Expressionpostoperator.hpp"

#include "analyzer/detail/Context.hpp"

namespace ice_script { namespace analyzer { namespace detail {

std::shared_ptr<Symbol> resolveSymbol(Context& context, const asg::Expressionvalue& expressionvalue)
{
    return boost::apply_visitor(SymbolResolverVisitor(context), expressionvalue.value);
}

}}}

#endif /* ICE_SCRIPT_ANALYZER_DETAIL_SYMBOLRESOLVER_HPP */
