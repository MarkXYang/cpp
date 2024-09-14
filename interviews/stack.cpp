#include <iostream>

template <typename T>
class Element
{
public:
    Element(T data, Element *nextE)
    {
        this->data = data;
        this->next = nextE;
    }
    T getData()
    {
        return data;
    }
    void setData(T data)
    {
        this.data = data;
    }
    Element *getNext()
    {
        return next;
    }
    void setNext(Element *next)
    {
        this->next = next;
    }

private:
    T data;
    Element *next;
};

class StackOverflowException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Stack overflow: Cannot push element onto full stack";
    }
};
class StackUnderflowException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Stack underflow: Cannot pop or peek from an empty stack";
    }
};

template <typename T>
class Stack
{
public:
    void push(T data)
    {
        if (size == MAX_SIZE)
        {
            throw StackOverflowException();
        }

        Element<T> *elem = new Element<T>(data, top);
        top = elem;
        ++size;
    }

    T pop()
    {
        if (size == 0)
        {
            throw StackUnderflowException();
        }
        T data = top->getData();
        Element<T> *oldtop = top;
        top = top->getNext();
        delete oldtop;

        --size;
        return data;
    }
    T peek()
    {
        if (size == 0)
        {
            throw StackUnderflowException();
        }
        T data = top->getData();

        return data;
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    bool isFull() const
    {
        return size == MAX_SIZE;
    }
    int getSize() const
    {
        return size;
    }

private:
    const int MAX_SIZE = 32;
    Element<T> *top = nullptr;
    int size = 0;
};

int main()
{
    Stack<int> intStack;

    // Test push and pop
    std::cout << "Pushing elements onto the stack:" << std::endl;
    for (int i = 1; i <= 5; ++i)
    {
        intStack.push(i);
        std::cout << "Pushed: " << i << std::endl;
    }

    std::cout << "\nPopping elements from the stack:" << std::endl;
    while (!intStack.isEmpty())
    {
        std::cout << "Popped: " << intStack.pop() << std::endl;
    }

    // Test exception handling
    try
    {
        intStack.pop();
    }
    catch (const StackUnderflowException &e)
    {
        std::cout << "\nCaught exception: " << e.what() << std::endl;
    }

    // Test peek and isFull
    std::cout << "\nPushing elements until full:" << std::endl;
    for (int i = 1; i <= 32; ++i)
    {
        intStack.push(i);
    }

    std::cout << "Stack size: " << intStack.getSize() << std::endl;
    std::cout << "Is stack full? " << (intStack.isFull() ? "Yes" : "No") << std::endl;
    std::cout << "Top element: " << intStack.peek() << std::endl;

    try
    {
        intStack.push(33);
    }
    catch (const StackOverflowException &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
