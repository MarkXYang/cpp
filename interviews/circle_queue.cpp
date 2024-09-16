#include <iostream>
#include <array>

using namespace std;
class QueueOverflowException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Queue overflow: Cannot enqueue element into full queue";
    }
};

class QueueUnderflowException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Queue Underflow: Cannot dnqueue element into empty queue";
    }
};

class CircleQueue
{
public:
    bool isEmpty()
    {
        return head == EMPTY_VAL;
    }

    bool isFull()
    {
        int next = (tail + 1) % cir_queue.size();
        return next == head;
    }

    void enqueue(int data)
    {
        if (isFull())
        {
            throw QueueOverflowException();
        }

        tail = (tail + 1) % cir_queue.size();
        cir_queue[tail] = data;

        if (head == EMPTY_VAL)
        {
            head = tail;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            throw QueueUnderflowException();
        }

        int data = cir_queue[head];

        if (head == tail)
        {
            head = EMPTY_VAL;
        }
        else
        {
            head = (head + 1) % cir_queue.size();
        }
        return data;
    }

private:
    static const int MAXSIZE = 16;
    array<int, MAXSIZE> cir_queue;
    const int EMPTY_VAL = -1;
    int head = EMPTY_VAL;
    int tail = EMPTY_VAL;
};

int main()
{
    CircleQueue queue;

    std::cout << "Testing Circular Queue:" << std::endl;

    // Test enqueue
    std::cout << "\nEnqueuing elements:" << std::endl;
    for (int i = 1; i <= 5; ++i)
    {
        queue.enqueue(i);
        std::cout << "Enqueued: " << i << std::endl;
    }

    // Test dequeue
    std::cout << "\nDequeuing elements:" << std::endl;
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "Dequeued: " << queue.dequeue() << std::endl;
    }

    // Enqueue more elements
    std::cout << "\nEnqueuing more elements:" << std::endl;
    for (int i = 6; i <= 8; ++i)
    {
        queue.enqueue(i);
        std::cout << "Enqueued: " << i << std::endl;
    }

    // Test exception handling
    std::cout << "\nTesting exception handling:" << std::endl;
    try
    {
        // Try to enqueue when queue is full
        for (int i = 9; i <= 20; ++i)
        {
            queue.enqueue(i);
        }
    }
    catch (const QueueOverflowException &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Dequeue all elements
    std::cout << "\nDequeuing all elements:" << std::endl;
    while (!queue.isEmpty())
    {
        std::cout << "Dequeued: " << queue.dequeue() << std::endl;
    }

    // Test underflow
    try
    {
        queue.dequeue();
    }
    catch (const QueueUnderflowException &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
