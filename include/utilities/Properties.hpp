#ifndef PROPERTIES_H_
#define PROPERTIES_H_

#include <sstream>
#include <algorithm>
#include <string>
#include <unordered_map>

#include <fs/IFile.hpp>

namespace ice_script
{

namespace utilities
{

namespace
{
bool toBool(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    std::istringstream is(str);

    bool b;
    is >> std::boolalpha >> b;
    return b;
}
}

class Properties
{
public:
	Properties() = default;
	Properties(fs::IFile* file);
	Properties(const std::string& properties);
	~Properties() = default;
	
	std::string getStringValue(const std::string& name, std::string defaultValue = std::string()) const
	{
		const auto it = parameters_.find(name);

		if (it != parameters_.end()) return it->second;

		return std::move(defaultValue);
	}

	int32_t getIntValue(const std::string& name, const int32_t defaultValue = 0) const
	{
        const auto it = parameters_.find(name);

		if (it != parameters_.end()) return std::stoi(it->second);

		return defaultValue;
	}

	int64_t getLongValue(const std::string& name, const int64_t defaultValue = 0L) const
	{
        const auto it = parameters_.find(name);

		if (it != parameters_.end()) return std::stol(it->second);

		return defaultValue;
	}

    float_t getFloatValue(const std::string& name, const float_t defaultValue = 0.0f) const
	{
        const auto it = parameters_.find(name);

		if (it != parameters_.end()) return std::stof(it->second);

		return defaultValue;
	}

	double_t getDoubleValue(const std::string& name, const double_t defaultValue = 0.0) const
	{
        const auto it = parameters_.find(name);

		if (it != parameters_.end()) return std::stod(it->second);

		return defaultValue;
	}

	bool getBoolValue(const std::string& name, const bool defaultValue = false) const
	{
        const auto it = parameters_.find(name);

		if (it != parameters_.end()) return toBool(it->second);

		return defaultValue;
	}

private:
	std::unordered_map<std::string, std::string> parameters_;
};

}

}

#endif /* PROPERTIES_H_ */
