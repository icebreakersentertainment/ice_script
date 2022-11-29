#ifndef ICE_SCRIPT_LLVMIR_HPP
#define ICE_SCRIPT_LLVMIR_HPP

#include <string>

#include "generator/IGenerator.hpp"

#include "type/TypeTable.hpp"
#include "symbol/SymbolTable.hpp"

#include "asg/Asg.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm {

class LlvmIr : public IGenerator
{
public:
    const static int TAB_SIZE = 4;

    LlvmIr(logger::ILogger& logger);
//    ~LlvmIr() override = default;

    std::string generate(const TypeTable& typeTable, const SymbolTable& symbolTable, const asg::Asg& asg) override;

private:
    logger::ILogger* logger_;
};

}}}

#endif //ICE_SCRIPT_LLVMIR_HPP
