#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &val, int low, int high)
{
    int i = low, j = high;
    int pivot = val[low];
    while (i < j)
    {

        while (val[i] <= pivot && i <= high - 1)
            i++;

        while (val[j] > pivot && j >= low + 1)
            j--;

        if (i < j)
        {

            swap(val[i], val[j]);
            cout << "Swapped is " << i << " and " << j << "   -> ";
            for (int v : val)
                cout << v << " ";
            cout << endl;
        }
    }
    cout<<"outisde low and j value: "<<low<<" & "<<j<<endl;
    swap(val[low], val[j]);

    for (int v : val)
        cout << v << " ";
    cout << endl;
    return j;
}

void quicksort(vector<int> &val, int low, int high)
{
    if (low < high)
    {
        int pindex = partition(val, low, high);
        quicksort(val, low, pindex - 1);
        quicksort(val, pindex + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> val(n);
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    cout << "Before Sorting:" << endl;
    for (int v : val)
    {
        cout << v << " ";
    }
    cout << endl;

    int low = 0, high = n - 1;
    quicksort(val, low, high);

    cout << "After Sorting:" << endl;
    for (int v : val)
    {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
