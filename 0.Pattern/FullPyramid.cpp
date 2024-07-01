#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= 2 * n - 1; i++) {
        int totcol = i > n ? 2 * n - i : i;

        // Print leading spaces
        for (int space = 1; space <= n - totcol; space++) {
            cout << " ";
        }

        // Print stars
        for (int col = 1; col <= totcol; col++) {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}
