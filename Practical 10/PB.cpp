#include <iostream>
#include <vector>
#include <string>

class Library {
private:
    std::vector<std::vector<std::string>> shelves;

public:
    Library() {
        shelves.resize(10);
    }

    void addBook(int book_code) {
        int shelf_idx = book_code % 10;
        shelves[shelf_idx].push_back(std::to_string(book_code));
    }

    void displayState() {
        for (int i = 0; i < 10; i++) {
            std::cout << "Shelf " << i << ": ";
            if (shelves[i].empty()) {
                std::cout << "Empty";
            } else {
                for (const auto& book : shelves[i]) {
                    std::cout << "[" << book << "] ";
                }
            }
            std::cout << "\n";
        }
    }
};

int main() {
    Library lib;
    lib.addBook(102);
    lib.addBook(542);
    lib.addBook(982);
    lib.addBook(405);
    lib.displayState();
    return 0;
}
