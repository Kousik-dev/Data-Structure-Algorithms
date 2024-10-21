#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    int perform(int x, int y, char op) {
        if (op == '+')
            return x + y;
        else if (op == '-')
            return x - y;
        else if (op == '*')
            return x * y;
        else if (op == '/')
            return x / y;

        return 0;
    }

    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        bool isNum = true;

        cout << "Evaluating expression: \"" << expression << "\"" << endl;

        for (int i = 0; i < expression.length(); i++) {
            char ch = expression[i];

            if (!isdigit(ch)) {
                isNum = false; // It's an operator
                cout << "\nOperator found: '" << ch << "'" << endl;

                string leftExpr = expression.substr(0, i);
                string rightExpr = expression.substr(i + 1);
                
                cout << "Left part of expression: \"" << leftExpr << "\"" << endl;
                cout << "Right part of expression: \"" << rightExpr << "\"" << endl;

                vector<int> left = diffWaysToCompute(leftExpr);
                vector<int> right = diffWaysToCompute(rightExpr);

                cout << "Results from left part: ";
                for (int x : left) {
                    cout << x << " ";
                }
                cout << endl;

                cout << "Results from right part: ";
                for (int y : right) {
                    cout << y << " ";
                }
                cout << endl;

                for (int x : left) {
                    for (int y : right) {
                        int val = perform(x, y, ch);
                        cout << "Computing: " << x << " " << ch << " " << y << " = " << val << endl;
                        ans.push_back(val);
                        cout << "Value pushed into ans: " << val << endl;
                    }
                }
            }
        }

        if (isNum) {
            int num = stoi(expression);
            ans.push_back(num);
            cout << "Number found: " << num << endl;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string expression = "2*3-4*5";
    vector<int> result = sol.diffWaysToCompute(expression);

    cout << "\nResults for expression \"" << expression << "\":" << endl;
    for (int res : result) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
