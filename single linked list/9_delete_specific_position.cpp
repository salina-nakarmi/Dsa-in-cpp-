//deleting a specific position in the list
#include<iostream>
using namespace std;
struct Node{
    int data; 
    Node* next;
    Node(int newdata){
        data = newdata;
        next = nullptr;
    }
};
void print(Node* ptr){
    while(ptr!=nullptr){
        cout<<ptr->data<<"\t";
        ptr = ptr->next;
    }
    cout<<endl;
}
Node* delete_position(Node* head, int pos){
      if (head == nullptr || pos < 1) {  // Handle edge cases (empty list or invalid position)
        return head;
    }

     // If the head is to be deleted
    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
      // Traverse to the node just before the position to be deleted
    Node* curr = head;
    for (int i = 1; curr != nullptr && i < pos - 1; i++) {
        curr = curr->next;
    }

    // If the position is invalid or out of bounds
    if (curr == nullptr || curr->next == nullptr) {
        return head;
    }

    // Delete the node at the given position
    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;

    return head;
/*    // Case 2: Node to be deleted is in middle
    // Traverse till given position
    for (int i = 1; i != position; i++) {
        prev = temp;
        temp = temp->next;
    }

    // If given position is found, delete node
    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }
    // If given position is not present
    else {
        cout << "Data not present\n";
    }

    return head;
}
*/
}
int main(){
    Node* head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = NULL;
     print(head);
    //to delete data of the 4rd node;
    head = delete_position(head,4);
    print(head);
    return 0;
}