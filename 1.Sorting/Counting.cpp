#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> val(n);
    for(int i = 0; i < n; i++)
        cin >> val[i];

    cout << "Before Sorting" << endl;
    for(int v : val)
        cout << v << " ";
    cout << endl;

    int maxi = val[0];
    for(int i = 1; i < n; i++)
        maxi = max(maxi, val[i]);

    vector<int> freq(maxi + 1, 0);

    // Step 1: Count the occurrences of each value in the input array
    for(int v : val)
        freq[v]++;

    // Step 2: Compute the prefix sums
    for(int i = 1; i <= maxi; i++)
        freq[i] += freq[i - 1];

    // Step 3: Place the elements in the correct positions in the output array
    vector<int>output(n);
    for(int i = 0; i<n; i++){
        output[freq[val[i]]-1] = val[i];
        freq[val[i]]--;
    }

    cout << "After Sorting" << endl;
    for(int v : output)
        cout << v << " ";
    cout << endl;

    return 0;
}
