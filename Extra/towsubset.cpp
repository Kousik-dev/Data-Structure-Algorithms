#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to print subsets
void printSubset(const vector<int>& subset) {
    for (int num : subset) {
        cout << num << " ";
    }
    cout << endl;
}

// Function to find two subsets with equal sum using power set approach
void findEqualSumSubsets(const vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, vector<int>> subsetSums; // Store sum -> corresponding subset

    // Iterate over all possible subsets (2^n subsets)
    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<int> currentSubset;
        int currentSum = 0;

        // Generate subset for this mask
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {  // If i-th element is in the subset
                currentSubset.push_back(arr[i]);
                currentSum += arr[i];
            }
        }

        // Check if we've already seen this sum before
        if (subsetSums.find(currentSum) != subsetSums.end()) {
            cout << "First subset with sum " << currentSum << ": ";
            printSubset(subsetSums[currentSum]);

            cout << "Second subset with sum " << currentSum << ": ";
            printSubset(currentSubset);
            return;
        }

        // Store the sum with the current subset
        subsetSums[currentSum] = currentSubset;
    }

    cout << "No two subsets with equal sum found." << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    findEqualSumSubsets(arr);

    return 0;
}


/*


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to print subsets
void printSubset(const vector<int>& subset) {
    for (int num : subset) {
        cout << num << " ";
    }
    cout << endl;
}

// Recursive function to find equal sum subsets
void findSubsets(int index, vector<int>& currentSubset, int currentSum, const vector<int>& arr, unordered_map<int, vector<int>>& subsetSums) {
    // Base case: if we've processed all elements
    if (index == arr.size()) {
        if (subsetSums.find(currentSum) != subsetSums.end()) {
            // If we found two subsets with the same sum
            cout << "First subset with sum " << currentSum << ": ";
            printSubset(subsetSums[currentSum]);

            cout << "Second subset with sum " << currentSum << ": ";
            printSubset(currentSubset);
            exit(0); // Exit after finding the first pair of equal-sum subsets
        }

        // Store the current subset's sum and the subset itself
        subsetSums[currentSum] = currentSubset;
        return;
    }

    // Option 1: Include the current element
    currentSubset.push_back(arr[index]);
    findSubsets(index + 1, currentSubset, currentSum + arr[index], arr, subsetSums);

    // Option 2: Exclude the current element
    currentSubset.pop_back();
    findSubsets(index + 1, currentSubset, currentSum, arr, subsetSums);
}

void findEqualSumSubsetsRecursive(const vector<int>& arr) {
    unordered_map<int, vector<int>> subsetSums; // Store sum -> corresponding subset
    vector<int> currentSubset;

    findSubsets(0, currentSubset, 0, arr, subsetSums);

    cout << "No two subsets with equal sum found." << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    findEqualSumSubsetsRecursive(arr);

    return 0;
}














*/