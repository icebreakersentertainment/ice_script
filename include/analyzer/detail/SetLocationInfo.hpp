#ifndef ICE_SCRIPT_ANALYZER_SETLOCATIONINFO_HPP
#define ICE_SCRIPT_ANALYZER_SETLOCATIONINFO_HPP

namespace ice_script { namespace analyzer { namespace detail {

template <typename AsgLocationInfo, typename AstLocationInfo>
void setLocationInfo(AsgLocationInfo& asgNode, const AstLocationInfo& astNode)
{
    asgNode.line = astNode.line;
    asgNode.column = astNode.column;
    asgNode.length = astNode.length;
}

}}}

#endif //ICE_SCRIPT_ANALYZER_SETLOCATIONINFO_HPP
