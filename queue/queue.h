
template <typename T>
class Queue
{
    T *q;
    int front;
    int rear;
    int SIZE;

public:
    Queue(int);

    void operator+(T);
    void operator-();
    T peek();
    void print_Queue();
};
