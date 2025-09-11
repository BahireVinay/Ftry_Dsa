#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function prototypes
void insertNode(Node*& head, int value);
void deleteNode(Node*& head, int value);
int findLength(Node* head);
bool searchElement(Node* head, int value);
void displayList(Node* head);

int main() {
    Node* head = nullptr;
    int choice, value;

    while (true) {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Insert a node\n";
        cout << "2. Delete a node\n";
        cout << "3. Find length of the linked list\n";
        cout << "4. Search an element\n";
        cout << "5. Display list\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertNode(head, value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(head, value);
                break;
            case 3:
                cout << "Length of the list: " << findLength(head) << endl;
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                if (searchElement(head, value))
                    cout << "Element found!\n";
                else
                    cout << "Element not found.\n";
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}

// Insert node at the end
void insertNode(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
    cout << "Node inserted.\n";
}

// Delete node by value
void deleteNode(Node*& head, int value) {
    Node *temp = head, *prev = nullptr;
    while (temp && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        cout << "Value not found.\n";
        return;
    }
    if (!prev) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    delete temp;
    cout << "Node deleted.\n";
}

// Find length of the list
int findLength(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// Search for an element
bool searchElement(Node* head, int value) {
    while (head) {
        if (head->data == value)
            return true;
        head = head->next;
    }
    return false;
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