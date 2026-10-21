
#include <iostream>
#include <vector>
#include <string>

class ParkingLot {
private:
    std::vector<std::string> slots;

public:
    ParkingLot() {
        slots.resize(10, "Empty");
    }

    void parkVehicle(std::string reg_num) {
        int last_digit = reg_num.back() - '0';
        int start_slot = last_digit;
        int current_slot = start_slot;
        
        while (slots[current_slot] != "Empty") {
            current_slot = (current_slot + 1) % 10;
            if (current_slot == start_slot) {
                std::cout << "Error: Parking lot is full for " << reg_num << "\n";
                return;
            }
        }
        slots[current_slot] = reg_num;
    }

    void displayState() {
        for (int i = 0; i < 10; i++) {
            std::cout << "Slot " << i << ": " << slots[i] << "\n";
        }
    }
};

int main() {
    ParkingLot lot;
    lot.parkVehicle("MH12AB1234");
    lot.parkVehicle("DL3CXY5674");
    lot.parkVehicle("KA01EF9994");
    lot.displayState();
    return 0;
}
