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
    Node* deleteAtEnd(Node* head){
         // Base case if linked list is empty
    if (head == nullptr)
        return nullptr;
        Node* curr = head;
        while(curr->next->next!=nullptr){ //by this we traverse upto secondlast node
            curr = curr->next;
        }
        delete(curr->next);
        curr->next =nullptr;
        return head;
    }
int main(){
      // Create the nodes in the linked list
    Node* head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next= new Node(3);
    head->next->next->next->next=NULL;
    //before deletion
    print(head);
    //delete last node
    head = deleteAtEnd(head);
    //after deletion
    print(head);
   
    return 0;
}