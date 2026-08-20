#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int> &a)
{
    int low = 0;
    int mid = 0;
    int high = a.size() - 1;

    while (mid <= high)
    {
        if (a[mid] == 0)
        {
            swap(a[low], a[mid]);
            low++;
            mid++;
        }
        else if (a[mid] == 1)
        {
            mid++;
        }
        else
        { // a[mid] == 2
            swap(a[mid], a[high]);
            high--;
        }
    }
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter only 0, 1 and 2: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sortColors(a);

    cout << "Sorted array: ";
    for (int x : a)
        cout << x << " ";

    cout << endl;

    return 0;
}