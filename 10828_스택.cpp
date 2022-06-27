#include <iostream>
#include <string>
#define MAX_SIZE 100000

class Stack
{
public:
    
    Stack(): size(0), top(-1){};
    
    
    void Push(int item)
    {
        if(!isFull())
        {
            ++top;
            items[top] = item;
        }
    }
    
    int Pop()
    {
        if(isEmpty())
        {
            return -1;
        }
        int item = items[top];
        --top;
        return item;
    }
    
    int Top()
    {
        if(isEmpty())
        {
            return -1;
        }
        return items[top];
    }
    
    int Size()
    {
        return top +1;
    }
    
    void Display()
    {
        std::cout << "\n=====================\n";
        for(int i=0; i<=top; ++i)
        {
            std::cout << items[i] << "\t";
        }
        std::cout << "\n=====================\n";
    }
    
    bool isFull()
    {
        if(top == MAX_SIZE)
        {
            return true;
        }
        return false;
    }
    
    bool isEmpty()
    {
        if(top == -1)
        {
            return true;
        }
        return false;
    }
    
private:
    int size;
    int top;
    int items[MAX_SIZE];
};
int main()
{
    int N, item = 0; std::cin >> N;
    std::string op;
    Stack s;
    
    while(N--)
    {
        std::cin >> op;
        
        if(op == "push"){
            std::cin >> item;
            s.Push(item);
        }else if(op == "pop"){
            std::cout << s.Pop() << "\n";}
        else if(op == "top"){
            std::cout << s.Top() << "\n";}
        else if(op == "size"){
            std::cout << s.Size() << "\n";}
        else if(op == "empty"){
            std::cout << s.isEmpty() << "\n";}
        else if(op == "display"){
            s.Display();}
    }
  
    return 0;
}
