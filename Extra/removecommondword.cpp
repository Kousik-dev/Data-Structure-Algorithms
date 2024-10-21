#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

// Function to split a string into words and store them in an unordered_set
unordered_set<string> splitIntoWords(const string& str) {
    unordered_set<string> words;
    string word;
    
    for (char ch : str) {
        if (ch != ' ') {
            word += ch; // Build the current word
        } else {
            if (!word.empty()) {
                words.insert(word); // Add the completed word to the set
                word.clear(); // Clear the word for the next one
            }
        }
    }
    
    // Handle the last word if the string doesn't end with a space
    if (!word.empty()) {
        words.insert(word);
    }
    
    return words;
}

// Function to remove common words from a string
string removeCommonWords(const string& str, const unordered_set<string>& commonWords) {
    string result;
    string word;
    
    for (char ch : str) {
        if (ch != ' ') {
            word += ch; // Build the current word
        } else {
            if (!word.empty()) {
                if (commonWords.find(word) == commonWords.end()) {
                    result += word + " "; // Add the word if it's not in commonWords
                }
                word.clear(); // Clear the word for the next one
            }
        }
    }
    
    // Handle the last word if the string doesn't end with a space
    if (!word.empty()) {
        if (commonWords.find(word) == commonWords.end()) {
            result += word;
        }
    }
    
    return result;
}

int main() {
    string s1 = "manoj is good boy and good programmer deserve zoho job";
    string s2 = "rahul is bad boy and good programmer deserve zoho job";
    string s3 = "Parthiban is bad boy and bad programmer deserve zoho job";

    // Split strings into words
    unordered_set<string> words1 = splitIntoWords(s1);
    unordered_set<string> words2 = splitIntoWords(s2);
    unordered_set<string> words3 = splitIntoWords(s3);

    // Find common words
    unordered_set<string> commonWords;
    for (const string& word : words1) {
        if (words2.find(word) != words2.end() && words3.find(word) != words3.end()) {
            commonWords.insert(word);
        }
    }

    // Remove common words from the original strings
    string result1 = removeCommonWords(s1, commonWords);
    string result2 = removeCommonWords(s2, commonWords);
    string result3 = removeCommonWords(s3, commonWords);

    // Print the results
    cout << "String 1 after removing common words: " << result1 << endl;
    cout << "String 2 after removing common words: " << result2 << endl;
    cout << "String 3 after removing common words: " << result3 << endl;

    return 0;
}


/*


#include <iostream>
#include <sstream>
#include <unordered_set>
#include <string>

using namespace std;

// Function to split a string into words and store them in an unordered_set
unordered_set<string> splitIntoWords(const string& str) {
    unordered_set<string> words;
    stringstream ss(str);
    string word;
    
    while (ss >> word) {
        words.insert(word);
    }
    
    return words;
}

// Function to remove common words from a string
string removeCommonWords(const string& str, const unordered_set<string>& commonWords) {
    stringstream ss(str);
    string word;
    string result;
    
    while (ss >> word) {
        if (commonWords.find(word) == commonWords.end()) {
            result += word + " ";
        }
    }
    
    // Remove the trailing space
    if (!result.empty()) {
        result.pop_back();
    }
    
    return result;
}

int main() {
    string s1 = "manoj is good boy and good programmer deserve zoho job";
    string s2 = "rahul is bad boy and good programmer deserve zoho job";
    string s3 = "Parthiban is bad boy and bad programmer deserve zoho job";

    // Split strings into words
    unordered_set<string> words1 = splitIntoWords(s1);
    unordered_set<string> words2 = splitIntoWords(s2);
    unordered_set<string> words3 = splitIntoWords(s3);

    // Find common words
    unordered_set<string> commonWords;
    for (const string& word : words1) {
        if (words2.find(word) != words2.end() && words3.find(word) != words3.end()) {
            commonWords.insert(word);
        }
    }

    // Remove common words from the original strings
    string result1 = removeCommonWords(s1, commonWords);
    string result2 = removeCommonWords(s2, commonWords);
    string result3 = removeCommonWords(s3, commonWords);

    // Print the results
    cout << "String 1 after removing common words: " << result1 << endl;
    cout << "String 2 after removing common words: " << result2 << endl;
    cout << "String 3 after removing common words: " << result3 << endl;

    return 0;
}















*/