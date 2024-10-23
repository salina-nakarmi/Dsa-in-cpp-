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

Node* deletion_front(Node* head){ 
    if(head==nullptr)
    return head;
    Node* curr =head;
    curr= curr->next;
    curr->prev = nullptr;
    delete(head);
    return curr;
    /* //Node* curr =head;
    head= head->next;
    head->prev = nullptr;
    return head;*/
}
int main(){
    Node* head = new Node(1);
    head -> next = new Node(2);
    head ->prev = nullptr;
    head ->next ->prev = head;
    //print before deletion
    print(head);
    //after the opertaion performed
    head = deletion_front(head);
    print(head);
    return 0;
}