#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void insert(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNode(Node** head, int value) {
    if (*head == nullptr) {
        cout << "List is empty. Deletion not possible." << endl;
        return;
    }
    Node* curr = *head;
    Node* prev = nullptr;
    bool found = false;
    while (curr != nullptr) {
        if (curr->data == value) {
            found = true;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    if (!found) {
        cout << "Node with value " << value << " not found." << endl;
        return;
    }
    if (curr == *head) {
        *head = curr->next;
    } else {
        prev->next = curr->next;
    }
    delete curr;
    cout << "Node with value " << value << " deleted successfully." << endl;
}

Node* fun1(Node* headA, Node* headB) {
    Node* mergedList = nullptr;
    Node* tail = nullptr;

    while (headA != nullptr && headB != nullptr) {
        if (headA->data == headB->data) {
            if (mergedList == nullptr) {
                mergedList = createNode(headA->data);
                tail = mergedList;
            } else {
                tail->next = createNode(headA->data);
                tail = tail->next;
            }
            headA = headA->next;
            headB = headB->next;
        } else if (headA->data < headB->data) {
            headA = headA->next;
        } else {
            headB = headB->next;
        }
    }

    return mergedList;
}

Node* fun2(Node* headA, Node* headB) {
    Node* mergedList = nullptr;
    Node* tail = nullptr;

    while (headA != nullptr) {
        if (mergedList == nullptr) {
            mergedList = createNode(headA->data);
            tail = mergedList;
        } else {
            bool exists = false;
            Node* temp = mergedList;
            while (temp != nullptr) {
                if (temp->data == headA->data) {
                    exists = true;
                    break;
                }
                temp = temp->next;
            }
            if (!exists) {
                tail->next = createNode(headA->data);
                tail = tail->next;
            }
        }
        headA = headA->next;
    }

    while (headB != nullptr) {
        bool exists = false;
        Node* temp = mergedList;
        while (temp != nullptr) {
            if (temp->data == headB->data) {
                exists = true;
                break;
            }
            temp = temp->next;
        }
        if (!exists) {
            if (mergedList == nullptr) {
                mergedList = createNode(headB->data);
                tail = mergedList;
            } else {
                tail->next = createNode(headB->data);
                tail = tail->next;
            }
        }
        headB = headB->next;
    }

    return mergedList;
}


int main() {
    Node* listA = nullptr;
    Node* listB = nullptr;
    

    insert(&listA, 3);
    insert(&listA, 7);
    insert(&listA, 10);
    insert(&listA, 15);
    insert(&listA, 16);
    insert(&listA, 9);
    insert(&listA, 22);
    insert(&listA, 17);
    insert(&listA, 23);
    insert(&listB, 16);
    insert(&listB, 2);
    insert(&listB, 9);
    insert(&listB, 13);
    insert(&listB, 47);
    insert(&listB, 8);
    insert(&listB, 10);
    insert(&listB, 1);
    insert(&listB, 28);
    cout << "List A: ";
    display(listA);

    cout << "List B: ";
    display(listB);

    cout<<"After adding similer elements for A and B: ";
    Node* listC = fun1(listA,listB);
    display(listC);

    cout<<"After adding  elements for A and B with no rpeptitation: "<<endl;
    Node* listD = fun2(listA,listB);
    display(listD);
    return 0;
}
