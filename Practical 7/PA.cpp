#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> queue(n);
    int start = 0, rear = 0, count = 0;

    while (q--) {
        string operation;
        cin >> operation;

        if (operation == "join") {
            int token;
            cin >> token;

            if (count == n) {
                cout << "Error: Queue is full\n";
            } else {
                queue[rear] = token;
                rear = (rear + 1) % n;
                count++;
            }
        } 
        else if (operation == "serve") {
            if (count == 0) {
                cout << "Error: Queue is empty\n";
            } else {
                start = (start + 1) % n;
                count--;
            }
        }

        if (count > 0)
            cout << "start: " << queue[start] << "\n";
        else
            cout << "start: Empty\n";
    }

    return 0;
}