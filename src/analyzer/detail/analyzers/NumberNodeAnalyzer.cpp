#include <boost/lexical_cast.hpp>

#include "analyzer/detail/analyzers/NumberNodeAnalyzer.hpp"

#include "type/Type.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

namespace
{

size_t getSize(Context& context, const std::string& value)
{
    const bool isNegative = !value.empty() && value[0] == '-';

    std::string integerValueAsString{};
    std::copy_if(value.begin(), value.end(), std::back_inserter(integerValueAsString), [](const auto c) { return std::isdigit(c); });

    size_t size = 0;

    if (isNegative)
    {
        const int64_t integer = boost::lexical_cast<int64_t>(integerValueAsString);

        if (integer >= std::numeric_limits<int8_t>::min() && integer <= std::numeric_limits<int8_t>::max()) return 8;
        if (integer >= std::numeric_limits<int16_t>::min() && integer <= std::numeric_limits<int16_t>::max()) return 16;
        if (integer >= std::numeric_limits<int32_t>::min() && integer <= std::numeric_limits<int32_t>::max()) return 32;

        return 64;
    }

    const uint64_t integer = boost::lexical_cast<uint64_t>(integerValueAsString);

    if (integer <= std::numeric_limits<uint8_t>::max()) return 8;
    if (integer <= std::numeric_limits<uint16_t>::max()) return 16;
    if (integer <= std::numeric_limits<uint32_t>::max()) return 32;

    return 64;
}

std::shared_ptr<Type> getType(Context& context, const std::string& value)
{
    const bool isNegative = !value.empty() && value[0] == '-';

    const auto indexOfDecimal = value.find_first_of('.');
    const bool hasDecimal = indexOfDecimal != std::string::npos;

    const auto indexOfF = hasDecimal ? value.find_first_of('f', indexOfDecimal) : std::string::npos;
    const bool hasF = indexOfF != std::string::npos;

//    for (const auto& character : value)
//    {
//        if (character == '.') hasDecimal = true;
//        if (character == 'f') hasF = true;
//
////        if (std::isdigit(character) || character == '-' || character == '+')
////        {
////            continue;
////        }
//    }

    if (hasDecimal)
    {
        if (hasF) return context.typeTable().get(Type::TypeId::FLOAT)[0];

        return context.typeTable().get(Type::TypeId::DOUBLE)[0];
    }

    const size_t size = getSize(context, value);

    switch (size)
    {
        case 8:
            if (isNegative) return context.typeTable().get(Type::TypeId::INTEGER8)[0];

            return context.typeTable().get(Type::TypeId::UINTEGER8)[0];

        case 16:
            if (isNegative) return context.typeTable().get(Type::TypeId::INTEGER16)[0];

            return context.typeTable().get(Type::TypeId::UINTEGER16)[0];

        case 32:
            if (isNegative) return context.typeTable().get(Type::TypeId::INTEGER32)[0];

            return context.typeTable().get(Type::TypeId::UINTEGER32)[0];

        case 64:
            if (isNegative) return context.typeTable().get(Type::TypeId::INTEGER64)[0];

            return context.typeTable().get(Type::TypeId::UINTEGER64)[0];

        default:
            throw RuntimeException("");
    }
}

NumberType getValue(Context& context, const std::string& value)
{
    std::shared_ptr<Type> type = getType(context, value);

    switch (type->typeId())
    {
        case Type::TypeId::INTEGER8:
        {
            Integer8 integer8{};
            integer8.type = type;
//            integer8.value = boost::lexical_cast<int8_t>(value);
            integer8.value = static_cast<int8_t>(boost::lexical_cast<int32_t>(value));

            return integer8;
        }

        case Type::TypeId::INTEGER16:
        {
            Integer16 integer16{};
            integer16.type = type;
            integer16.value = boost::lexical_cast<int16_t>(value);

            return integer16;
        }

        case Type::TypeId::INTEGER32:
        case Type::TypeId::INTEGER:
        {
            Integer32 integer32{};
            integer32.type = type;
            integer32.value = boost::lexical_cast<int32_t>(value);

            return integer32;
        }

        case Type::TypeId::INTEGER64:
        {
            Integer64 integer64{};
            integer64.type = type;
            integer64.value = boost::lexical_cast<int64_t>(value);

            return integer64;
        }

        case Type::TypeId::UINTEGER8:
        {
            UInteger8 uinteger8{};
            uinteger8.type = type;
//            uinteger8.value = boost::lexical_cast<uint8_t>(value);
            uinteger8.value = static_cast<uint8_t>(boost::lexical_cast<uint32_t>(value));

            return uinteger8;
        }

        case Type::TypeId::UINTEGER16:
        {
            UInteger16 uinteger16{};
            uinteger16.type = type;
            uinteger16.value = boost::lexical_cast<uint16_t>(value);

            return uinteger16;
        }

        case Type::TypeId::UINTEGER32:
        case Type::TypeId::UINTEGER:
        {
            UInteger32 uinteger32{};
            uinteger32.type = type;
            uinteger32.value = boost::lexical_cast<uint32_t>(value);

            return uinteger32;
        }

        case Type::TypeId::UINTEGER64:
        {
            UInteger64 uinteger64{};
            uinteger64.type = type;
            uinteger64.value = boost::lexical_cast<uint64_t>(value);

            return uinteger64;
        }

        case Type::TypeId::FLOAT:
        {
            Float floatValue{};
            floatValue.type = type;
            floatValue.value = boost::lexical_cast<float>(value);

            return floatValue;
        }

        case Type::TypeId::DOUBLE:
        {
            Double doubleValue{};
            doubleValue.type = type;
            doubleValue.value = boost::lexical_cast<double>(value);

            return doubleValue;
        }

        default:
            throw RuntimeException("");
    }
}

}

asg::Number process(Context& context, const ast::NumberNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Number number{};

//    number.type = getType(context, node.value);
    number.value = getValue(context, node.value);

    return number;
}

}}}