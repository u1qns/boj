#include <iostream>
#define MAX_SIZE 500001

class Queue {
    
public:
    int count;
    
    Queue(int n): size(n), front(-1), rear(-1), count(0){};
    
    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (front == rear + 1))
            return true;
        else
            return false;
    }
    
    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }
    
    void enQueue(int data)
    {
        if (!isFull())
        {
            if (front == -1) front = 0;
            rear = (rear + 1) % size;
            items[rear] = data;
            ++count;
        }
    }
    
    int deQueue()
    {
        if (isEmpty())
            return (-1);
        
        int data = items[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        --count;
        return data;
    }
    
    void display()
    {
        std::cout << "\ndisplay---------------\n";

        for(int i = 0; i<size; ++i)
        {
            std::cout << items[i] << "\t";
        }
        std::cout << "\n----------------------\n";
    }
    
private:
    int items[MAX_SIZE];
    int front, rear;
    int size;
    
    
};

int main()
{
    int N = 0;
    std::cin >> N;
    if(N==1)
    {
        std::cout << N << std::endl;
        return 0;
    }
    
    Queue q(N);
    q.deQueue();
    for(int i = 1; i<=N; ++i)
    {
        q.enQueue(i);
    }
    while(1)
    {
        if(q.count == 1)
        {
            std::cout << q.deQueue() << std::endl;
            break;
        }
        q.deQueue();
        q.enQueue(q.deQueue());

    }
    
    return 0;
}

