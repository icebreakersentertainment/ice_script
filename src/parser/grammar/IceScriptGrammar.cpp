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

    start = qi::eps >> scriptRule_;

    on_error<rethrow>(start, handler(_1, _2, _3, _4));
    on_error<rethrow>(scriptRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(classRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(typedefRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(namespaceRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(funcRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(interfaceRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(varRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(importRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(enumRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(funcdefRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(virtpropRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(mixinRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(intfmthdRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(statblockRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(paramlistRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(typemodRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(typeRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(initlistRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(scopeRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(datatypeRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(primtypeRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(funcattrRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(statementRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(switchRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(breakRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(forRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(whileRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(dowhileRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(ifRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(continueRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(exprstatRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(tryRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(returnRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(caseRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(exprRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(exprtermRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(exprvalueRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(constructcallRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(exprpreopRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(exprpostopRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(castRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(lambdaRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(literalRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(funccallRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(varaccessRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(arglistRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(assignRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(conditionRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(expropRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(bitopRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(mathopRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(compopRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(logicopRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(assignopRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(identifierRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(numberRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(stringRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(bitsRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(boolRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(nullRule_, handler(_1, _2, _3, _4));
    on_error<rethrow>(voidRule_, handler(_1, _2, _3, _4));

    auto set_location_info = annotate(_val, _1, _3);
    on_success(start, set_location_info);
    on_success(scriptRule_, set_location_info);
    on_success(classRule_, set_location_info);
    on_success(typedefRule_, set_location_info);
    on_success(namespaceRule_, set_location_info);
    on_success(funcRule_, set_location_info);
    on_success(interfaceRule_, set_location_info);
    on_success(varRule_, set_location_info);
    on_success(importRule_, set_location_info);
    on_success(enumRule_, set_location_info);
    on_success(funcdefRule_, set_location_info);
    on_success(virtpropRule_, set_location_info);
    on_success(mixinRule_, set_location_info);
    on_success(intfmthdRule_, set_location_info);
    on_success(statblockRule_, set_location_info);
    on_success(paramlistRule_, set_location_info);
    on_success(typemodRule_, set_location_info);
    on_success(typeRule_, set_location_info);
    on_success(initlistRule_, set_location_info);
    on_success(scopeRule_, set_location_info);
    on_success(datatypeRule_, set_location_info);
    on_success(primtypeRule_, set_location_info);
    on_success(funcattrRule_, set_location_info);
    on_success(statementRule_, set_location_info);
    on_success(switchRule_, set_location_info);
    on_success(breakRule_, set_location_info);
    on_success(forRule_, set_location_info);
    on_success(whileRule_, set_location_info);
    on_success(dowhileRule_, set_location_info);
    on_success(ifRule_, set_location_info);
    on_success(continueRule_, set_location_info);
    on_success(exprstatRule_, set_location_info);
    on_success(tryRule_, set_location_info);
    on_success(returnRule_, set_location_info);
    on_success(caseRule_, set_location_info);
    on_success(exprRule_, set_location_info);
    on_success(exprtermRule_, set_location_info);
    on_success(exprvalueRule_, set_location_info);
    on_success(constructcallRule_, set_location_info);
    on_success(exprpreopRule_, set_location_info);
    on_success(exprpostopRule_, set_location_info);
    on_success(castRule_, set_location_info);
    on_success(lambdaRule_, set_location_info);
    on_success(literalRule_, set_location_info);
    on_success(funccallRule_, set_location_info);
    on_success(varaccessRule_, set_location_info);
    on_success(arglistRule_, set_location_info);
    on_success(assignRule_, set_location_info);
    on_success(conditionRule_, set_location_info);
    on_success(expropRule_, set_location_info);
    on_success(bitopRule_, set_location_info);
    on_success(mathopRule_, set_location_info);
    on_success(compopRule_, set_location_info);
    on_success(logicopRule_, set_location_info);
    on_success(assignopRule_, set_location_info);
    on_success(identifierRule_, set_location_info);
    on_success(numberRule_, set_location_info);
    on_success(stringRule_, set_location_info);
    on_success(bitsRule_, set_location_info);
    on_success(boolRule_, set_location_info);
    on_success(nullRule_, set_location_info);
    on_success(voidRule_, set_location_info);

    BOOST_SPIRIT_DEBUG_NODES(
            (start)
            (scriptRule_)
            (classRule_)
            (typedefRule_)
            (namespaceRule_)
            (funcRule_)
            (interfaceRule_)
            (varRule_)
            (importRule_)
            (enumRule_)
            (funcdefRule_)
            (virtpropRule_)
            (mixinRule_)
            (intfmthdRule_)
            (statblockRule_)
            (paramlistRule_)
            (typemodRule_)
            (typeRule_)
            (initlistRule_)
            (scopeRule_)
            (datatypeRule_)
            (primtypeRule_)
            (funcattrRule_)
            (statementRule_)
            (switchRule_)
            (breakRule_)
            (forRule_)
            (whileRule_)
            (dowhileRule_)
            (ifRule_)
            (continueRule_)
            (exprstatRule_)
            (tryRule_)
            (returnRule_)
            (caseRule_)
            (exprRule_)
            (exprtermRule_)
            (exprvalueRule_)
            (constructcallRule_)
            (exprpreopRule_)
            (exprpostopRule_)
            (castRule_)
            (lambdaRule_)
            (literalRule_)
            (funccallRule_)
            (varaccessRule_)
            (arglistRule_)
            (assignRule_)
            (conditionRule_)
            (expropRule_)
            (bitopRule_)
            (mathopRule_)
            (compopRule_)
            (logicopRule_)
            (assignopRule_)
            (identifierRule_)
            (numberRule_)
            (stringRule_)
            (bitsRule_)
            (boolRule_)
            (nullRule_)
            (voidRule_)
    )
}

}}}