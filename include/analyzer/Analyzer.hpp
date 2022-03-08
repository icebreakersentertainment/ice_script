#ifndef ICE_SCRIPT_ANALYZER_ANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_ANALYZER_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer {

class Analyzer
{
public:
    Analyzer(logger::ILogger& logger) : logger_(&logger)
    {

    }

    asg::Asg parse(const ast::Ast& ast);

private:
    logger::ILogger* logger_;
};

}}

#endif //ICE_SCRIPT_ANALYZER_ANALYZER_HPP
