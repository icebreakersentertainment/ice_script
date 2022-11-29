#ifndef ICE_SCRIPT_SHUNTINGYARDALGORITHM_HPP
#define ICE_SCRIPT_SHUNTINGYARDALGORITHM_HPP

#include <stack>
#include <queue>

namespace ice_script { namespace analyzer { namespace detail {

template <typename Container, typename Token>
class ShuntingYardAlgorithm
{
public:
    ShuntingYardAlgorithm() = default;

    auto process()
    {
        while (!tokens_.empty())
        {
            const Token token = tokens_.pop();

            if (isNumber(token))
            {
                outputQueue_.push(token);
            }
            else if (isOperator(token))
            {
                const Operator _operator = toOperator(token);

                if (!operatorStack_.empty())
                {
                    Operator* processedOperator = &operatorStack_.top();

                    while (processedOperator && processedOperator->precedence() > _operator.precedence())
                    {
                        processedOperator = nullptr;
                        outputQueue_.push(operatorStack_.top());

                        operatorStack_.pop();

                        if (!operatorStack_.empty()) processedOperator = &operatorStack_.top();
                    }
                }

                operatorStack_.push(_operator);
            }
            else if (isLeftBracket(token))
            {
                operatorStack_.push(token);
            }
            else if (isRightBracket(token))
            {
                if (operatorStack_.empty()) throw std::runtime_error("");

                Operator* processedOperator = &operatorStack_.top();

                while (processedOperator && !isLeftBracket(*processedOperator))
                {
                    processedOperator = nullptr;
                    outputQueue_.push(operatorStack_.top());

                    operatorStack_.pop();

                    if (!operatorStack_.empty()) processedOperator = &operatorStack_.top();
                }

                operatorStack_.pop();
            }
        }

        while (!operatorStack_.empty())
        {
            outputQueue_.push(operatorStack_.top());

            operatorStack_.pop();
        }
    }

private:
    Container tokens_;
    std::stack<Token> operatorStack_;
    std::queue<Token> outputQueue_;
};

}}}

#endif //ICE_SCRIPT_SHUNTINGYARDALGORITHM_HPP
