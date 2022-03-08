#ifndef ICE_SCRIPT_FUNCTIONSYMBOL_HPP
#define ICE_SCRIPT_FUNCTIONSYMBOL_HPP

#include <string>
#include <memory>

#include "analyzer/Symbol.hpp"

namespace ice_script { namespace analyzer {

class FunctionSymbol : public Symbol
{
public:
    using Symbol::Symbol;

    std::shared_ptr<asg::FunctionType> type()
    {
        return type_;
    }

    const std::shared_ptr<asg::FunctionType>& type() const
    {
        return type_;
    }

    void setType(std::shared_ptr<asg::FunctionType> type)
    {
        type_ = std::move(type);
    }

protected:
    std::shared_ptr<asg::FunctionType> type_;

};

}}

#endif //ICE_SCRIPT_FUNCTIONSYMBOL_HPP
