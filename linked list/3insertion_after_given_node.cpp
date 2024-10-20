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

int main(){
    Node* head= new Node(1);
    head->next =new Node(2);
    head->next->next =new Node(4);
    head->next->next->next =new Node(5);
    head->next->next->next->next =new Node(6);
    display(head);
    //insert 3 after 2;
    insertafter()


    return 0;
}