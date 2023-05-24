#include <iostream>
#include <stack>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
Node* findNode(Node* node, int value) {
    if (node == nullptr || node->data == value)
        return node;
    if (value < node->data) 
        return findNode(node->left, value);
    else
        return findNode(node->right, value);
}
Node* insert(Node* node, int value) {
    if (node == nullptr) 
        return new Node(value);
    if (value < node->data)
        node->left = insert(node->left, value);
    else 
        node->right = insert(node->right, value);
    return node;
}

int getHeight(Node* node) {
    if (node == nullptr) 
        return 0;
    else {
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        return max(leftHeight, rightHeight) + 1;
    }
}

Node* findMaxNode(Node* node) {
    if (node == nullptr) 
           return nullptr;
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}
Node* Predecessor(Node* root, int value) {
    Node* node = findNode(root, value);
    if (node == nullptr)
        return nullptr;
    if (node->left != nullptr)
        return findMaxNode(node->left);
    else {
        Node* predecessor = nullptr;
        Node* current = root;
        while (current != nullptr) {
            if (value > current->data) {
                predecessor = current;
                current = current->right;
            } else {
                current = current->left;
            }
        }
        return predecessor;
    }
}

void printLeaves(Node* node) {
    if (node == nullptr) {
        return;
    }

    printLeaves(node->left);

    if (node->left == nullptr && node->right == nullptr) {
        cout << node->data << " ";
    }

    printLeaves(node->right);
}
void printLeftBoundary(Node* node) {
    if (node == nullptr) {
        return;
    }

    if (node->left != nullptr) {
        std::cout << node->data << " ";
        printLeftBoundary(node->left);
    } else if (node->right != nullptr) {
        std::cout << node->data << " ";
        printLeftBoundary(node->right);
    }
}
void printRightBoundary(Node* node) {
    if (node == nullptr) {
        return;
    }

    if (node->right != nullptr) {
        printRightBoundary(node->right);
        std::cout << node->data << " ";
    } else if (node->left != nullptr) {
        printRightBoundary(node->left);
        std::cout << node->data << " ";
    }
}
void printTreeBorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::cout << root->data << " ";

    printLeftBoundary(root->left);

    printLeaves(root->left);
    printLeaves(root->right);

    printRightBoundary(root->right);

    std::cout << std::endl;
}


Node* findMinNode(Node* node) {
    if (node == nullptr) 
        return nullptr;
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}
Node* findSuccessor(Node* root, int value) {
    Node* node = findNode(root, value);
    if (node == nullptr)
        return nullptr; // Node not found
    if (node->right != nullptr) 
        return findMinNode(node->right);
    else {
        Node* successor = nullptr;
        Node* current = root;
        while (current != nullptr) {
            if (value < current->data) {
                successor = current;
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return successor;
    }
}

void InOrder(Node* node) {
    if (node != nullptr) {
        InOrder(node->left);
        cout << node->data << " ";
        InOrder(node->right);
    }
}

void PreOrder(Node* node){
    if (node != nullptr) {
        cout << node->data << " ";
        InOrder(node->left);
        InOrder(node->right);
    }
}

void PostOrder(Node* node){
    if (node != nullptr) {
        InOrder(node->left);
        InOrder(node->right);
        cout << node->data << " ";
    }
}

void zigzagTraversal(Node* root) {
    if (root == nullptr)
        return;
    stack<Node*> currentLevel; // Stack for nodes at the current level
    stack<Node*> nextLevel;    // Stack for nodes at the next level
    bool leftToRight = true; // Flag to track the order of traversal
    currentLevel.push(root); // Start with the root node
    while (!currentLevel.empty()) {
        Node* node = currentLevel.top(); // Get the top node from the current level
        currentLevel.pop();              // Pop the node from the stack
        if (node != nullptr) {
            cout << node->data << " ";
            if (leftToRight) {
                if (node->left)
                    nextLevel.push(node->left);

                if (node->right)
                    nextLevel.push(node->right);
            } 
            else {
                if (node->right)
                    nextLevel.push(node->right);
                if (node->left)
                    nextLevel.push(node->left);
            }
        }
        if (currentLevel.empty()) {
            cout << endl;
            swap(currentLevel, nextLevel);
            leftToRight = !leftToRight;
        }
    }
}
 
 int height(Node* node) {
    if (node == nullptr)
        return 0;
    return max(height(node->left), height(node->right)) + 1;
}

int diameter(Node* root) {
    if (root == nullptr)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    return max({leftDiameter, rightDiameter, leftHeight + rightHeight + 1});
}

int main() {
    Node* root = nullptr;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);
    root = insert(root, 10);
    root = insert(root, 9);
    root = insert(root, 1);

    cout << "In-order traversal: ";
    InOrder(root);
    cout << endl;
    cout << "Pre-order traversal: ";
    PreOrder(root);
    cout << endl;
    cout << "Post-order traversal: ";
    PostOrder(root);
    cout << endl;
    cout<<"Hight is: "<<getHeight(root);
    cout << endl;
    Node* a = Predecessor(root,5);
    Node* successor = findSuccessor(root,5);
    cout<<"Predecessor is: "<<a->data;
    cout<<"Successor is: "<<successor->data;
    cout<<endl;
    cout<<"Boundry is: ";printTreeBorder(root);
    cout<<"Zig-Zag : "<<endl;
    zigzagTraversal(root);
    cout<<"Zig-Zag : "<<endl;
    zigzagTraversal(root);
    int treeDiameter = diameter(root);
    cout<<"Diameter is: "<<treeDiameter;

    
    return 0;
}
