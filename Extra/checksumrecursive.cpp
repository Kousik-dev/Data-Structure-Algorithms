#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>& val, int target, int temp, int ind, vector<int>& current) {
    // Base case: if we have processed all elements
    if (ind == val.size()) {
        if (temp == target) {
            // Print the current valid subset
            for (int i = 0; i < current.size(); i++) {
                cout << current[i] << " ";
            }
            cout << endl; // New line after printing the subset
        }
        return; // Return from the function after processing
    }

    // Include the current element in the subset
    current.push_back(val[ind]);
    backtrack(val, target, temp + val[ind], ind + 1, current);

    // Exclude the current element from the subset
    current.pop_back(); // Backtrack: undo the inclusion
    backtrack(val, target, temp, ind + 1, current);
}

int main() {
    vector<int> val = {1, 2, 1};
    int target = 2;
    vector<int> current; // To store the current subset

    backtrack(val, target, 0, 0, current);

    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

int backtrack(vector<int>& val, int target, int temp, int ind) {
    // Base case: if we have processed all elements
    if (ind == val.size()) {
        // If the current sum equals the target, return 1 (valid subset)
        return (temp == target) ? 1 : 0;
    }

    // Early exit if temp is already greater than the target
    if (temp > target) {
        return 0;
    }

    // Include the current element in the subset (Left branch)
    int left = backtrack(val, target, temp + val[ind], ind + 1);

    // Exclude the current element from the subset (Right branch)
    int right = backtrack(val, target, temp, ind + 1);

    // Return the total count of valid subsets from both branches
    return left + right;
}

int main() {
    vector<int> val = {1, 2, 1};
    int target = 3;

    int totalCount = backtrack(val, target, 0, 0);
    cout << "Total count of subsets with sum " << target << ": " << totalCount << endl;

    return 0;
}
