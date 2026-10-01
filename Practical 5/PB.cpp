#include <iostream>
#include <string>

struct Node {
    std::string name;
    Node* next;
    Node* prev;
    Node(std::string val) : name(val), next(nullptr), prev(nullptr) {}
};

class SinglyCircularList {
    Node* head = nullptr;
public:
    void join(std::string name, std::string afterName = "") {
        Node* newNode = new Node(name);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* curr = head;
        if (!afterName.empty()) {
            do {
                if (curr->name == afterName) break;
                curr = curr->next;
            } while (curr != head);
        } else {
            while (curr->next != head) curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void leave(std::string name) {
        if (!head) return;
        Node* curr = head;
        Node* prev = nullptr;
        do {
            if (curr->name == name) break;
            prev = curr;
            curr = curr->next;
        } while (curr != head);
        if (curr->name != name) return;
        if (curr->next == curr) {
            delete curr;
            head = nullptr;
            return;
        }
        if (curr == head) {
            Node* tail = head;
            while (tail->next != head) tail = tail->next;
            head = head->next;
            tail->next = head;
        } else {
            prev->next = curr->next;
        }
        delete curr;
    }

    void display() {
        if (!head) { std::cout << "Empty\n"; return; }
        Node* curr = head;
        do {
            std::cout << curr->name << " ";
            curr = curr->next;
        } while (curr != head);
        std::cout << "\n";
    }
};

class DoublyCircularList {
    Node* head = nullptr;
public:
    void join(std::string name, std::string afterName = "") {
        Node* newNode = new Node(name);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }
        Node* curr = head;
        if (!afterName.empty()) {
            do {
                if (curr->name == afterName) break;
                curr = curr->next;
            } while (curr != head);
        } else {
            curr = head->prev;
        }
        newNode->next = curr->next;
        newNode->prev = curr;
        curr->next->prev = newNode;
        curr->next = newNode;
    }

    void leave(std::string name) {
        if (!head) return;
        Node* curr = head;
        do {
            if (curr->name == name) break;
            curr = curr->next;
        } while (curr != head);
        if (curr->name != name) return;
        if (curr->next == curr) {
            delete curr;
            head = nullptr;
            return;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        if (curr == head) head = curr->next;
        delete curr;
    }

    void display() {
        if (!head) { std::cout << "Empty\n"; return; }
        Node* curr = head;
        do {
            std::cout << curr->name << " ";
            curr = curr->next;
        } while (curr != head);
        std::cout << "\n";
    }
};

int main() {
    SinglyCircularList scll;
    DoublyCircularList dcll;
    
    std::cout << "--- Singly Circular List ---\n";
    scll.join("Alice"); scll.display();
    scll.join("Bob"); scll.display();
    scll.join("Charlie", "Alice"); scll.display();
    scll.leave("Alice"); scll.display();
    scll.leave("Bob"); scll.display();
    scll.leave("Charlie"); scll.display();

    std::cout << "\n--- Doubly Circular List ---\n";
    dcll.join("Alice"); dcll.display();
    dcll.join("Bob"); dcll.display();
    dcll.join("Charlie", "Alice"); dcll.display();
    dcll.leave("Alice"); dcll.display();
    dcll.leave("Bob"); dcll.display();
    dcll.leave("Charlie"); dcll.display();
    return 0;
}
