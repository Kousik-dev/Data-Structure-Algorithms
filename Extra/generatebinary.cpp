#include<iostream>
#include<vector>
using namespace std;

void generateBinaryStringsNoConsecutiveOnes(string current, int i, int k, vector<string>& ans) {
    // Base case: if the string has reached length K
    if (i == k) {
        ans.push_back(current);
        return;
    }

    // Append '0' in all cases
    generateBinaryStringsNoConsecutiveOnes(current + '0', i + 1, k, ans);

    // Append '1' only if the previous character is not '1'
    if (current.empty() || current.back() == '0') {
        generateBinaryStringsNoConsecutiveOnes(current + '1', i + 1, k, ans);
    }
}

int main() {
    int k = 4;  // Set k as required
    vector<string> ans;

    // Generate sequences starting with an empty string
    generateBinaryStringsNoConsecutiveOnes("", 0, k, ans);

    // Print the results
    for (const auto& s : ans) {
        cout << s << endl;
    }

    return 0;
}
