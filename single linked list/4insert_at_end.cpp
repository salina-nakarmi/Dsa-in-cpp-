#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int new_data) {
        data = new_data;
        next = nullptr; 
    }
};
 void display(Node* ptr){
    while(ptr!=NULL){
    cout<<ptr->data<<"\t";
    ptr=ptr->next;
    }
    cout<<endl;
 }
void insertafter(Node* head,int newdata){
    // Store the head reference in a temporary variable
   // Node* curr = head;            //no need 
    while(head->next!=NULL){
        head=head->next;
    }
                head->next=new Node(newdata);
  
        }

int main(){
    Node* head= new Node(1);
    head->next =new Node(2);
    head->next->next =new Node(3);
    head->next->next->next =new Node(4);
    head->next->next->next->next =new Node(5);
    //befor insertion
    display(head);
    //insert 3 after 2;
    insertafter(head,6);
    //after insertion
    display(head);


    return 0;
}