#include<iostream>
#include<stack>
using namespace std;
stack<int> s1,s2;
void push(int data)
{
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(data);
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}

void pop()
{
    if(s1.empty())
    {
        cout<<"\nQueue is empty";
        exit(0);
    }
    int x = s1.top();
    s1.pop();
    cout<<"\nPop element: "<<x;
}

void display()
{
    stack<int> temp;
    temp = s1;
    while (!temp.empty()) {
        cout <<"\n"<< temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display();
    pop();
    pop();
    display();
    return 0;
}
