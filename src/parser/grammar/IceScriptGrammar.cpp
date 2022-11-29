#include "parser/grammar/IceScriptGrammar.hpp"

namespace ice_script { namespace parser { namespace grammar {

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

using namespace ice_script::parser::rules;
using namespace ice_script::ast;

IceScriptGrammar::IceScriptGrammar(PositionIteratorType it) : IceScriptGrammar::base_type(start), annotate(it)
{
    using namespace boost::spirit;
    using namespace boost::spirit::qi;
    using qi::int_;
    using qi::lit;
    using qi::double_;
    using qi::lexeme;
    using ascii::char_;
    using ascii::space;
    using ascii::space_type;

    start = qi::eps >> ice_script::parser::rules::scriptRule;

    on_error<rethrow>(start, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::scriptRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::classRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::typedefRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::namespaceRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::funcRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::interfaceRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::varRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::importRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::enumRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::funcdefRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::virtpropRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::mixinRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::intfmthdRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::statblockRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::paramlistRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::typemodRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::typeRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::initlistRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::scopeRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::datatypeRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::primtypeRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::funcattrRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::statementRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::switchRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::breakRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::forRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::whileRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::dowhileRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::ifRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::continueRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::exprstatRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::tryRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::returnRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::caseRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::exprRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::exprtermRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::exprvalueRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::constructcallRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::exprpreopRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::exprpostopRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::castRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::lambdaRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::literalRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::funccallRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::varaccessRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::arglistRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::assignRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::conditionRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::expropRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::bitopRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::mathopRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::compopRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::logicopRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::assignopRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::identifierRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::numberRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::stringRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::bitsRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::boolRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::nullRule, handler(_1, _2, _3, _4));
    on_error<rethrow>(ice_script::parser::rules::voidRule, handler(_1, _2, _3, _4));

    auto set_location_info = annotate(_val, _1, _3);
    on_success(start, set_location_info);
    on_success(ice_script::parser::rules::scriptRule, set_location_info);
    on_success(ice_script::parser::rules::classRule, set_location_info);
    on_success(ice_script::parser::rules::typedefRule, set_location_info);
    on_success(ice_script::parser::rules::namespaceRule, set_location_info);
    on_success(ice_script::parser::rules::funcRule, set_location_info);
    on_success(ice_script::parser::rules::interfaceRule, set_location_info);
    on_success(ice_script::parser::rules::varRule, set_location_info);
    on_success(ice_script::parser::rules::importRule, set_location_info);
    on_success(ice_script::parser::rules::enumRule, set_location_info);
    on_success(ice_script::parser::rules::funcdefRule, set_location_info);
    on_success(ice_script::parser::rules::virtpropRule, set_location_info);
    on_success(ice_script::parser::rules::mixinRule, set_location_info);
    on_success(ice_script::parser::rules::intfmthdRule, set_location_info);
    on_success(ice_script::parser::rules::statblockRule, set_location_info);
    on_success(ice_script::parser::rules::paramlistRule, set_location_info);
    on_success(ice_script::parser::rules::typemodRule, set_location_info);
    on_success(ice_script::parser::rules::typeRule, set_location_info);
    on_success(ice_script::parser::rules::initlistRule, set_location_info);
    on_success(ice_script::parser::rules::scopeRule, set_location_info);
    on_success(ice_script::parser::rules::datatypeRule, set_location_info);
    on_success(ice_script::parser::rules::primtypeRule, set_location_info);
    on_success(ice_script::parser::rules::funcattrRule, set_location_info);
    on_success(ice_script::parser::rules::statementRule, set_location_info);
    on_success(ice_script::parser::rules::switchRule, set_location_info);
    on_success(ice_script::parser::rules::breakRule, set_location_info);
    on_success(ice_script::parser::rules::forRule, set_location_info);
    on_success(ice_script::parser::rules::whileRule, set_location_info);
    on_success(ice_script::parser::rules::dowhileRule, set_location_info);
    on_success(ice_script::parser::rules::ifRule, set_location_info);
    on_success(ice_script::parser::rules::continueRule, set_location_info);
    on_success(ice_script::parser::rules::exprstatRule, set_location_info);
    on_success(ice_script::parser::rules::tryRule, set_location_info);
    on_success(ice_script::parser::rules::returnRule, set_location_info);
    on_success(ice_script::parser::rules::caseRule, set_location_info);
    on_success(ice_script::parser::rules::exprRule, set_location_info);
    on_success(ice_script::parser::rules::exprtermRule, set_location_info);
    on_success(ice_script::parser::rules::exprvalueRule, set_location_info);
    on_success(ice_script::parser::rules::constructcallRule, set_location_info);
    on_success(ice_script::parser::rules::exprpreopRule, set_location_info);
    on_success(ice_script::parser::rules::exprpostopRule, set_location_info);
    on_success(ice_script::parser::rules::castRule, set_location_info);
    on_success(ice_script::parser::rules::lambdaRule, set_location_info);
    on_success(ice_script::parser::rules::literalRule, set_location_info);
    on_success(ice_script::parser::rules::funccallRule, set_location_info);
    on_success(ice_script::parser::rules::varaccessRule, set_location_info);
    on_success(ice_script::parser::rules::arglistRule, set_location_info);
    on_success(ice_script::parser::rules::assignRule, set_location_info);
    on_success(ice_script::parser::rules::conditionRule, set_location_info);
    on_success(ice_script::parser::rules::expropRule, set_location_info);
    on_success(ice_script::parser::rules::bitopRule, set_location_info);
    on_success(ice_script::parser::rules::mathopRule, set_location_info);
    on_success(ice_script::parser::rules::compopRule, set_location_info);
    on_success(ice_script::parser::rules::logicopRule, set_location_info);
    on_success(ice_script::parser::rules::assignopRule, set_location_info);
    on_success(ice_script::parser::rules::identifierRule, set_location_info);
    on_success(ice_script::parser::rules::numberRule, set_location_info);
    on_success(ice_script::parser::rules::stringRule, set_location_info);
    on_success(ice_script::parser::rules::bitsRule, set_location_info);
    on_success(ice_script::parser::rules::boolRule, set_location_info);
    on_success(ice_script::parser::rules::nullRule, set_location_info);
    on_success(ice_script::parser::rules::voidRule, set_location_info);

    BOOST_SPIRIT_DEBUG_NODES(
            (start)
            (ice_script::parser::rules::scriptRule)
            (ice_script::parser::rules::classRule)
            (ice_script::parser::rules::typedefRule)
            (ice_script::parser::rules::namespaceRule)
            (ice_script::parser::rules::funcRule)
            (ice_script::parser::rules::interfaceRule)
            (ice_script::parser::rules::varRule)
            (ice_script::parser::rules::importRule)
            (ice_script::parser::rules::enumRule)
            (ice_script::parser::rules::funcdefRule)
            (ice_script::parser::rules::virtpropRule)
            (ice_script::parser::rules::mixinRule)
            (ice_script::parser::rules::intfmthdRule)
            (ice_script::parser::rules::statblockRule)
            (ice_script::parser::rules::paramlistRule)
            (ice_script::parser::rules::typemodRule)
            (ice_script::parser::rules::typeRule)
            (ice_script::parser::rules::initlistRule)
            (ice_script::parser::rules::scopeRule)
            (ice_script::parser::rules::datatypeRule)
            (ice_script::parser::rules::primtypeRule)
            (ice_script::parser::rules::funcattrRule)
            (ice_script::parser::rules::statementRule)
            (ice_script::parser::rules::switchRule)
            (ice_script::parser::rules::breakRule)
            (ice_script::parser::rules::forRule)
            (ice_script::parser::rules::whileRule)
            (ice_script::parser::rules::dowhileRule)
            (ice_script::parser::rules::ifRule)
            (ice_script::parser::rules::continueRule)
            (ice_script::parser::rules::exprstatRule)
            (ice_script::parser::rules::tryRule)
            (ice_script::parser::rules::returnRule)
            (ice_script::parser::rules::caseRule)
            (ice_script::parser::rules::exprRule)
            (ice_script::parser::rules::exprtermRule)
            (ice_script::parser::rules::exprvalueRule)
            (ice_script::parser::rules::constructcallRule)
            (ice_script::parser::rules::exprpreopRule)
            (ice_script::parser::rules::exprpostopRule)
            (ice_script::parser::rules::castRule)
            (ice_script::parser::rules::lambdaRule)
            (ice_script::parser::rules::literalRule)
            (ice_script::parser::rules::funccallRule)
            (ice_script::parser::rules::varaccessRule)
            (ice_script::parser::rules::arglistRule)
            (ice_script::parser::rules::assignRule)
            (ice_script::parser::rules::conditionRule)
            (ice_script::parser::rules::expropRule)
            (ice_script::parser::rules::bitopRule)
            (ice_script::parser::rules::mathopRule)
            (ice_script::parser::rules::compopRule)
            (ice_script::parser::rules::logicopRule)
            (ice_script::parser::rules::assignopRule)
            (ice_script::parser::rules::identifierRule)
            (ice_script::parser::rules::numberRule)
            (ice_script::parser::rules::stringRule)
            (ice_script::parser::rules::bitsRule)
            (ice_script::parser::rules::boolRule)
            (ice_script::parser::rules::nullRule)
            (ice_script::parser::rules::voidRule)
    )
}

}}}