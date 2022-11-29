#ifndef ICE_SCRIPT_ICESCRIPTENGINE_HPP
#define ICE_SCRIPT_ICESCRIPTENGINE_HPP

#include <memory>
#include <string>

// #include "Library.hpp"

// #include "Context.hpp"

#include "fs/FileSystem.hpp"
#include "logger/Logger.hpp"

namespace ice_script
{

class IceScriptEngine
{
public:
    IceScriptEngine() = default;

    // IceScriptEngine(Context context) : context_(std::move(context))
    // {

    // }

    IceScriptEngine(logger::ILogger& logger, fs::IFileSystem& fileSystem) : logger_(&logger), fileSystem_(&fileSystem)
    {

    }
    
    // Library& createLibrary()
    // {
    //     LOG_INFO(context_.logger(), "Creating library");
        
    //     auto library = std::make_shared<Library>(context_);
        
    //     libraries_.push_back(library);
        
    //     return *library;
    // }

    void execute(const std::string& script);

private:
    logger::ILogger* logger_;
    fs::IFileSystem* fileSystem_;
    // Context context_;
    // std::vector<std::shared_ptr<Library>> libraries_;
};

}

#endif //ICE_SCRIPT_ICESCRIPTENGINE_HPP
