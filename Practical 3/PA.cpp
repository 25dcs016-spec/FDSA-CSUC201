#include <iostream>
#include <vector>
using namespace std;

void bubble(vector<int> a)
{
    int n = a.size();

    for (int i = 0; i < n - 1; i++)
    {
        bool s = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                s = true;
            }
        }

        if (!s)
            break;
    }

    cout << "Bubble Sort: ";
    for (int x : a)
        cout << x << " ";
    cout << endl;
}

void selection(vector<int> a)
{
    int n = a.size();

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
                minIndex = j;
        }

        swap(a[i], a[minIndex]);
    }

    cout << "Selection Sort: ";
    for (int x : a)
        cout << x << " ";
    cout << endl;
}

void insertion(vector<int> a)
{
    int n = a.size();

    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }

    cout << "Insertion Sort: ";
    for (int x : a)
        cout << x << " ";
    cout << endl;
}

int main()
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    vector<int> marks(n);

    cout << "Enter marks: ";
    for (int i = 0; i < n; i++)
        cin >> marks[i];

    bubble(marks);
    selection(marks);
    insertion(marks);

    return 0;
}