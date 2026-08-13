#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Books borrowed by students = ";
    cin >> n;

    int *a = new int[n];

    cout << "Enter the book numbers = ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int max = 0;

    for (int i = 0; i < n; i++)
    {
        int c = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
                c++;
        }

        if (c > max)
            max = c;
    }

    cout << "Most borrowed book(s): ";

    for (int i = 0; i < n; i++)
    {
        bool already = false;

        for (int k = 0; k < i; k++)
        {
            if (a[k] == a[i])
            {
                already = true;
                break;
            }
        }

        if (already)
            continue;

        int c = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
                c++;
        }

        if (c == max)
            cout << a[i] << " ";
    }

    delete[] a;
    return 0;
}