//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
};
// set an Empty lincked ist
struct Node* head = NULL;

void insertAtBegin(int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

void insertAtEnd(int new_data)
{
    struct Node* last = head;

    while (last->next != NULL)
        last= last->next;  
    
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    last->next = new_node;

}
void insertAtMiddle(int new_data,int pos)
{
    struct Node* ptr = head;
    while (ptr->data != pos)
    {
        ptr =  ptr->next;
    }
    
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = ptr->next;
    ptr->next = new_node;
}

void deleteAtBegin()
{
    struct Node* temp = head;
    head  = temp->next;
    temp = NULL;
}

void deleteAtEnd()
{
    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp= temp->next; 
    struct Node* prev  = temp->next;
    temp->next = NULL;
    prev = NULL;
}
void deleteAtmiddle(int pos)
{
    struct Node* prev = head;
    for(int i=0;i<pos-1;i++)
        prev= prev->next; 
    struct Node* temp  = prev->next;
    prev->next = temp->next;
    temp = NULL;

}
void search(int data)
{
    struct Node* ptr = head;
    int count = 1;
    while (ptr->data != data)
    {
        ptr =  ptr->next;
        count ++;
    }
    cout<<"\nElemetn "<<data<<" is on position "<<count;
}

void bubbleSort()
{
    if (head == NULL || head->next == NULL)
        return;

    struct Node* curr;
    struct Node* prev = NULL;
    bool swapped;

    do {
        swapped = false;
        curr = head;

        while (curr->next != prev) {
            if (curr->data > curr->next->data) {
                int temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
                swapped = true;
            }

            curr = curr->next;
        }

        prev = curr;
    } while (swapped);
}

void display(){
    struct Node* ptr;
    ptr = head;
    while (ptr) {
        cout<< ptr->data <<" ";
        ptr = ptr->next;
   }
}
// class LinckedList()
// {

// };

int main()
{
    // int n;
    // cout<<"Enter the of elements u want to add";
    // cin>>n;
    // for (int i = 0; i < n; i++)
    // {
    //     int temp = 0;
    //     cin >> temp;
    //     insertAtBegin(temp);
    // }
    
    insertAtBegin(10);
    insertAtBegin(20);
    insertAtBegin(30);
    insertAtBegin(40);
    insertAtBegin(50);
    insertAtEnd(1000);
    insertAtMiddle(55,40);
    insertAtMiddle(150,20);

    cout<<"\n The linked list is: \n";
    display();
    // deleteAtBegin();
    // cout<<"\n The linked list at begin deletion is: \n";
    // display();
    // deleteAtEnd();
    // cout<<"\n The linked list at  end deletion is: \n";
    // display();
    // deleteAtmiddle(3);
    // cout<<"\n The linked list at  middle deletion is: \n";
    // display();
    bubbleSort();

    cout << "\nSorted Linked List:\n ";
    display();

    return 0;
}
