#include <iostream>
using namespace std;

struct Node
{
    int token;
    Node *next;
};

class Queue
{
private:
    Node *front;

public:
    Queue()
    {
        front = NULL;
    }

    void insertFront(int token)
    {
        Node *newNode = new Node;

        newNode->token = token;
        newNode->next = front;

        front = newNode;

        cout << "Patient " << token
             << " inserted at front.\n";

        display();
    }

    void insertEnd(int token)
    {
        Node *newNode = new Node;

        newNode->token = token;
        newNode->next = NULL;

        if (front == NULL)
        {
            front = newNode;
        }
        else
        {
            Node *temp = front;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        cout << "Patient " << token
             << " inserted at end.\n";

        display();
    }

    void insertAtPosition(int token, int position)
    {
        if (position < 1)
        {
            cout << "Invalid position.\n";
            return;
        }

        if (position == 1)
        {
            insertFront(token);
            return;
        }

        Node *temp = front;

        for (int i = 1; i < position - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Position is greater than "
                     << "current queue length.\n";
                return;
            }

            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Position is greater than "
                 << "current queue length.\n";
            return;
        }

        Node *newNode = new Node;

        newNode->token = token;
        newNode->next = temp->next;

        temp->next = newNode;

        cout << "Patient " << token
             << " inserted at position "
             << position << ".\n";

        display();
    }

    void display()
    {
        if (front == NULL)
        {
            cout << "Queue is empty.\n";
            return;
        }

        Node *temp = front;

        cout << "Queue: ";

        while (temp != NULL)
        {
            cout << temp->token << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    Queue q;

    int choice;
    int token;
    int position;

    do
    {
        cout << "\n========== HOSPITAL QUEUE ==========\n";
        cout << "1. Insert Critical Patient at Front\n";
        cout << "2. Insert Routine Patient at End\n";
        cout << "3. Insert Priority Patient at Position\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter patient token: ";
            cin >> token;

            q.insertFront(token);
            break;

        case 2:
            cout << "Enter patient token: ";
            cin >> token;

            q.insertEnd(token);
            break;

        case 3:
            cout << "Enter patient token: ";
            cin >> token;

            cout << "Enter position: ";
            cin >> position;

            q.insertAtPosition(token, position);
            break;

        case 4:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}