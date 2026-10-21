#include <iostream>
#include <vector>
#include <string>

class TokenCounter {
private:
    std::vector<std::string> queue;
    int cap;
    int start;
    int rear;
    int size;

    void print_start() {
        if (size == 0) {
            std::cout << "Current start token: None\n";
        } else {
            std::cout << "Current start token: " << queue[start] << "\n";
        }
    }

public:
    TokenCounter(int n) {
        cap = n;
        queue.resize(n);
        start = 0;
        rear = 0;
        size = 0;
    }

    void join(std::string token_id) {
        if (size == cap) {
            std::cout << "Error: Counter is full.\n";
            return;
        }
        queue[rear] = token_id;
        rear = (rear + 1) % cap;
        size++;
        print_start();
    }

    void serve() {
        if (size == 0) {
            std::cout << "Error: Counter is empty.\n";
            return;
        }
        start = (start + 1) % cap;
        size--;
        print_start();
    }
};

int main() {
    TokenCounter counter(3);
    counter.join("T1");
    counter.join("T2");
    counter.serve();
    counter.join("T3");
    counter.join("T4");
    counter.join("T5");
    return 0;
}
