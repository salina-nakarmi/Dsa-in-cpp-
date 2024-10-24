#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int newdata) {
        data = newdata;
        next = nullptr;
    }
};

// Function to print the elements of a circular linked list
void print(Node* first) {
    if (first == nullptr) { // Check if the list is empty
        cout << "The list is empty" << endl;
        return;
    }

    Node* temp = first;
    do {
        cout << temp->data << "\t";
        temp = temp->next;
    } while (temp != first); // Loop until we come back to the first node
    cout << endl;
}

int main() {
    // Creating a circular linked list with 3 nodes: 1 -> 2 -> 3 -> 1
    Node* first = new Node(1);
    first->next = new Node(2);
    first->next->next = new Node(3);
    first->next->next->next = first; // Link the last node to the first to make it circular

    // Display the list
    print(first);

    return 0;
}
