#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

Node* insertLL(vector<int>&a){
    Node* head;
    Node* mover;
    for(int i = 0; i<a.size(); i++){
        Node* temp = new Node(a[i]);

        if(i==0){
            head = temp;
            mover = head;
        }
        else{
            mover->next = temp;
            mover = temp;

        }
    }
    return head;
}

Node* reverseLL(Node* head){

    Node* temp = head;
    Node* prev = nullptr;

    while(temp!=NULL){
        Node* newNode = temp->next;
        temp->next = prev;
        prev = temp;
        temp = newNode;
    }

    return prev;
}

Node* recursiveRev(Node* head){
    if(head== nullptr or head->next == nullptr)
    return head;

    Node* newHead = recursiveRev(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;
}
void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void middle(Node* head){
    Node* fast = head;
    Node* slow = head;

    while(fast && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    cout<<"\n middle: "<<slow->data;


}
int main(){
    vector<int>a = {10,20,30,40,50,60};
    Node* val = insertLL(a);
    print(val);

    middle(val);
    cout<<"\nReversed Order is : ";
    Node* var = recursiveRev(val);
    print(var);
}