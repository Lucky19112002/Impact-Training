#include<iostream>
using namespace std;
int queue[100];
int n=100 ,front = -1, rear = -1;

void push(int data)
{
    if (rear == n - 1)
        cout<<"Queue Overflow"<<endl;
    else 
    {
       if (front == - 1)
            front = 0;
       rear++;
       queue[rear] = data;
    }
}

void pop()
{
    if (front == - 1 || front > rear) 
    {
        cout<<"Queue Underflow ";
        return ;
    } 
    else 
    {
        cout<<"\nElement deleted from queue is : "<< queue[front] <<endl;
        front++;
    }
}

void display()
{
    cout<<"\nList is :\n";
    for (int i = front; i <= rear; i++)
    {
        cout<<queue[i]<<"\t";
    }
    
}
int main()
{
    push(10);
    display();
    push(20);
    display();
    pop();
    display();
    return 0;
}