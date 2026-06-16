class Solution {
public:

    // Backtracking function to build all valid combinations
    void solve(int idx,
               string &digits,
               string &temp,
               vector<string>& result,
               unordered_map<char, string>& mp) {

        // A complete combination has been formed
        if (idx == digits.length()) {
            result.push_back(temp);
            return;
        }

        // Get letters corresponding to the current digit
        char ch = digits[idx];
        string str = mp[ch];

        // Try every possible letter for the current digit
        for (int i = 0; i < str.length(); i++) {

            // Choose
            temp.push_back(str[i]);

            // Move to the next digit
            solve(idx + 1, digits, temp, result, mp);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        // Edge case: no digits provided
        if (digits.empty()) {
            return {};
        }

        // Digit-to-letter mapping
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> result;
        string temp;

        // Start generating combinations from index 0
        solve(0, digits, temp, result, mp);

        return result;
    }
};