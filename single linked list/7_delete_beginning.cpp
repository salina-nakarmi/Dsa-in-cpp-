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
    Node* deleteAtFront(Node* head, int deletedata){
         // Base case if linked list is empty
    if (head == nullptr)
        return nullptr;
        head = head->next;
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
    int deletedata =0;
    head = deleteAtFront(head,deletedata);
    //after deletion
    print(head);
   
    return 0;
}