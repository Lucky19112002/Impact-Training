#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next; 
};

struct  Node* head =  NULL;

void push(int data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}
void pop(){
    struct Node* temp = head;
    head  = temp->next;
    temp = NULL;
}
void peek(){
    int temp = head->data;
    cout<<"\nData on top is "<<temp;
}
void print(){
    struct Node* ptr;
    cout<<"\n";
    ptr = head;
    while (ptr) {
        cout<< ptr->data <<" ";
        ptr = ptr->next;
   }
}
int main()
{
    push(50);
    push(40);
    push(30);
    push(20);
    push(10);
    cout<<"\nAfter All push :\n";
    print(); 
    pop();
    cout<<"\nAfter pop :\n";
    print(); 
    peek();
    print();
    return 0;
}