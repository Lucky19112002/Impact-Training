#include <iostream>
#include <list>

using namespace std;

list<int> myList;

void enqueue(int data) {
    myList.push_back(data);
}

void dequeue() {
    if (!myList.empty()) {
        myList.pop_front();
    } else {
        cout << "Queue is empty." << endl;
    }
}

void display() {
    if (myList.empty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue elements: ";
        for (int element : myList) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();

    dequeue();
    dequeue();
    display();

    return 0;
}
