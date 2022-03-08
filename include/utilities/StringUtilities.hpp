#ifndef STRINGUTILITIES_H_
#define STRINGUTILITIES_H_

#include <string>
#include <sstream>

namespace ice_script
{
namespace utilities
{

inline std::string toString(const std::wstring& ws)
{
	return std::string( ws.begin(), ws.end() );
}

inline std::wstring toWstring(const std::string& s)
{
	return std::wstring( s.begin(), s.end() );
}

// Taken from https://stackoverflow.com/a/12967014/780281
template <class OutIt>
inline void explode(const std::string& input, const char sep, OutIt output)
{
    std::istringstream buffer(input);

    std::string temp;

    while (std::getline(buffer, temp, sep))
    {
        *output++ = temp;
	}
}

inline std::vector<std::string> explode(const std::string& input, const char sep)
{
    std::vector<std::string> result;

    explode(input, sep, std::back_inserter(result));

    return result;
}

}
}

#endif /* STRINGUTILITIES_H_ */
