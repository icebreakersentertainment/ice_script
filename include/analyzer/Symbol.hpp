#ifndef ICE_SCRIPT_ANALYZER_SYMBOL_HPP
#define ICE_SCRIPT_ANALYZER_SYMBOL_HPP

#include <string>
#include <memory>

#include "asg/Type.hpp"

#include "detail/ToStringUtils.hpp"

namespace ice_script { namespace analyzer {

class Symbol
{
public:
    Symbol()
    {}

    Symbol(const std::string& name) : name_(name)
    {}

    virtual ~Symbol() = default;

    friend std::ostream& operator<<(std::ostream& os, const Symbol& symbol)
    {
        os << "(" << boost::typeindex::type_id<Symbol>().pretty_name() << ")["
        << "name: " << symbol.name_
        << ", type: " << symbol.type_
        << "]";

        return os;
    }

    friend std::string toString(const Symbol& symbol)
    {
        using namespace std::string_literals;

        return "(Symbol)[\n"s
            + "\tname: "s + symbol.name_
            + ",\n\ttype: " + detail::toString(symbol.type_)
            + "\n]";
    }

    const std::string& name() const
    {
        return name_;
    }

    void setName(std::string name)
    {
        name_ = std::move(name);
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
