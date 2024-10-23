#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next, *prev;
    Node(int newdata){
        data = newdata;
        next = prev = nullptr;
    }
};
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<"\t";
        head = head->next;
    }
    cout<<endl;
}

Node* insertion_after(Node* head, int keydata, int newdata){
    
    Node* curr = head;
    while(curr!=nullptr){
        if(curr->data == keydata)
        break;
        curr = curr->next;   //gives us the data after which we have to insert a node;
       }

       if(curr==nullptr){
        cout<<"the key data not found:"<<"\t"<<"try again"<<endl;
        return head;
       }
       

       // Create a new node
    Node* newnode = new Node(newdata); 
    newnode->prev = curr; // Set the new node's prev to the current node
    newnode->next = curr->next; // Set new node's next to the current's next

    if (curr->next != nullptr) { // If current node is not the last node
        curr->next->prev = newnode; // Adjust the next node's prev to the new node
    }
    curr->next = newnode; // Link the current node to the new node

    return head; // Return the head of the list
}

int main(){
    Node* head = new Node(1);
    head -> next = new Node(2);
    head ->prev = nullptr;
    head ->next ->prev = head;
    //print before insertion
    print(head);
    //after inserting 3 after 2;
    head = insertion_after(head, 2, 3);
    print(head);
    return 0;
}