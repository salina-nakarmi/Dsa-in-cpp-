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

Node* insertion_at_front(Node* head, int data){
    Node* newnode = new Node(data); 
    head ->prev= newnode;
    newnode -> next = head;
    newnode ->prev = NULL;
    return newnode;
}
int main(){
    Node* head = new Node(1);
    head -> next = new Node(2);
    head ->prev = nullptr;
    head ->next ->prev = head;
    //print before insertion
    print(head);
    //after the opertaion performed
    head = insertion_at_front(head, 0);
    print(head);
    return 0;
}