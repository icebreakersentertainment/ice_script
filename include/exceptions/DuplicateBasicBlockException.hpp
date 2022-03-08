#ifndef ICE_SCRIPT_DUPLICATEBASICBLOCKEXCEPTION_HPP
#define ICE_SCRIPT_DUPLICATEBASICBLOCKEXCEPTION_HPP

#include "exceptions/Exception.hpp"

namespace ice_script
{

struct DuplicateBasicBlockException : virtual Exception
{
    using Exception::Exception;
};

}

#endif //ICE_SCRIPT_DUPLICATEBASICBLOCKEXCEPTION_HPP
