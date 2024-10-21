#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

Node* reverseDll(Node* head) {
    Node* temp = head;
    Node* previous = nullptr;

    while (temp != nullptr) {
        // Swap prev and next pointers
       Node* newNode = temp->next;
       temp->next = previous;
       temp->prev = newNode;
       previous = temp;
       temp = newNode;
    }

    // After the loop, prev will be the new head of the reversed list

    return previous;
}
Node* insertDll(vector<int>& a) {
    Node* head = nullptr;
    Node* mover = nullptr;
    for (int i = 0; i < a.size(); i++) {
        Node* temp = new Node(a[i]);
        if (i == 0) {
            head = temp;
            mover = head;
        } else {
            mover->next = temp;
            temp->prev = mover;
            mover = temp;
        }
    }
    return head;
}

Node* deleteDll(Node* head, int pos) {
    if (!head) return nullptr;

    Node* temp = head;
    int i = 1;
    while (temp != nullptr && i < pos) {
        temp = temp->next;
        i++;
    }

    if (temp == nullptr) return head; // Position out of bounds

    if (temp->prev) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next; // Update head if deleting the first node
    }

    if (temp->next) {
        temp->next->prev = temp->prev;
    }

    delete temp;
    return head;
}

void print(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    vector<int> a = {11, 12, 13, 14, 15, 16, 17, 18};
    Node* head = insertDll(a);
    cout << "Insertion Elements are: ";
    print(head);

    cout << "Deletion Elements are: ";
    head = deleteDll(head, 3);
    print(head);

    cout << "Reversed Elements are: ";
    head = reverseDll(head);
    print(head);

    return 0;
}
