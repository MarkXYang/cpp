#include <iostream>
#include <stack>

using namespace std;
class StackUnderflowException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Stack underflow: Cannot perform operation on an empty stack";
    }
};

template <typename T>
class MinimumStack
{
private:
    stack<T> astack;
    stack<T> MinimumStack;

public:
    void push(T value)
    {
        astack.push(value);
        T min = value;
        if (!MinimumStack.empty())
        {
            if (min > MinimumStack.top())
            {
                min = MinimumStack.top();
            }
        }
        MinimumStack.push(min);
    }

    T pop()
    {
        if (astack.empty())
        {
            throw StackUnderflowException();
        }
        MinimumStack.pop();
        T value = astack.top();
        astack.pop();
        return value;
        }

    T top()
    {
        if (astack.empty())
        {
            throw StackUnderflowException();
        }
        return astack.top();
    }

    T getMin()
    {
        if (MinimumStack.empty())
        {
            throw StackUnderflowException();
        }
        return MinimumStack.top();
    }

    bool isEmpty()
    {
        return astack.empty();
    }
};

int main()
{
    MinimumStack<int> minStack;

    // Test pushing elements
    std::cout << "Pushing elements onto the stack:" << std::endl;
    minStack.push(3);
    std::cout << "Pushed: 3, Min: " << minStack.getMin() << std::endl;
    minStack.push(5);
    std::cout << "Pushed: 5, Min: " << minStack.getMin() << std::endl;
    minStack.push(2);
    std::cout << "Pushed: 2, Min: " << minStack.getMin() << std::endl;
    minStack.push(1);
    std::cout << "Pushed: 1, Min: " << minStack.getMin() << std::endl;
    minStack.push(4);
    std::cout << "Pushed: 4, Min: " << minStack.getMin() << std::endl;

    // Test popping elements
    std::cout << "\nPopping elements from the stack:" << std::endl;
    while (!minStack.isEmpty())
    {
        std::cout << "Popped: " << minStack.pop() << ", New Min: ";
        if (!minStack.isEmpty())
        {
            std::cout << minStack.getMin() << std::endl;
        }
        else
        {
            std::cout << "Stack is empty" << std::endl;
        }
    }

    // Test exception handling
    try
    {
        minStack.pop();
    }
    catch (const StackUnderflowException &e)
    {
        std::cout << "\nCaught exception: " << e.what() << std::endl;
    }

    // Test pushing after popping all elements
    std::cout << "\nPushing new elements:" << std::endl;
    minStack.push(7);
    std::cout << "Pushed: 7, Min: " << minStack.getMin() << std::endl;
    minStack.push(6);
    std::cout << "Pushed: 6, Min: " << minStack.getMin() << std::endl;
    minStack.push(8);
    std::cout << "Pushed: 8, Min: " << minStack.getMin() << std::endl;

    // Test top() function
    std::cout << "\nTop element: " << minStack.top() << std::endl;
    std::cout << "Current min: " << minStack.getMin() << std::endl;

    return 0;
}
