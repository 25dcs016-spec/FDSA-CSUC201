#include <iostream>
#include <queue>
#include <string>

class PatientQueue {
private:
    std::queue<std::string> q;

    void print_start() {
        if (q.empty()) {
            std::cout << "Current start patient: None\n";
        } else {
            std::cout << "Current start patient: " << q.front() << "\n";
        }
    }

public:
    void arrive(std::string patient_name) {
        q.push(patient_name);
        print_start();
    }

    void attend() {
        if (q.empty()) {
            std::cout << "Error: No patients to attend.\n";
            return;
        }
        q.pop();
        print_start();
    }
};

int main() {
    PatientQueue hospitalQueue;
    hospitalQueue.arrive("Alice");
    hospitalQueue.arrive("Bob");
    hospitalQueue.attend();
    hospitalQueue.arrive("Charlie");
    hospitalQueue.attend();
    hospitalQueue.attend();
    hospitalQueue.attend();
    return 0;
}
