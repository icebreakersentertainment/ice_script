#ifndef ICE_SCRIPT_LOCATIONINFO_HPP
#define ICE_SCRIPT_LOCATIONINFO_HPP

namespace ice_script { namespace ast {

struct LocationInfo
{
    uint32_t line;
    uint32_t column;
    uint32_t length;
};

}}

#endif //ICE_SCRIPT_LOCATIONINFO_HPP
