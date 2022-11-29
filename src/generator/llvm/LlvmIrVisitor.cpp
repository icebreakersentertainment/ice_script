#ifdef WIN32
#define NOMINMAX
#undef min
#undef max
#endif

#include <llvm/ADT/APFloat.h>
#include <llvm/ADT/STLExtras.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>

#include "generator/llvm/LlvmIrVisitor.hpp"
#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"
#include "generator/llvm/Scope.hpp"

#include "generator/llvm/detail/generators/ArglistGenerator.hpp"
#include "generator/llvm/detail/generators/AssignGenerator.hpp"
#include "generator/llvm/detail/generators/AssignoperatorGenerator.hpp"
#include "generator/llvm/detail/generators/BitoperatorGenerator.hpp"
#include "generator/llvm/detail/generators/BitsGenerator.hpp"
#include "generator/llvm/detail/generators/BreakGenerator.hpp"
#include "generator/llvm/detail/generators/CaseGenerator.hpp"
#include "generator/llvm/detail/generators/CastGenerator.hpp"
#include "generator/llvm/detail/generators/ClassGenerator.hpp"
#include "generator/llvm/detail/generators/ComparisonoperatorGenerator.hpp"
#include "generator/llvm/detail/generators/ConditionGenerator.hpp"
#include "generator/llvm/detail/generators/ConstructcallGenerator.hpp"
#include "generator/llvm/detail/generators/ContinueGenerator.hpp"
#include "generator/llvm/detail/generators/DatatypeGenerator.hpp"
#include "generator/llvm/detail/generators/DowhileGenerator.hpp"
#include "generator/llvm/detail/generators/EnumerationGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionoperatorertyGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionpostoperatorGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionpreoperatorGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionstatGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressiontermGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionvalueGenerator.hpp"
#include "generator/llvm/detail/generators/ForGenerator.hpp"
#include "generator/llvm/detail/generators/FunctionGenerator.hpp"
#include "generator/llvm/detail/generators/FunctionattributeGenerator.hpp"
#include "generator/llvm/detail/generators/FunctioncallGenerator.hpp"
#include "generator/llvm/detail/generators/FunctiondefinitionGenerator.hpp"
#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/IfGenerator.hpp"
#include "generator/llvm/detail/generators/ImportGenerator.hpp"
#include "generator/llvm/detail/generators/InitlistGenerator.hpp"
#include "generator/llvm/detail/generators/InterfaceGenerator.hpp"
#include "generator/llvm/detail/generators/InterfacemethodGenerator.hpp"
#include "generator/llvm/detail/generators/LambdaGenerator.hpp"
#include "generator/llvm/detail/generators/LiteralGenerator.hpp"
#include "generator/llvm/detail/generators/LogicoperatorGenerator.hpp"
#include "generator/llvm/detail/generators/MathoperatorGenerator.hpp"
#include "generator/llvm/detail/generators/MixinGenerator.hpp"
#include "generator/llvm/detail/generators/NamespaceGenerator.hpp"
#include "generator/llvm/detail/generators/NumberGenerator.hpp"
#include "generator/llvm/detail/generators/ParameterlistGenerator.hpp"
#include "generator/llvm/detail/generators/PrimativetypeGenerator.hpp"
#include "generator/llvm/detail/generators/ReturnGenerator.hpp"
#include "generator/llvm/detail/generators/ScoperatoreGenerator.hpp"
#include "generator/llvm/detail/generators/ScriptGenerator.hpp"
#include "generator/llvm/detail/generators/StatblockGenerator.hpp"
#include "generator/llvm/detail/generators/StatementGenerator.hpp"
#include "generator/llvm/detail/generators/StringGenerator.hpp"
#include "generator/llvm/detail/generators/SwitchGenerator.hpp"
#include "generator/llvm/detail/generators/TryGenerator.hpp"
#include "generator/llvm/detail/generators/TypeGenerator.hpp"
#include "generator/llvm/detail/generators/TypedefinitionGenerator.hpp"
#include "generator/llvm/detail/generators/TypemodifierGenerator.hpp"
#include "generator/llvm/detail/generators/VariableGenerator.hpp"
#include "generator/llvm/detail/generators/VariableaccessGenerator.hpp"
#include "generator/llvm/detail/generators/VirtualproperatorertyGenerator.hpp"
#include "generator/llvm/detail/generators/WhileGenerator.hpp"

