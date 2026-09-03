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

    void reversePrint(Node *temp)
    {
        if (temp == NULL)
        {
            return;
        }

        reversePrint(temp->next);

        cout << temp->token << " ";
    }

public:
    Queue()
    {
        front = NULL;
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
    }

    void deleteByValue(int token)
    {
        if (front == NULL)
        {
            cout << "Queue is empty.\n";
            return;
        }

        if (front->token == token)
        {
            Node *temp = front;

            front = front->next;

            delete temp;

            cout << "Patient " << token
                 << " deleted successfully.\n";

            return;
        }

        Node *temp = front;

        while (temp->next != NULL &&
               temp->next->token != token)
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            cout << "Patient " << token
                 << " not found.\n";

            return;
        }

        Node *deleteNode = temp->next;

        temp->next = deleteNode->next;

        delete deleteNode;

        cout << "Patient " << token
             << " deleted successfully.\n";
    }

    void forwardTraversal()
    {
        if (front == NULL)
        {
            cout << "Queue is empty.\n";
            return;
        }

        Node *temp = front;

        cout << "Front to Back: ";

        while (temp != NULL)
        {
            cout << temp->token << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void reverseTraversal()
    {
        if (front == NULL)
        {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Back to Front: ";

        reversePrint(front);

        cout << endl;
    }
};

int main()
{
    Queue q;

    int choice;
    int token;

    do
    {
        cout << "\n========== HOSPITAL QUEUE ==========\n";
        cout << "1. Add Patient\n";
        cout << "2. Delete Patient by Token\n";
        cout << "3. Display Front to Back\n";
        cout << "4. Display Back to Front\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "Enter patient token: ";
            cin >> token;

            q.insertEnd(token);

            cout << "Patient added successfully.\n";

            break;

        case 2:

            cout << "Enter token to delete: ";
            cin >> token;

            q.deleteByValue(token);

            break;

        case 3:

            q.forwardTraversal();

            break;

        case 4:

            q.reverseTraversal();

            break;

        case 5:

            cout << "Program ended.\n";

            break;

        default:

            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}