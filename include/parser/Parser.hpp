#ifndef ICE_SCRIPT_PARSER_HPP
#define ICE_SCRIPT_PARSER_HPP

#include <string>

//#include "parser/AstAll.hpp"

#include "ast/Ast.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace parser {

class Parser
{
public:
    Parser(logger::ILogger& logger) : logger_(&logger)
    {

    }

    ast::Ast parse(const std::string& script);

    ast::Ast parse(std::istream& inputStream, const std::string& script);

private:
    logger::ILogger* logger_;
};

}}

#endif //ICE_SCRIPT_PARSER_HPP
