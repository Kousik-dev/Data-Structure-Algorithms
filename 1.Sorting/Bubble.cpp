#include <iostream>
using namespace std;
int main()
{
    int n, didswap = 0;
    cin >> n;
    int arr[n];
    cout << "Before Sorting ";
    for (int i = 0; i < n; i++)

        cin >> arr[i];
    for (int val : arr)
        cout << val << " ";
    cout << endl;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didswap = 1;
            }
        }
        if (didswap == 0)
        {
            break;
        }
    }
    cout << "AFter Sorting ";
    for (int val : arr)
        cout << val << " ";
}