#include "logger/Logger.hpp"

namespace ice_script { namespace generator { namespace llvm {

using namespace ice_script::generator::llvm::detail;
using namespace ::llvm;

static bool debug = true;

LlvmIrVisitor::LlvmIrVisitor(logger::ILogger& logger, std::shared_ptr<Context> context, std::shared_ptr<Llvm> llvm)
:
        logger_(&logger),
        context_(std::move(context)),
        llvm_(std::move(llvm))
{

}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const std::string& string) const
{
    std::cout << "I AM HERE 3: " << typeid(std::string).name() << " " << string << std::endl;
    
    return {};
}

std::vector<::llvm::Type*> LlvmIrVisitor::createParameterTypeList(const std::vector<asg::Variable>& parameters) const
{
    std::vector<::llvm::Type*> parameterList{};

    for (const auto& parameter : parameters)
    {
//        const auto& type = parameter.type;
//        const auto& typeMod = parameter.get<1>().get();
//        const auto& identifier = parameter.get<2>();
//        const auto& expression = parameter.get<3>();

//        auto param = Type::getInt64Ty(llvm_->context());
//        auto paramType = llvmType(type);

        auto paramType = ::llvm::Type::getInt64Ty(llvm_->context());

        parameterList.push_back(paramType);
    }

    return parameterList;
}

::llvm::Type* LlvmIrVisitor::toLlvmType(const Type& type) const
{
    auto paramType = ::llvm::Type::getInt64Ty(llvm_->context());

    return paramType;
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Asg& asg) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(asg).name())

    return operator()(asg.root);
//        boost::apply_visitor(LlvmIrVisitor(_os, indent+TAB_SIZE), ast.root);
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Script& script) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(script).name())

    for (const auto& node : script.nodes)
    {
        boost::apply_visitor(*this, node);
    }

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Class& classData) const
{
   LOG_DEBUG(logger_, "Processing %s", typeid(classData).name())

   return process(*context_, *llvm_, classData);
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Typedefinition& typedefinition) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(typedefinition).name())

    Scope& scope = context_->scope();

    return {};
}

//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Namespace& namespaceDefinition) const
//{
//    LOG_DEBUG(logger_, "Processing %s", typeid(namespaceDefinition).name())
//
//    Scope& scope = context_->scope();
//}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Function& function) const
{
    return process(*context_, *llvm_, function);
}

//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Interface& interfaceData) const
//{
//    LOG_DEBUG(logger_, "Processing %s", typeid(interfaceData).name())
//
//    Scope& scope = context_->scope();
//}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Variable& variable) const
{
    return process(*context_, *llvm_, variable);
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Import& import) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(import).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Enumeration& enumeration) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(enumeration).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Functiondefinition& functiondefinition) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(functiondefinition).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Virtualproperatorerty& virtualproperatorerty) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(virtualproperatorerty).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Mixin& mixin) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(mixin).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Interfacemethod& interfacemethod) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(interfacemethod).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Statblock& statblock) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(statblock).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Parameterlist& parameterlist) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(parameterlist).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Typemodifier& typemodifier) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(typemodifier).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const Type& type) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(type).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Initlist& initlist) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(initlist).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Scoperatore& scoperatore) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(scoperatore).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Datatype& datatype) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(datatype).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Primativetype& primativetype) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(primativetype).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Functionattribute& functionattribute) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(functionattribute).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Statement& statement) const
{
    return process(*context_, *llvm_, statement);
}

