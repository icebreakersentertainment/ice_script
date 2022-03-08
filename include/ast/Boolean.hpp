#ifndef ICE_SCRIPT_BOOLEAN_HPP
#define ICE_SCRIPT_BOOLEAN_HPP

namespace ice_script { namespace ast {

struct Boolean
{
    Boolean() : value(false) {}
    explicit Boolean(bool value) : value(value) {}

    bool value;
};

}}

#endif //ICE_SCRIPT_BOOLEAN_HPP
