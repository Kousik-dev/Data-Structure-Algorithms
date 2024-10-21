/*#include<iostream>
#include<vector>
using namespace std;
int main(){

    string s = "abc";
    int n = s.length();
    vector<string>ans;
    for(int num = 0; num< (1<<n); num++){

       string temp = "";

       for(int j = 0; j<n; j++){
        if(num & (1<<j))
        temp = temp + s[j];
       }

       ans.push_back(temp);
    }
    int i = 0;
    for(auto val: ans)
    cout<<i++<<" : "<<val<<endl;
}

*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

void backtrack(string a, vector<string>& ans, int start, string temp, int n) {

    if (start == n) {  // Base case: when the start reaches the length of the string
        ans.push_back(temp);
        return;
    }

    // Include the current character
    backtrack(a, ans, start + 1, temp + a[start], n);

    // Exclude the current character
    backtrack(a, ans, start + 1, temp, n);
}

int main() {
    string val = "abc";
    vector<string> ans;

    backtrack(val, ans, 0, "", val.length());

    for (auto& val : ans) {
        cout << val << endl;
    }

    return 0;
}
