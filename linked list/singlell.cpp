// Singly linked list node in C++
class Node {
public:
  
    // Data field
    int data;
  
    // Pointer to the next node
    Node* next;

    // Constructor to initialize a new node with data
    Node(int new_data) {
        this->data = new_data;
        this->next = nullptr;
    }
};
