#if __has_include(<bits/stdc++.h>)
#include <bits/stdc++.h>
#else
#include <iostream>
#include <string>
#endif
using namespace std;

struct Node {
    string title;
    Node* prev;
    Node* next;
    Node(string val) : title(val), prev(nullptr), next(nullptr) {}
};

class Playlist {
private:
    Node *head = nullptr, *tail = nullptr;
    int count = 0;

public:
    ~Playlist() {
        while (head) {
            Node* temp = head;
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr;
            delete temp;
        }
        count = 0;
    }

    void display() {
        cout << "Playlist (" << count << "): ";
        for (Node* curr = head; curr; curr = curr->next)
            cout << "[" << curr->title << "]" << (curr->next ? " <-> " : "");
        cout << "\n";
    }

    void addFront(string title) {
        Node* n = new Node(title);
        if (!head) head = tail = n;
        else { n->next = head; head->prev = n; head = n; }
        count++;
        display();
    }

    void addEnd(string title) {
        Node* n = new Node(title);
        if (!tail) head = tail = n;
        else { tail->next = n; n->prev = tail; tail = n; }
        count++;
        display();
    }

    void insertAfter(string target, string title) {
        Node* curr = head;
        while (curr && curr->title != target) curr = curr->next;
        if (!curr) { cout << "'" << target << "' not found.\n"; display(); return; }
        Node* n = new Node(title);
        n->next = curr->next;
        n->prev = curr;
        if (curr->next) curr->next->prev = n;
        else tail = n;
        curr->next = n;
        count++;
        display();
    }

    void removeFront() {
        if (!head) { display(); return; }
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        count--;
        display();
    }
};

int main() {
    Playlist pl;
    pl.addEnd("Song B");
    pl.addFront("Song A");
    pl.insertAfter("Song B", "Song C");
    pl.insertAfter("Song X", "Song Y");
    pl.removeFront();
    return 0;
}
