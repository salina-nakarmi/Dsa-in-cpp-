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

Node* insertion_position(Node* head, int pos, int newdata){
    Node* newnode = new Node(newdata);
    if(pos==1){
        newnode->next = head;
        head->prev = newnode;
        newnode->prev = nullptr;
        return newnode;
    }
    int position = 1;

    Node* curr = head;
    while(curr!=nullptr){
        if(pos==position)
        break;
        curr = curr->next;   //the pointer of the node before which we have to insert the new node
        position+=1;
       }

       if(curr==nullptr){
        cout<<"the position doesn't exist in the linked list"<<endl;
        return head;
       }
       
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
    //after inserting 2 at second position;
    head = insertion_position(head, 2, 2);
    print(head);
    return 0;
}