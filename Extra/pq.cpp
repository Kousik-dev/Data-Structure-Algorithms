#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

struct Compare {
    bool operator() (pair<int, string> a, pair<int, string> b) {
        if(a.first == b.first)
            return a.second > b.second;
        else
            return a.first < b.first;
    }
};

vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> m;
    for(int i = 0; i < words.size(); i++)
        m[words[i]]++;
    
    priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> q;
    for(auto p : m)
        q.push({p.second, p.first});
    
    vector<string> ans;
    
    // Print the contents of the priority queue
    cout << "Priority Queue contents:" << endl;
    while (!q.empty()) {
        cout << "Top: {" << q.top().first << ", " << q.top().second << "}" << endl;
        q.pop();
    }

    // Re-insert elements to extract top k frequent words
    for(auto p : m)
        q.push({p.second, p.first});

    while(k--) {
        ans.push_back(q.top().second);
        q.pop();
    }
    
    return ans;
}

int main() {
    // Example input
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding", "coding", "coding"};
    int k = 3;

    vector<string> result = topKFrequent(words, k);
    
    // Print result
    for (const string& word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
