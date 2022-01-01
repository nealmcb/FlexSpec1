// https://codereview.stackexchange.com/questions/164148/circular-buffer-c-implementation


#include <vector>
#include <stdexcept>

class CircularBuffer
{
    static const size_t EMPTY = ~0u;

    std::vector<char> data;
    size_t next = 0;               // index at which next insert will occur
    size_t head = EMPTY;           // index of next pop, or EMPTY marker

public:
    CircularBuffer(size_t size)
        : data(size)
    {
    }

    virtual ~CircularBuffer() = default;

    bool empty() const
    {
        return head == EMPTY;
    }

    size_t size() const
    {
        if (empty())
            return 0;
        if (next > head)
            return next - head;
        return data.size() - head + next;
    }

    void push(char val)
    {
        if (next == head)
            throw std::logic_error("Buffer overrun");

        data[next] = val;
        if (empty())
            head = next;
        if (++next == data.size())
            next = 0;
    }

    char pop()
    {
        if (empty())
            throw std::logic_error("Buffer underrun");

        const char popVal = data[head];

        if (++head == data.size())
            head = 0;

        if (head == next)
            head = EMPTY;

        return popVal;
    }
};
