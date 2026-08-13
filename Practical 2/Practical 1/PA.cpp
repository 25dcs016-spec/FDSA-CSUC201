#include <iostream>
using namespace std;

int main()
{
    int n, h;

    cout << "Enter no. of items= ";
    cin >> n;

    int *a = new int[n];

    cout << "Enter the items= ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter no. of hours= ";
    cin >> h;

    h = h % n;

    for (int i = 0; i < h; i++)
    {
        int f = a[0];

        for (int j = 0; j < n - 1; j++)
        {
            a[j] = a[j + 1];
        }

        a[n - 1] = f;
    }

    cout << "Final display order= ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    delete[] a;
    return 0;
}