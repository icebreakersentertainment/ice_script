#ifndef ICE_SCRIPT_LLVMORCJIT_HPP
#define ICE_SCRIPT_LLVMORCJIT_HPP

#include <string>

#include "logger/ILogger.hpp"
#include "fs/IFileSystem.hpp"

namespace ice_script { namespace engine { namespace llvm {

class LlvmOrcJit
{
public:
    LlvmOrcJit(logger::ILogger& logger, fs::IFileSystem& fileSystem) : logger_(&logger), fileSystem_(&fileSystem)
    {

    }

    void execute(const std::string& symbolName);

private:
    logger::ILogger* logger_;
    fs::IFileSystem* fileSystem_;
};

}}}

#endif //ICE_SCRIPT_LLVMORCJIT_HPP
