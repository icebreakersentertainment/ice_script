#ifndef ICE_SCRIPT_IGENERATOR_HPP
#define ICE_SCRIPT_IGENERATOR_HPP

#include <string>

#include "asg/Asg.hpp"

namespace ice_script { namespace generator {

class IGenerator
{
public:
    virtual ~IGenerator() = default;

    virtual std::string generate(const asg::Asg& asg) = 0;
};

}}

#endif //ICE_SCRIPT_IGENERATOR_HPP
