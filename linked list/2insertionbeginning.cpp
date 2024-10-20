#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int newdata){
        data = newdata;
        next = NULL;
    }
};
void print(Node* ptr){
        while(ptr!=NULL){
            cout<<ptr->data<<"\t";
            ptr=ptr->next;
        }
        cout<<endl;
    }
    Node* insertAtFront(Node* head, int newdata){
        Node* newnode = new Node(newdata);
        newnode->next = head;
        return newnode;
    }
int main(){
      // Create the nodes in the linked list
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next= new Node(5);
    head->next->next->next->next=NULL;
    print(head);
    int newdata =1;
    head = insertAtFront(head,newdata);
    print(head);
    int nextnewdata =0;
    head = insertAtFront(head,nextnewdata);
    print(head);
    return 0;
}