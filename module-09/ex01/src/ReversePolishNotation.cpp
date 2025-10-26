#include "../include/ReversePolishNotation.hpp"

bool ReversePolishNotation::isOperator(const std::string& token) const
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool ReversePolishNotation::isValidNumString(const std::string& token, int& num) const
{
    char* endptr;
    long  result = std::strtol(token.c_str(), &endptr, 10);
    if (*endptr != '\0' || endptr == token.c_str())
    {
        return false;
    }

    if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
    {
        throw std::runtime_error("Number overflow/underflow");
    }

    num = static_cast<int>(result);
    return true;
}

void ReversePolishNotation::performRnp(const std::string& op)
{
    if (st.size() < 2)
    {
        throw std::runtime_error("Stack must contain at least two number for this operation");
    }

    int result, a, b;
    b = st.top();
    st.pop();
    a = st.top();
    st.pop();

    switch (op[0])
    {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b == 0)
                throw std::runtime_error("Division by zero error.");
            result = a / b;
            break;
    }
    st.push(result);
}

/* -------------------------------------------------------------------------- */

/* [ALGO]:
 * I have to go through an example string like, ./RNP "7 7 * 7 -"
 * I can go through the string, each char is seperated by a space
 * If its a number push it to the stack, if its an operator access whatever
 * inside the stack do the operation and replace the stack with the result */
void ReversePolishNotation::rnp(std::string& str)
{
    std::istringstream iss(str);
    std::string        token;

    while (iss >> token)
    {
        int num;
        if (isValidNumString(token, num))
        {
            if (num < 0 || num > 9)
            {
                if (token.length() == 1)
                    st.push(num);
                else
                    throw std::runtime_error("Input numbers must be < 10");
            }
            else
            {
                st.push(num);
            }
        }
        else if (isOperator(token))
        {
            performRnp(token);
        }
        else
        {
            throw std::runtime_error("Invalid token '" + token + "'");
        }
    }

    if (st.size() == 1)
        std::cout << "Result: " << st.top() << std::endl;
    else
        std::cerr << "Error: Invalid RPN expression." << std::endl;
}

/* -------------------------------------------------------------------------- */

ReversePolishNotation::ReversePolishNotation()
{
    return;
}

ReversePolishNotation::~ReversePolishNotation()
{
    return;
}

ReversePolishNotation::ReversePolishNotation(const ReversePolishNotation& other) : st(other.st)
{
    return;
}

ReversePolishNotation& ReversePolishNotation::operator=(const ReversePolishNotation& other)
{
    if (this != &other)
    {
        st = other.st;
    }
    return *this;
}
