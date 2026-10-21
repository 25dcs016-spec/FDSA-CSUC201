#include <iostream>
#include <queue>
using namespace std;

int main() {
    int q;
    cin >> q;

    queue<int> patients;

    while (q--) {
        string operation;
        cin >> operation;

        if (operation == "arrive") {
            int patient;
            cin >> patient;
            patients.push(patient);
        }
        else if (operation == "attend") {
            if (patients.empty()) {
                cout << "Error: Queue is empty\n";
            } else {
                patients.pop();
            }
        }

        if (!patients.empty())
            cout << "start: " << patients.front() << "\n";
        else
            cout << "start: Empty\n";
    }

    return 0;
}