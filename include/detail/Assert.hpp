#ifndef ICEENGINEASSERT_H_
#define ICEENGINEASSERT_H_

#include <iostream>

namespace ice_script
{
namespace detail
{

#define ICE_SCRIPT_ASSERT(condition) if (!(condition)) \
{ \
	std::cerr << __FILE__ << " (" << __LINE__ << "): Assert " << #condition << " failed" << std::endl; \
	std::abort(); \
	\
}

}
}

#endif /* ICEENGINEASSERT_H_ */
