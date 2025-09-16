#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

// Insert at the beginning
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr, head};
    if (head) head->prev = newNode;
    head = newNode;
}

// Insert at the end
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at a specific position (1-based index)
void insertAtPosition(Node*& head, int value, int position) {
    if (position <= 1) {
        insertAtBeginning(head, value);
        return;
    }
    Node* temp = head;
    for (int i = 1; temp && i < position - 1; ++i)
        temp = temp->next;
    if (!temp) {
        cout << "Position out of bounds. Inserting at end.\n";
        insertAtEnd(head, value);
        return;
    }
    Node* newNode = new Node{value, temp, temp->next};
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete from the beginning
void deleteFromBeginning(Node*& head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    delete temp;
}

// Delete from the end
void deleteFromEnd(Node*& head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->prev->next = nullptr;
    delete temp;
}

// Delete from a specific position (1-based index)
void deleteFromPosition(Node*& head, int position) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (position <= 1) {
        deleteFromBeginning(head);
        return;
    }
    Node* temp = head;
    for (int i = 1; temp && i < position; ++i)
        temp = temp->next;
    if (!temp) {
        cout << "Position out of bounds.\n";
        return;
    }
    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    delete temp;
}

// Display the list forward
void displayForward(Node* head) {
    cout << "Doubly Linked List (forward): ";
    while (head) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Display the list backward
void displayBackward(Node* head) {
    if (!head) {
        cout << "Doubly Linked List (backward): NULL\n";
        return;
    }
    // Go to the last node
    while (head->next)
        head = head->next;
    cout << "Doubly Linked List (backward): ";
    while (head) {
        cout << head->data << " <-> ";
        head = head->prev;
    }
    cout << "NULL\n";
}

// Example usage for beginners
int main() {
    Node* head = nullptr;
    insertAtBeginning(head, 10); // 10
    insertAtEnd(head, 20);       // 10 <-> 20
    insertAtPosition(head, 15, 2); // 10 <-> 15 <-> 20
    displayForward(head);
    displayBackward(head);

    deleteFromBeginning(head);   // 15 <-> 20
    displayForward(head);

    deleteFromEnd(head);         // 15
    displayForward(head);

    insertAtEnd(head, 25);       // 15 <-> 25
    insertAtEnd(head, 30);       // 15 <-> 25 <-> 30
    insertAtPosition(head, 22, 2); // 15 <-> 22 <-> 25 <-> 30
    displayForward(head);

    deleteFromPosition(head, 3); // 15 <-> 22 <-> 30
    displayForward(head);

    displayBackward(head);

    return 0;
}