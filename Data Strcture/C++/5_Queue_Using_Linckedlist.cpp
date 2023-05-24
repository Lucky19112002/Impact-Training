#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* frontPtr = nullptr;
Node* rearPtr = nullptr;

void enqueue(int data) {
    Node* newNode = new Node(data);

    if (rearPtr == nullptr) {
        frontPtr = newNode;
        rearPtr = newNode;
    } else {
        rearPtr->next = newNode;
        rearPtr = newNode;
    }
}

void dequeue() {
    if (frontPtr == nullptr) {
        cout << "Queue is empty." << endl;
    } else {
        Node* temp = frontPtr;
        frontPtr = frontPtr->next;
        delete temp;

        if (frontPtr == nullptr) {
            rearPtr = nullptr;
        }
    }
}

void display() {
    if (frontPtr == nullptr) {
        cout << "Queue is empty." << endl;
    } else {
        Node* current = frontPtr;
        cout << "Queue elements: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    dequeue();

    display();


    return 0;
}
