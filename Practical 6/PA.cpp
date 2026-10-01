#include <iostream>
#include <vector>
#include <string>

class TrayStack {
private:
    int n;
    int top_index;
    std::vector<int> stack;

    void print_top() {
        if (top_index == -1) {
            std::cout << "Stack is empty\n";
        } else {
            std::cout << "Top tray: " << stack[top_index] << "\n";
        }
    }

public:
    TrayStack(int capacity) : n(capacity), top_index(-1), stack(capacity) {}

    void place(int tray_id) {
        if (top_index == n - 1) {
            std::cout << "Error: Cannot place tray. Counter is full.\n";
            return;
        }
        stack[++top_index] = tray_id;
        print_top();
    }

    void take() {
        if (top_index == -1) {
            std::cout << "Error: Cannot take tray. Counter is empty.\n";
            return;
        }
        top_index--;
        print_top();
    }
};

int main() {
    TrayStack counter(3);

    counter.place(101);
    counter.place(102);
    counter.place(103);
    counter.place(104); 
    counter.take();
    counter.take();
    counter.take();
    counter.take(); 

    return 0;
}
