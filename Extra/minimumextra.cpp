#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int solve(int start, string s, unordered_set<string>& st, int n, int depth) {
        // Indentation for better visualization of recursion depth
        string indent(depth * 4, ' ');

        // Print the current state of recursion
        cout << indent << "solve(" << start << ", \"" << s.substr(start) << "\")" << endl;

        // Base case: if we reach the end of the string, no extra characters are left
        if (start >= n) {
            cout << indent << "Reached end of string, returning 0" << endl;
            return 0;
        }

        // Option 1: Assume current character is an extra character
        cout << indent << "Assuming '" << s[start] << "' is extra" << endl;
        int result = 1 + solve(start + 1, s, st, n, depth + 1);
        cout << indent << "Result after assuming '" << s[start] << "' is extra: " << result << endl;

        // Option 2: Try to match any valid word from the dictionary
        for (int end = start; end < n; end++) {
            string temp = s.substr(start, end - start + 1);
            if (st.count(temp)) {
                cout << indent << "Found valid word \"" << temp << "\" (from index " << start << " to " << end << ")" << endl;
                cout << indent << "Calling solve(" << end + 1 << ", \"" << s.substr(end + 1) << "\") after using \"" << temp << "\"" << endl;
                int subResult = solve(end + 1, s, st, n, depth + 1);
                result = min(result, subResult);
                cout << indent << "Result after using \"" << temp << "\": " << result << endl;
            }
        }

        // Return the result for this recursion
        cout << indent << "Returning result for solve(" << start << "): " << result << endl;
        return result;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        int n = s.length();
        return solve(0, s, st, n, 0);
    }
};

int main() {
    // Input string and dictionary
    string s = "leetscode";
    vector<string> dictionary = {"leet", "code", "leetcode"};

    // Create a Solution object
    Solution sol;

    // Call the function and print the final result
    int result = sol.minExtraChar(s, dictionary);

    // Final result
    cout << "Final result (minimum extra characters): " << result << endl;

    return 0;
}
