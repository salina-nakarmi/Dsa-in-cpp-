#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;
    Node(int newdata) {
        data = newdata;
        next = prev = nullptr;
    }
};

// Function to print the list
void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << "\t";
        head = head->next;
    }
    cout << endl;
}

// Function to delete a node at a specific position
Node* deletion_position(Node* head, int pos) {
    if (head == nullptr)
        return head; // If the list is empty

    Node* curr = head;
    // Traverse to the node at the given position
    for (int i = 1; i < pos && curr != nullptr; i++) {
        curr = curr->next;
    }

    // If the position is invalid
    if (curr == nullptr) {
        cout << "Position not found" << endl;
        return head;
    }

    // If we're deleting the head node
    if (curr == head) {
        head = curr->next; // Move the head to the next node
        if (head != nullptr) {
            head->prev = nullptr; // If there's a next node, set its prev to null
        }
        delete curr;
        return head;
    }

    // If we're deleting any node other than the head
    if (curr->next != nullptr) { // If the node to delete is not the last node
        curr->next->prev = curr->prev;
    }
    curr->prev->next = curr->next;

    delete curr; // Free the memory of the deleted node
    return head;
}

int main() {
    // Creating the list: 1 <-> 2 <-> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    // Print before deletion
    cout << "Before deletion:" << endl;
    print(head);

    // Perform deletion at position 2 (the second node, value 2)
    head = deletion_position(head, 2);

    // Print after deletion
    cout << "After deletion at position 2:" << endl;
    print(head);

    return 0;
}
