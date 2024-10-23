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

Node* insertion_end(Node* head,int newdata){
    Node* newnode = new Node(newdata);
    Node* curr = head;
    while(curr->next!=nullptr){
        curr = curr->next;   //reaches to last node;
       }
       
    newnode->prev = curr; 
    newnode->next = curr->next;
    curr->next = newnode;
    

    return head; // Return the head of the list
}

int main(){
    Node* head = new Node(1);
    head->next =new Node(2);
    head -> next->next = new Node(3);
    head ->prev = nullptr;
    head->next->prev=head;
    head->next->next->prev= head->prev;

    head ->next ->prev = head;
    //print before insertion
    print(head);
    //after inserting 4 at the end;
    head = insertion_end(head,4);
    print(head);
    return 0;
}