#include <iostream>
#include <string>
using namespace std;

struct Node {
    int empNumber;
    string name;
    float salary;
    Node* prev;
    Node* next;
};

Node* createNode(int empNumber, const string& name, float salary) {
    Node* newNode = new Node;
    newNode->empNumber = empNumber;
    newNode->name = name;
    newNode->salary = salary;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void insertNode(Node** head, int empNumber, const string& name, float salary) {
    Node* newNode = createNode(empNumber, name, salary);
    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    cout << "EMP Number\tName\t\tSalary" << endl;
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->empNumber << "\t\t" << temp->name << "\t\t" << temp->salary << endl;
        temp = temp->next;
    }
}

int main() {
    Node* head = nullptr;
    insertNode(&head, 101, "John Doe", 5000.0);
    insertNode(&head, 102, "Jane Smith", 6000.0);
    insertNode(&head, 103, "Robert Johnson", 5500.0);
    
    displayList(head);  

    return 0;
}
