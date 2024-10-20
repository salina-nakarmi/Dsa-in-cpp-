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
 void insertafter(Node* head,int key, int newdata){
    while(head->next!=NULL){
        head=head->next;
        if(head->data==key){
            Node* newnode = new Node(newdata);
            newnode->next=head->next;
            head->next=newnode;
            
}
    }
 }

int main(){
    Node* head= new Node(1);
    head->next =new Node(2);
    head->next->next =new Node(4);
    head->next->next->next =new Node(5);
    head->next->next->next->next =new Node(6);
    display(head);
    //insert 3 after 2;
    insertafter(head,2,3);
    display(head);


    return 0;
}