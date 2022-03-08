#ifndef ICE_SCRIPT_ANALYZER_TYPETABLE_HPP
#define ICE_SCRIPT_ANALYZER_TYPETABLE_HPP

#include <string>
#include <memory>
#include <unordered_map>

#include "ast/PrimitiveType.hpp"

#include "asg/Type.hpp"
#include "asg/PrimitiveType.hpp"
#include "asg/UnknownType.hpp"

#include "analyzer/AnalyzerUtilities.hpp"

#include "exceptions/TypeNotFoundException.hpp"
#include "exceptions/DuplicateTypeException.hpp"

namespace ice_script { namespace analyzer {

class TypeTable
{
public:
    std::shared_ptr<asg::Type> find(const std::string& name)
    {
        const auto it = typeMap_.find(name);

        if (it != typeMap_.end())
        {
            return it->second;
        }

        return nullptr;
    }

    std::shared_ptr<asg::FunctionType> findFunction(const std::string& name)
    {
        const auto it = typeMap_.find(name);

        if (it != typeMap_.end())
        {
            return it->second;
        }

        return nullptr;
    }

    std::shared_ptr<asg::Type> get(const std::string& name)
    {
        auto type = find(name);

        if (!type) throw TypeNotFoundException();

        return type;
    }

    std::shared_ptr<asg::Type> get(const asg::Type::TypeId typeId)
    {
        const auto string = toString(typeId);

        auto type = find(string);

        if (!type) throw TypeNotFoundException();

        return type;
    }

    std::shared_ptr<asg::Type> get(const ast::PrimitiveType primitiveType)
    {
        const auto string = toString(primitiveType);

        auto type = find(string);

        if (!type) throw TypeNotFoundException();

        return type;
    }

    std::shared_ptr<asg::Type> create(const ast::PrimitiveType primitiveType)
    {
        const auto string = toString(primitiveType);

        auto type = find(string);

        if (type) throw DuplicateTypeException();

        typeMap_[string] = std::make_shared<asg::PrimitiveType>(primitiveType);

        return typeMap_[string];
    }

    void add(std::shared_ptr<asg::Type> type)
    {
//        const auto string = toString(primitiveType);

        auto _type = find(type->name());

        if (_type) throw DuplicateTypeException();

        typeMap_[type->name()] = type;
    }

    std::shared_ptr<asg::UnknownType> unknownType()
    {
        return unknownType_;
    }

private:
    std::unordered_map<std::string, std::shared_ptr<asg::Type>> typeMap_;

//    const static std::unique_ptr<asg::UnknownType> unknownType_ = std::make_unique<asg::UnknownType>();
    std::shared_ptr<asg::UnknownType> unknownType_ = std::make_shared<asg::UnknownType>();

};

}}

#endif //ICE_SCRIPT_ANALYZER_TYPETABLE_HPP
