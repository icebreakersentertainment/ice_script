#ifndef ICE_SCRIPT_ASG_STATEMENT_HPP
#define ICE_SCRIPT_ASG_STATEMENT_HPP

#include <string>

#include "detail/monostate.hpp"

#include "asg/LocationInfo.hpp"

namespace ice_script { namespace asg {

struct If;
struct For;
struct While;
struct Return;
struct Statblock;
struct Break;
struct Continue;
struct Dowhile;
struct Switch;
struct Expressionstat;
struct Try;

using StatementType = boost::variant<
    monostate,
    boost::recursive_wrapper<If>,
    boost::recursive_wrapper<For>,
    boost::recursive_wrapper<While>,
    boost::recursive_wrapper<Return>,
    boost::recursive_wrapper<Statblock>,
    boost::recursive_wrapper<Break>,
    boost::recursive_wrapper<Continue>,
    boost::recursive_wrapper<Dowhile>,
    boost::recursive_wrapper<Switch>,
    boost::recursive_wrapper<Expressionstat>,
    boost::recursive_wrapper<Try>
>;

// STATEMENT     ::= (IF | FOR | WHILE | RETURN | STATBLOCK | BREAK | CONTINUE | DOWHILE | SWITCH | EXPRSTAT | TRY)
struct Statement : LocationInfo
{
    Statement() = default;
    
    Statement(StatementType value) : value(std::move(value))
    {}
    
    StatementType value;
};

}}

#include "asg/If.hpp"
#include "asg/For.hpp"
#include "asg/While.hpp"
#include "asg/Return.hpp"
#include "asg/Statblock.hpp"
#include "asg/Break.hpp"
#include "asg/Continue.hpp"
#include "asg/Dowhile.hpp"
#include "asg/Switch.hpp"
#include "asg/Expressionstat.hpp"
#include "asg/Try.hpp"

#endif //ICE_SCRIPT_ASG_STATEMENT_HPP