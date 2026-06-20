class Solution {
public:
    // Check if s[i...j] is a palindrome
    bool isPalindrome(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void solve(int i, string &s, vector<string> &temp,
               vector<vector<string>> &result) {

        // If entire string is partitioned
        if (i == s.size()) {
            result.push_back(temp);
            return;
        }

        // Try all possible partitions starting from i
        for (int j = i; j < s.size(); j++) {

            // If substring s[i...j] is palindrome
            if (isPalindrome(i, j, s)) {

                // Add substring to current partition
                temp.push_back(s.substr(i, j - i + 1));

                // Recur for remaining string
                solve(j + 1, s, temp, result);

                // Backtrack
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> result;

        solve(0, s, temp, result);

        return result;
    }
};