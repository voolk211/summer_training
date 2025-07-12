#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* topNode;

public:
    Stack() : topNode(nullptr) {}
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (topNode) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    int top() const {
        if (topNode) return topNode->data;
        throw runtime_error("Stack is empty");
    }

    bool empty() const {
        return topNode == nullptr;
    }

    void print() const {
        Node* temp = topNode;
        cout << "Stack from top to bottom: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


void sortStack(Stack& original) {
    Stack tempStack;

    while (!original.empty()) {
        int current = original.top();
        original.pop();
        while (!tempStack.empty() && tempStack.top() > current) {
            original.push(tempStack.top());
            tempStack.pop();
        }
        tempStack.push(current);}

    while (!tempStack.empty()) {
        original.push(tempStack.top());
        tempStack.pop();}
}

int main() {
    srand(time(0));
    int n;
    cout << "length of stack: ";
    cin >> n;
    Stack stack;
    for (int i = 0; i < n; ++i) {
        int num = rand() % 100;
        stack.push(num);
    }
    cout << endl;

    cout << "stack before sorting:" << endl;
    stack.print();
    sortStack(stack);
    cout << "stack after sorting:" << endl;
    stack.print();
    return 0;
}
