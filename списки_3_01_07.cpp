#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


class Node {
public:
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};


class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() : head(nullptr) {}


    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }


    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "None" << endl;
    }


    void sortList() {
        if (!head || !head->next) return;

        head = mergeSort(head);
    }

    void removeDuplicates() {
        Node* current = head;
        while (current && current->next) {
            if (current->value == current->next->value) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            else {
                current = current->next;
            }
        }
    }

private:
    Node* mergeSort(Node* head) {
        if (!head || !head->next) return head;

        Node* middle = getMiddle(head);
        Node* nextToMiddle = middle->next;
        middle->next = nullptr;

        Node* left = mergeSort(head);
        Node* right = mergeSort(nextToMiddle);

        return merge(left, right);
    }

    Node* getMiddle(Node* head) {
        if (!head) return head;

        Node* slow = head;
        Node* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }


    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;

        if (left->value < right->value) {
            left->next = merge(left->next, right);
            return left;
        }
        else {
            right->next = merge(left, right->next);
            return right;
        }
    }
};

void generateRandomList(SinglyLinkedList& list, int n) {
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        list.append(rand() % 10 + 1); 
    }
}

int main() {
    int n;
    cout << "enter length: ";
    cin >> n;

    SinglyLinkedList list;

    generateRandomList(list, n);
    list.sortList();
    cout << "list in the beginning:" << endl;
    list.printList();

    list.removeDuplicates();
    cout << "list after deleting duplicates:" << endl;
    list.printList();

    return 0;
}