//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Switch& switchStatement) const
//{
//    LOG_DEBUG(logger_, "Processing %s", typeid(switchStatement).name())
//
//    Scope& scope = context_->scope();
//}
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Break& breakStatement) const
//{
//    LOG_DEBUG(logger_, "Processing %s", typeid(breakStatement).name())
//
//    Scope& scope = context_->scope();
//}
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::For& forLoop) const
//{
//    LOG_DEBUG(logger_, "Processing %s", typeid(forLoop).name())
//
//    Scope& scope = context_->scope();
//}
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::While& whileStatement) const
//{
//    LOG_DEBUG(logger_, "Processing %s", typeid(whileStatement).name())
//
//    Scope& scope = context_->scope();
//}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Dowhile& dowhile) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(dowhile).name())

    Scope& scope = context_->scope();

    return {};
}

//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::If& ifStatement) const
//{
//    LOG_DEBUG(logger_, "Processing %s", typeid(ifStatement).name())
//
//    Scope& scope = context_->scope();
//}
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Continue& continueStatement) const
//{
//    LOG_DEBUG(logger_, "Processing %s", typeid(continueStatement).name())
//
//    Scope& scope = context_->scope();
//}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Expressionstat& expressionstat) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(expressionstat).name())

    Scope& scope = context_->scope();

    return {};
}

//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Try& tryStatement) const
//{
//    LOG_DEBUG(logger_, "Processing %s", typeid(tryStatement).name())
//
//    Scope& scope = context_->scope();
//}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Return& ret) const
{
    return process(*context_, *llvm_, ret);
}

//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Case& caseStatement) const
//{
//    LOG_DEBUG(logger_, "Processing %s", typeid(caseStatement).name())
//
//    Scope& scope = context_->scope();
//}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Expression& expression) const
{
    return process(*context_, *llvm_, expression);
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Expressionterm& expressionterm) const
{
    return process(*context_, *llvm_, expressionterm);
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Expressionvalue& expressionvalue) const
{
    return process(*context_, *llvm_, expressionvalue);
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Constructcall& constructcall) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(constructcall).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Expressionpreoperator& expressionpreoperator) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(expressionpreoperator).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Expressionpostoperator& expressionpostoperator) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(expressionpostoperator).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Cast& cast) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(cast).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Lambda& lambda) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(lambda).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Literal& literal) const
{
    return process(*context_, *llvm_, literal);
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Functioncall& functioncall) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(functioncall).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Variableaccess& variableaccess) const
{
    return process(*context_, *llvm_, variableaccess);
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Arglist& arglist) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(arglist).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Assign& assign) const
{
    return process(*context_, *llvm_, assign);
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Condition& condition) const
{
    return process(*context_, *llvm_, condition);
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Expressionoperatorerty& expressionoperatorerty) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(expressionoperatorerty).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Bitoperator& bitoperator) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(bitoperator).name())

    Scope& scope = context_->scope();

    return {};
}

//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Mathoperator& mathoperator) const
//{
//    LOG_DEBUG(logger_, "Processing %s", typeid(mathoperator).name())
//
//    Scope& scope = context_->scope();
//}
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Comparisonoperator& comparisonoperator) const
//{
//    LOG_DEBUG(logger_, "Processing %s", typeid(comparisonoperator).name())
//
//    Scope& scope = context_->scope();
//}
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Logicoperator& logicoperator) const
//{
//    LOG_DEBUG(logger_, "Processing %s", typeid(logicoperator).name())
//
//    Scope& scope = context_->scope();
//}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Assignoperator& assignoperator) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(assignoperator).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Identifier& identifier) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(identifier).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Number& number) const
{
    return process(*context_, *llvm_, number);
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::String& string) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(string).name())

    Scope& scope = context_->scope();

    return {};
}

LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const asg::Bits& bits) const
{
    LOG_DEBUG(logger_, "Processing %s", typeid(bits).name())

    Scope& scope = context_->scope();

    return {};
}


