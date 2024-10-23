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
Node* insertbefore(Node* head,int position, int newdata){
    //when position is 1
    while(position==1){
        Node* newnode = new Node(newdata);
        newnode->next = head;
        return newnode;
    }

    Node* curr = head;
    for(int i=1; i<position-1 && curr!=nullptr ; i++ ){
curr=curr->next;//position - 1  so that  we can effeciently use insert after the node code
    }
    if(curr==nullptr){
        cout<<"not enough node before it to reach that position"<<endl;
        return head;
    }
      
    if(curr!=nullptr){
        Node* newnode = new Node(newdata);
        newnode->next = curr ->next;
        curr -> next = newnode;
        return head;

       
    }
    

 }

int main(){
    Node* head= new Node(1);
    head->next =new Node(2);
    head->next->next =new Node(4);
    head->next->next->next =new Node(5);
    head->next->next->next->next =new Node(6);
    display(head);
    //insert 3 at 3rd position;
    head = insertbefore(head,3,3);
    display(head);


    return 0;
}