#ifndef QUEUE_TYPE
#define QUEUE_TYPE

const int MAX_SIZE = 5;

template<class T>
class QueueType {
private:
    T data[MAX_SIZE];
    int front, rear;
public:
    QueueType();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    void Enqueue(T);
    void Dequeue();
    T Front();
};

class FullQueue {};
class EmptyQueue {};


#endif