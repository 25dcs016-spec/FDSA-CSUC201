#include <iostream>
#include <vector>

class StorageSystem {
private:
    std::vector<int> slots;
    int table_size;

    int hash1(int id) {
        return id % table_size;
    }

    int hash2(int id) {
        return 7 - (id % 7);
    }

public:
    StorageSystem() {
        table_size = 10;
        slots.resize(table_size, -1);
    }

    void assignID(int student_id) {
        int init_slot = hash1(student_id);
        int jump = hash2(student_id);
        int current_slot = init_slot;
        int attempts = 0;

        while (slots[current_slot] != -1) {
            current_slot = (current_slot + jump) % table_size;
            attempts++;
            if (attempts >= table_size) {
                std::cout << "Error: Insertion failed for ID " << student_id << "\n";
                return;
            }
        }
        slots[current_slot] = student_id;
    }

    void displayState() {
        for (int i = 0; i < table_size; i++) {
            std::cout << "Slot " << i << ": ";
            if (slots[i] == -1) std::cout << "Empty\n";
            else std::cout << slots[i] << "\n";
        }
    }
};

int main() {
    StorageSystem sys;
    sys.assignID(1014);
    sys.assignID(2024);
    sys.assignID(3034);
    sys.displayState();
    return 0;
}
