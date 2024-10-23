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
        curr = curr->next;   //the pointer of the node before which we have to insert the new node
       }

       if(curr==nullptr){
        cout<<"the key data not found:"<<"\t"<<"try again"<<endl;
        return head;
       }
       

       // Create a new node
    Node* newnode = new Node(newdata); 
    newnode->prev = curr->prev; 
    newnode->next = curr; 
    //curr->prev=newnode;    //not here because it will update the curr->prev link before we use it to link to newnode
    if (curr->prev != nullptr) { // If current node is not the first node
        curr->prev->next = newnode;
    }
    else {
      
        // If the current node is the head, update the head
        head = newnode;
    }
    curr->prev=newnode; // Update prev of given node to new node

    return head; // Return the head of the list
}

int main(){
    Node* head = new Node(1);
    head -> next = new Node(3);
    head ->prev = nullptr;
    head ->next ->prev = head;
    //print before insertion
    print(head);
    //after inserting 2 before 3;
    head = insertion_after(head, 3, 2);
    print(head);
    return 0;
}