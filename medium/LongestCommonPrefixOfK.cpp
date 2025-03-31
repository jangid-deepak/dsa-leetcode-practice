#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to compute the Longest Common Prefix between two words
int lcp(string& a, string& b) {
    int len = min(a.size(), b.size());
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) return i;  // Return LCP length
    }
    return len;
}

vector<int> longestCommonPrefixAfterRemoval(vector<string>& words, int k) {
    int n = words.size();
    vector<int> answer(n, 0);

    // Sort words lexicographically
    vector<string> sorted_words = words;
    sort(sorted_words.begin(), sorted_words.end());

    for (int i = 0; i < n; i++) {
        vector<string> remaining;
        
        // Collect words excluding the i-th word
        for (int j = 0; j < n; j++) {
            if (j != i) remaining.push_back(words[j]);
        }

        // If fewer than k words remain, answer[i] = 0
        if (remaining.size() < k) {
            answer[i] = 0;
            continue;
        }

        // Sort remaining words to bring similar prefixes together
        sort(remaining.begin(), remaining.end());

        int maxLCP = 0;

        // Sliding window to find max LCP among any k words
        for (int j = 0; j + k - 1 < remaining.size(); j++) {
            int currentLCP = remaining[j].size();
            for (int m = j; m < j + k - 1; m++) {
                currentLCP = min(currentLCP, lcp(remaining[m], remaining[m + 1]));
            }
            maxLCP = max(maxLCP, currentLCP);
        }

        answer[i] = maxLCP;
    }

    return answer;
}

// **Example Usage**
int main() {
    vector<string> words = {"jump", "run", "run", "jump", "run"};
    int k = 2;
    vector<int> result = longestCommonPrefixAfterRemoval(words, k);

    for (int res : result) {
        cout << res << " ";
    }
    return 0;
}
