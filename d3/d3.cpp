#include <iostream>
using namespace std;

//the following code is for basic operations on singly linked list 
// Node structure
struct Node {
    int data;
    Node* next;
};

// Insert at the beginning
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

// Insert at the end
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
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
    Node* newNode = new Node{value, temp->next};
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
    while (temp->next && temp->next->next)
        temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
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
    for (int i = 1; temp->next && i < position - 1; ++i)
        temp = temp->next;
    if (!temp->next) {
        cout << "Position out of bounds.\n";
        return;
    }
    Node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
}

// Display the list
void displayList(Node* head) {
    cout << "Linked List: ";
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Example usage for beginners
int main() {
    Node* head = nullptr;
    insertAtBeginning(head, 10); // 10
    insertAtEnd(head, 20);       // 10 -> 20
    insertAtPosition(head, 15, 2); // 10 -> 15 -> 20
    displayList(head);

    deleteFromBeginning(head);   // 15 -> 20
    displayList(head);

    deleteFromEnd(head);         // 15
    displayList(head);

    insertAtEnd(head, 25);       // 15 -> 25
    insertAtEnd(head, 30);       // 15 -> 25 -> 30
    insertAtPosition(head, 22, 2); // 15 -> 22 -> 25 -> 30
    displayList(head);

    deleteFromPosition(head, 3); // 15 -> 22 -> 30
    displayList(head);