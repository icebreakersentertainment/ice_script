#ifndef IFILE_H_
#define IFILE_H_

#include <string>
#include <iostream>

namespace ice_script
{
namespace fs
{

enum FileFlags : int32_t
{
	READ 	= 1 << 0,
	WRITE 	= 1 << 1,
	APPEND 	= 1 << 2,
	BINARY 	= 1 << 3
};

class IFile
{
public:
	virtual ~IFile() = default;

	virtual bool isOpen() const = 0;
	virtual uint64_t size() const = 0;
	virtual bool eof() const = 0;
	virtual std::string path() const = 0;
	virtual void close() = 0;

	virtual void write(const std::string& data) = 0;
	virtual std::string read(const uint32_t length = 256) = 0;
	virtual std::string readAll() = 0;
	
	virtual std::istream& getInputStream() = 0;
	virtual std::ostream& getOutputStream() = 0;
};

}
}

#endif /* IFILE_H_ */
