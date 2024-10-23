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
Node* insertbefore(Node* head,int key, int newdata){
    //no data
    while(head==nullptr){
        return NULL;
    }
    //if the key is at the beginning
    while(head->data==key){
        Node* newnode = new Node(newdata);
        newnode->next = head;
        return newnode;
    }
    //initialize current and previous pointer
    
    Node* curr = head;
    Node* prev = nullptr;

    while(curr!=nullptr && curr->data!=key ){
        prev = curr;
        curr = curr->next;
    }

    while(curr!=nullptr){
        Node* newnode = new Node(newdata);
        prev->next = newnode;
        newnode -> next = curr;
        return head;
    }

//     while(head->next!=NULL){
        
//         if(head->data==key){
//             Node* newnode = new Node(newdata);
//             newnode->next=head;
//             head=newnode;
            
            
            
// }
// head=head->next;
//     }
 }

int main(){
    Node* head= new Node(1);
    head->next =new Node(2);
    head->next->next =new Node(4);
    head->next->next->next =new Node(5);
    head->next->next->next->next =new Node(6);
    display(head);
    //insert 3 before 4;
    head = insertbefore(head,4,3);
    display(head);


    return 0;
}