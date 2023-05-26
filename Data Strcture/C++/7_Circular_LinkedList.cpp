#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

struct node *start(struct node *head,int data){
    struct node *temp = (struct node *) malloc (sizeof(struct node));
    if(head == nullptr){
        temp->data = data;
        head = temp;
        head->next = head;
    }
    else{
        temp->data = data;
        temp->next  = head->next;
        head->next = temp;
        head = temp;
    }
    return head;
}

struct node *deletAtStart(struct node *head){
    struct node *prev = head, *first = head;
    if(head == nullptr){
        cout<<" List is empty"<<endl;
        return NULL;
    }
    if(prev->next == prev)
    {
        head = NULL;
        return head;
    }
    while (prev->next != head)
    {
        prev = prev->next;
    }
    prev->next = first->next;
    head = prev->next;
    return head;
}

struct node *deletAtEnd(struct node *head){
    struct node *curr =head, *temp = head,*prev;
    if(head == nullptr){
        cout<<" List is empty"<<endl;
        return NULL;
    }
    if (curr->next == curr){
        head = NULL;
        return head;
    }
    while (curr->next != head){
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    head = prev->next;
    free(curr);
    return head;
}

void display(struct node *head){
    struct node *t;
    if(head == nullptr){
        cout<<" LIncked list in empty"<<endl;
        return;
    }
    t = head;

    do{
        cout<<" "<<t->data;
        t = t->next;
    } while (t !=head);    
    cout<<" "<<endl;
}

int main(){
    struct node *head = NULL;
    head = start(head,0);
    head = start(head,1);
    head = start(head,2);
    head = start(head,3);
    head = start(head,4);
    head = start(head,5);
    head = start(head,6);
    cout<<" ------Data Vilable------------ "<<endl;
    display(head);
    head = deletAtStart(head);
    cout<<" ------Delete at First------------ "<<endl;
    display(head);
    head = deletAtStart(head);
    cout<<" ------Delete at First------------ "<<endl;
    display(head);
    head = deletAtStart(head);
    cout<<" ------Delete at First------------ "<<endl;
    display(head);
    head = deletAtEnd(head);
    cout<<" ------Delete at Last------------ "<<endl;
    display(head);
    return 0;
    
}