//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::ClassNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::TypedefNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//
//    operator()(node.primTypeNode);
//    operator()(node.identifierNode);
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::NamespaceNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::FuncNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//
//    std::cout << node.identifierNode.get().value << std::endl;
//
//    Scope tmp{};
//    Scope& scope = scope_ ? *scope_ : tmp;
//
//    generate(node, scope);
//
////    Function* testFunction;
////    {
////        const auto& name = node.identifierNode.get().value;
////
//////        std::vector<Type*> parameterList = {2, Type::getInt64Ty(llvm_->context())};
////        auto parameterList = createParameterTypeList(node.paramlistNode.get());
////
////        // Make the function type:  int(int, int) etc.
//////        std::vector<Type*> integers{2, Type::getInt64Ty(llvm_->context())};
////        FunctionType* FT = FunctionType::get(Type::getInt64Ty(llvm_->context()), parameterList, false);
////
////        testFunction = Function::Create(FT, Function::ExternalLinkage, name, module_);
////
////        // Set names for all arguments.
//////        unsigned Idx = 0;
//////        for (auto &Arg : testFunction->args())
//////            Arg.setName(Args[Idx++]);
////
////        auto argsIterator = testFunction->args();
//////        for (const auto& parameter : node.paramlistNode.get().value)
////        for (int i = 0; i < testFunction->arg_size(); ++i)
////        {
////            auto arg = testFunction->getArg(i);
////            auto parameter = node.paramlistNode.get().value[i];
////
//////            const auto& type = parameter.get<0>().get();
//////            const auto& typeMod = parameter.get<1>().get();
////            const auto& identifier = parameter.get<2>();
//////            const auto& expression = parameter.get<3>();
////
////    //        auto param = Type::getInt64Ty(llvm_->context());
////    //        auto paramType = llvmType(type);
////
////            if (identifier)
////            {
////                const auto& paramName = identifier.get().get().value;
////                arg->setName(paramName);
////            }
////        }
////
////
////
////        // Set names for all arguments.
//////    unsigned Idx = 0;
//////    for (auto &Arg : F->args())
//////        Arg.setName(Args[Idx++]);
//////
//////    return F;
////
//////    namedValues.clear();
//////    for (auto &Arg : F->args())
//////    {
//////        std::cout << "ARG " << Arg.getArgNo() << ": " << std::string(Arg.getName()) << std::endl;
//////        namedValues[std::string(Arg.getName())] = &Arg;
//////    }
////
////        BasicBlock* BB = BasicBlock::Create(llvm_->context(), "entry", testFunction);
////        llvm_->builder().SetInsertPoint(BB);
////
//////    llvm::APFlo
//////    Value* constant = ConstantFP::get(llvm_->context(), llvm::APInt(1));
////
//////    auto it = namedValues.begin();
////
//////int i = 0;
//////
//////void test(int j, int k)
//////{
//////    int l = j + k;
//////    print("ok: " + l);
//////}
////
////        if (node.optionalStatblockNode)
////        {
////            const auto& statblockNode = node.optionalStatblockNode.get().get();
////
////            for (const auto& varOrStatement : statblockNode.value)
////            {
////
////            }
////        }
////
////        auto itr = testFunction->args();
////        auto it = itr.begin();
////        Value* L = (Value*) &(*it);
////        Value* R = (Value*) &(*(++it));
////        Value* result = llvm_->builder().CreateAdd(L, R, "addtmp");
////        llvm_->builder().CreateRet(result);
////    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::InterfaceNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::VarNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//
//    Scope tmp{};
//    Scope& scope = scope_ ? *scope_ : tmp;
//
//    generate(node, scope);
////    operator()(node.primTypeNode);
////    tab(TAB_SIZE);
////    operator()(node.identifierNode);
//
////    llvm::Value* constant1 = ConstantInt::get(IntegerType::getInt64Ty(llvm_->context()), 1);
////    llvm::Value* pHelloWorldStr = llvm_->builder().CreateGlobalStringPtr("hello world!");
////    auto global_variable = module_->getOrInsertGlobal("gvar", IntegerType::getInt64Ty(llvm_->context()));
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::ImportNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::EnumNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::FuncdefNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::VirtpropNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::MixinNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::IntfmthdNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::StatblockNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::ParamlistNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::TypemodNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::TypeNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//
//    operator()(node.scopeNode);
//    operator()(node.datatypeNode);
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::InitlistNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::ScopeNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::DatatypeNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//
//    boost::apply_visitor(LlvmIrVisitor(llvm_->context(), *module_, *builder_), node.value);
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::PrimtypeNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::FuncattrNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//
//    std::cout << node.value.size() << " ";
//    for (const auto& e : node.value)
//    {
//        std::cout << e << " ";
//    }
//    std::cout << std::endl;
//
////        operator()(node.isRef);
////
////        if (node.inout)
////        {
////            tab(TAB_SIZE);
////            operator()(node.inout.get());
////        }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::StatementNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//
//    Scope tmp{};
//    Scope& scope = scope_ ? *scope_ : tmp;
//
//    boost::apply_visitor(LlvmIrVisitor(llvm_->context(), *module_, *builder_, scope), node.value);
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::SwitchNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::BreakNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::ForNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::WhileNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::DowhileNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::IfNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::ContinueNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::ExprstatNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//
//    if (!node.value)
//    {
//        return;
//    }
//
//    const auto& assignNode = node.value.get().get();
//
//    operator()(assignNode);
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::TryNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::ReturnNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::CaseNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::ExprNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//
//    operator()(node.exprtermNode);
//
//    for (const auto& value : node.value)
//    {
//        operator()(value.get<0>());
//        operator()(value.get<1>());
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::ExprtermNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//
//    if (node.value.which() == 0)
//    {
//        const ast::OptionalTypeAndInitListType& a = *boost::get<ast::OptionalTypeAndInitListType>(&node.value);
//
//        if (a.get<0>())
//        {
//            operator()(a.get<0>().get());
//        }
//
//        operator()(a.get<1>());
//    } else if (node.value.which() == 1)
//    {
//        const ast::VectorExprpreopExprvalueVectorExprpreopType& a = *boost::get<ast::VectorExprpreopExprvalueVectorExprpreopType>(&node.value);
//
//        for (const auto& b : a.get<0>())
//        {
//            operator()(b);
//        }
//
//        operator()(a.get<1>());
//
//        for (const auto& b : a.get<2>())
//        {
//            operator()(b);
//        }
//    }
//
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::ExprvalueNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//
//    Scope tmp{};
//    Scope& scope = scope_ ? *scope_ : tmp;
//
//    boost::apply_visitor(LlvmIrVisitor(llvm_->context(), *module_, *builder_, scope), node.value);
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::ConstructcallNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//
//    operator()(node.typeNode.get());
//    operator()(node.arglistNode.get());
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::ExprpreopNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::ExprpostopNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::CastNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::LambdaNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::LiteralNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//
//    boost::apply_visitor(LlvmIrVisitor(llvm_->context(), *module_, *builder_), node.value);
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::FunccallNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::VaraccessNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::ArglistNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//
//    for (const auto& value : node.value)
//    {
//        if (value.get<0>())
//        {
//            operator()(value.get<0>()->get<0>());
//        }
//
//        operator()(value.get<1>());
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::AssignNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//
//    operator()(node.conditionNode);
//
//    if (node.assignopNodeAssignNode)
//    {
//        operator()(node.assignopNodeAssignNode.get().get<0>());
//        operator()(node.assignopNodeAssignNode.get().get<1>());
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::ConditionNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//
//    operator()(node.exprNode);
//
//    if (node.assignNode)
//    {
//        operator()(node.assignNode.get().get<0>());
//        operator()(node.assignNode.get().get<1>());
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::ExpropNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//
//    // boost::variant<BitopNode, MathopNode, CompopNode, LogicopNode> value;
//
//    boost::apply_visitor(LlvmIrVisitor(llvm_->context(), *module_, *builder_), node.value);
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::BitopNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::MathopNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::CompopNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::LogicopNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::AssignopNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::IdentifierNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::NumberNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::StringNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::BitsNode& node) const
//{
//    if (debug)
//    {
//        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
//        std::cout << typeid(node).name();
//        std::cout << std::endl;
//    }
//}
//
////    void operator()(const TypemodNode& node) const
////    {
////        tab(indent_);
////
////        if (debug)
////        {
////            std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
////            std::cout << typeid(node).name();
////            std::cout << std::endl;
////        }
////
////        tab(TAB_SIZE);
////        operator()(node.isRef);
////
////        if (node.inout)
////        {
////            tab(TAB_SIZE);
////            operator()(node.inout.get());
////        }
////    }
//
////LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::Node& node) const
////{
////    if (debug)
////    {
////        std::cout << "Line: " << node.line << " Column: " << node.column << " Length: " << node.length << " ";
////        std::cout << typeid(node).name();
////        std::cout << std::endl;
////    }
////
////    std::cout << typeid(node).name() << std::endl;
////    operator()(node.scriptNode);
//////        for (const auto& _node : node.values)
//////        {
////////            tab(indent+tabsize);
////////            operator()(_node);
//////            boost::apply_visitor(LlvmIrVisitor(llvm_->context(), *module_, *builder_), _node);
//////        }
////////        tab(indent);
////}
//
//LlvmIrVisitorReturnType LlvmIrVisitor::operator()(const ast::Ast& ast) const
//{
//    std::cout << typeid(ast).name() << std::endl;
//    operator()(ast.root);
////        boost::apply_visitor(LlvmIrVisitor(_os, indent+TAB_SIZE), ast.root);
//}
//
//std::vector<Type*> LlvmIrVisitor::createParameterTypeList(const ast::ParamlistNode& node) const
//{
//    std::vector<Type*> parameterList{};
//
//    for (const auto& parameter : node.value)
//    {
//        const auto& type = parameter.get<0>().get();
//        const auto& typeMod = parameter.get<1>().get();
//        const auto& identifier = parameter.get<2>();
//        const auto& expression = parameter.get<3>();
//
////        auto param = Type::getInt64Ty(llvm_->context());
////        auto paramType = llvmType(type);
//
//        auto paramType = Type::getInt64Ty(llvm_->context());
//
//        parameterList.push_back(paramType);
//    }
//
//    return parameterList;
//}
//
//void LlvmIrVisitor::generate(const ast::FuncNode& node, Scope& scope) const
//{
//    Scope currentScope{scope};
//
//    const auto& name = node.identifierNode.get().value;
//
////        std::vector<Type*> parameterList = {2, Type::getInt64Ty(llvm_->context())};
//    auto parameterList = createParameterTypeList(node.paramlistNode.get());
//
//    // Make the function type:  int(int, int) etc.
////        std::vector<Type*> integers{2, Type::getInt64Ty(llvm_->context())};
//    FunctionType* functionType = FunctionType::get(Type::getInt64Ty(llvm_->context()), parameterList, false);
//
//    Function* function = Function::Create(functionType, Function::ExternalLinkage, name, module_);
//
//    scope.add(name, *function);
//    currentScope.add(name, *function);
//    currentScope.set(function);
//
//    // Set names for all arguments.
//    auto argsIterator = function->args();
//    for (int i = 0; i < function->arg_size(); ++i)
//    {
//        auto arg = function->getArg(i);
//        auto parameter = node.paramlistNode.get().value[i];
//
////            const auto& type = parameter.get<0>().get();
////            const auto& typeMod = parameter.get<1>().get();
//        const auto& identifier = parameter.get<2>();
////            const auto& expression = parameter.get<3>();
//
////        auto param = Type::getInt64Ty(llvm_->context());
////        auto paramType = llvmType(type);
//
//        if (identifier)
//        {
//            const auto& paramName = identifier.get().get().value;
//            arg->setName(paramName);
//        }
//    }
//
//    // set parameter variables to be in scope
//    for (auto& arg : function->args())
//    {
//        currentScope.add(std::string(arg.getName()), arg);
//    }
//
////    llvm::APFlo
////    Value* constant = ConstantFP::get(llvm_->context(), llvm::APInt(1));
//
////    auto it = namedValues.begin();
//
////int i = 0;
////
////void test(int j, int k)
////{
////    int l = j + k;
////    print("ok: " + l);
////}
//
//    if (node.optionalStatblockNode)
//    {
//        generate(node.optionalStatblockNode.get().get(), currentScope);
//    }
//}
//
//void LlvmIrVisitor::generate(const ast::StatblockNode& node, Scope& scope) const
//{
//    Scope currentScope{scope};
//
//    auto function = currentScope.function();
//
//    BasicBlock* BB = BasicBlock::Create(llvm_->context(), "entry", function);
//    llvm_->builder().SetInsertPoint(BB);
//
//    currentScope.add("entry", *BB);
//    currentScope.set(BB);
//
//    for (const auto& varOrStatement : node.value)
//    {
//        LlvmIrVisitor visitor{llvm_->context(), *module_, *builder_, currentScope};
//
//        boost::apply_visitor(visitor, varOrStatement);
//    }
//
//    auto itr = function->args();
//    auto it = itr.begin();
//    Value* L = (Value*) &(*it);
//    Value* R = (Value*) &(*(++it));
//    Value* result = llvm_->builder().CreateAdd(L, R, "addtmp");
//    llvm_->builder().CreateRet(result);
//}
//
//void LlvmIrVisitor::generate(const ast::VarNode& node, Scope& scope) const
//{
////    Scope currentScope{scope};
//
//    if (scope.basicBlock())
//    {
//        auto variable = llvm_->builder().CreateAlloca(Type::getInt64Ty(llvm_->context()), 0, node.identifierNode.get().value);
//
//        scope.add(node.identifierNode.get().value, *variable);
//    }
//    else
//    {
//        // global
//        llvm::Value* constant1 = ConstantInt::get(IntegerType::getInt64Ty(llvm_->context()), 1);
////    llvm::Value* pHelloWorldStr = llvm_->builder().CreateGlobalStringPtr("hello world!");
////    auto global_variable = module_->getOrInsertGlobal("gvar", IntegerType::getInt64Ty(llvm_->context()));
//
//    }
//}
////
////void LlvmIrVisitor::generate2(const ast::VarNode& node, Scope& scope) const
////{
//////    Scope currentScope{scope};
////
////    const Variable& variable = node.variable;
////
////    auto type = resolve(node.typeNode.get());
////    auto identifier = resolve(node.identifierNode.get());
////
////    if (node.initListOrExprOrArgList)
////    {
////        auto value = resolve(node.initListOrExprOrArgList.get());
////    }
////
////    if (scope.basicBlock())
////    {
////        auto variable = llvm_->builder().CreateAlloca(Type::getInt64Ty(llvm_->context()), 0, node.identifierNode.get().value);
////
////        scope.add(node.identifierNode.get().value, *variable);
////    }
////    else
////    {
////        // global
////        llvm::Value* constant1 = ConstantInt::get(IntegerType::getInt64Ty(llvm_->context()), 1);
//////    llvm::Value* pHelloWorldStr = llvm_->builder().CreateGlobalStringPtr("hello world!");
//////    auto global_variable = module_->getOrInsertGlobal("gvar", IntegerType::getInt64Ty(llvm_->context()));
////
////    }
////}

}}}