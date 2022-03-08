#ifndef ICE_SCRIPT_ANALYZER_SYMBOL_HPP
#define ICE_SCRIPT_ANALYZER_SYMBOL_HPP

#include <string>
#include <memory>

#include "asg/Type.hpp"

namespace ice_script { namespace analyzer {

class Symbol
{
public:
    Symbol(const std::string& name) : name_(name)
    {}

    virtual ~Symbol() = default;

    const std::string& name() const
    {
        return name_;
    }

    std::shared_ptr<asg::Type> type()
    {
        return type_;
    }

    const std::shared_ptr<asg::Type>& type() const
    {
        return type_;
    }

    void setType(std::shared_ptr<asg::Type> type)
    {
        type_ = std::move(type);
    }

protected:
    std::string name_;
    std::shared_ptr<asg::Type> type_;

};

}}

#endif //ICE_SCRIPT_ANALYZER_SYMBOL_HPP
