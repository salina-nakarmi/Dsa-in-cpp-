#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    void traversal(Node* ptr){
        while(ptr!=NULL){
            cout<<ptr->data<<"\t";
            ptr=ptr->next;
        }
    }

};
int main(){
      // Create the nodes in the linked list
    Node* head = new Node();
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();
    head->data=1;
    head->next=first;
    first->data= 8;
    first -> next = second;
    second->data = 2;
    second -> next= third;
    third->data = 7;
    third -> next= NULL;
    head->traversal(head);
    return 0;
}
  // Create the linked list 2->3->4->5
   /*
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);*/ 

    //this should be included in the class 
    /*   Node(int new_data) {
        data = new_data;
        next = nullptr; 
    }*/