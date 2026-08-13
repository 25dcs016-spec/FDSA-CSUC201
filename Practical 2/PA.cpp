
/* #include <iostream>
using namespace std;

int linear(int arr[], int n, int i, int search)
{

    if (i == n)
        return -1;

    if (arr[i] == search)
        return i;

    return linear(arr, n, i + 1, search);
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[100];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int search;
    cout << "Enter element to search: ";
    cin >> search;

    int pos = linear(arr, n, 0, search);

    if (pos == -1)
        cout << "Element not found";
    else
        cout << "Element found at index " << pos;

    return 0;
} */

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[100];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int search;
    cout << "Enter element to search: ";
    cin >> search;

    int pos = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == search)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
        cout << "Not Found";
    else
        cout << "Found at index " << pos;

    return 0;
}