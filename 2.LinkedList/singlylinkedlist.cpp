#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
     Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

Node* head = NULL;

void print(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << "\n\n";
}

void insertLinkedList(vector<int>& a) {
    Node* mover = nullptr;
    for (int i = 0; i < a.size(); i++) {
        if (i == 0) {
            head = new Node(a[i]);
            mover = head;
        } else {
            Node* temp = new Node(a[i]);
            mover->next = temp;
            mover = temp;
        }
    }
    print(head);
}

void deleteFirst() {
    if (head == NULL)
        return;

    Node* temp = head;
    head = head->next;
    delete temp;
    print(head);
}
void deleteLast(){
    if(head==NULL)
    return;

    Node *temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    delete(temp->next);
    print(head);
}

void deleteAny(int pos){

    if(pos==1){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    else{
        int count = 0;
        Node *temp = head, *prev = NULL;

        while(temp->next!=NULL){
            count++;
            if(count==pos){
                prev->next = temp->next;
                delete temp;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    print(head);
}

void insertHead(int val){
    Node* temp = new Node(val, head);
    head = temp;
    print(head);
}

Node* ReverseLL(Node* head){
    Node* temp = head;
    Node* prev = NULL;

    while(temp!=NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    cout<<"\n"<<"Reversed Order is: ";
    return prev;

}
void insertLast(int val){

    if(head==NULL)
    head = new Node(val);
    else{
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        Node* last = new Node(val);
        temp->next = last;
    }
    print(head);
}
void insertAny(int pos,int num){
    if(head==NULL)
   cout<<"NULL";
    if(pos==1)
     head = new Node(num,head);


     else{
        int count =0;
        Node* temp = head;
        while(temp->next!=NULL){
            count++;
            if(count==pos-1){
                Node* newNode = new Node(num);
                newNode->next = temp->next;
                temp->next = newNode;
            }
            temp = temp->next;
        }

     }
     print(head);
}
int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Insertion from the array
    cout<<"Insertion: ";
    insertLinkedList(a);

 /*
    // Delete the first node
    cout<<"Deleting First: ";
    deleteFirst();

    cout<<"Deleting Last: ";
    deleteLast();

  cout<<"Deleting Any: ";
   deleteAny(5);
*/ 

insertHead(100);

insertLast(1000);
insertAny(1,20);

Node* rev = ReverseLL(head);
print(rev);
    return 0;
}
