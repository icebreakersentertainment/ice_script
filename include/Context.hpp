#ifndef ICE_SCRIPT_CONTEXT_HPP
#define ICE_SCRIPT_CONTEXT_HPP

#include <memory>

#include "logger/ILogger.hpp"
#include "fs/IFileSystem.hpp"

namespace ice_script
{

class Context
{
public:
    logger::ILogger* logger()
    {
        return logger_.get();
    }
    
    void setLogger(std::shared_ptr<logger::ILogger> logger)
    {
        logger_ = std::move(logger);
    }
    
    fs::IFileSystem* fileSystem()
    {
        return fileSystem_.get();
    }

    void setFileSystem(std::shared_ptr<fs::IFileSystem> fileSystem)
    {
        fileSystem_ = std::move(fileSystem);
    }
    
private:
    std::shared_ptr<logger::ILogger> logger_;
    std::shared_ptr<fs::IFileSystem> fileSystem_;
};

}

#endif /* ICE_SCRIPT_CONTEXT_HPP */
