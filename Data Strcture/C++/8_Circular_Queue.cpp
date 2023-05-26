#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node* link;
};
struct Queue
{
    struct node *frount,*rear;
};
void enQueue(Queue* q,int val){
    struct node* temp = new node;
    temp->data = val;
    if(q->frount == nullptr)
        q->frount = temp;
    else
        q->rear->link = temp;
    q->rear = temp;
    q->rear->link=q->frount;
}

void display(struct Queue* q){
    struct node* temp = q->frount;
    cout<<"-------Elements--------"<<endl;
    while (temp->link != q->frount)
    {
        cout<< temp->data << " " ;
        temp=temp->link;
    }
    cout<<temp->data;
}

void deleteNode(Queue* q, int value) {
    if (q->frount == nullptr) {
        cout << "Queue is empty. Deletion not possible." << endl;
        return;
    }
    struct node* curr = q->frount;
    struct node* prev = nullptr;
    bool found = false;
    do {
        if (curr->data == value) {
            found = true;
            break;
        }
        prev = curr;
        curr = curr->link;
    } while (curr != q->frount);
    if (!found) {
        cout << "Node with value " << value << " not found." << endl;
        return;
    }
    if (curr->link == q->frount) {
        q->frount = nullptr;
        q->rear = nullptr;
    }
    else if (curr == q->frount) {
        q->frount = curr->link;
        q->rear->link = q->frount;
    }
    else if (curr == q->rear) {
        prev->link = q->frount;
        q->rear = prev;
    }
    else {
        prev->link = curr->link;
    }
    delete curr;
    cout << "Node with value " << value << " deleted successfully." << endl;
}
int main(){
    Queue* q = new Queue;
    q->frount = q->rear = nullptr;

    enQueue(q,1);
    enQueue(q,2);
    enQueue(q,3);
    enQueue(q,4);
    enQueue(q,5);
    display(q);
    int nodeToDelete;
    cout << "\nEnter the value of the node to delete: ";
    cin >> nodeToDelete;
    deleteNode(q, nodeToDelete);

    cout << "\nAfter deletion: ";
    display(q);
    return 0;
}

