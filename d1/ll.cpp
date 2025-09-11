#include <iostream>

class Node {
public:
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
public:
        LinkedList() {
        head = nullptr;
    }

    // Insert at end
    void insert(int val) {
        Node* newNode = new Node{val, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    // Display list
    void display() const {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    LinkedList ll;
    ll.insert(1);
    // ll.insert(2);
    // ll.insert(3);
    ll.display();
    return 0;
}