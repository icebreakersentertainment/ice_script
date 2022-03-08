#include "analyzer/detail/visitors/ExpropNodeVisitor.hpp"

#include "analyzer/detail/analyzers/MathopNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/CompopNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/LogicopNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/BitopNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

ExpropNodeVisitorResultType ExpropNodeVisitor::operator()(const ast::MathopNode& node)
{
    return process(*logger_, *context_, node);
}

ExpropNodeVisitorResultType ExpropNodeVisitor::operator()(const ast::CompopNode& node)
{
    return process(*logger_, *context_, node);
}

ExpropNodeVisitorResultType ExpropNodeVisitor::operator()(const ast::LogicopNode& node)
{
    return process(*logger_, *context_, node);
}

ExpropNodeVisitorResultType ExpropNodeVisitor::operator()(const ast::BitopNode& node)
{
    return process(*logger_, *context_, node);
}


}}}