class Solution1 {
public:
    ////////////////////////// Variable Sliding Window //////////////////////////

    int lengthOfLongestSubstring(string s) {

        // Left and right pointers of the sliding window.
        int i = 0, j = 0;

        // Stores the length of the longest valid substring.
        int maxLength = 0;

        // Keeps track of unique characters present in the current window.
        unordered_set<char> charset;

        // Expand the window until the right pointer reaches the end.
        while (j < s.size()) {

            // If the current character is not present in the window,
            // include it and update the maximum length.
            if (charset.find(s[j]) == charset.end()) {

                charset.insert(s[j]);

                maxLength = max(maxLength, j - i + 1);

                // Expand the window.
                j++;
            }
            else {

                // Duplicate character found.
                // Shrink the window from the left until
                // the duplicate character is removed.
                charset.erase(s[i]);
                i++;
            }
        }

        return maxLength;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1); // ASCII chars
        int maxLength = 0;
        int i = 0; // left pointer

        for (int j = 0; j < s.size(); j++) {
            if (lastIndex[s[j]] >= i) {
                // duplicate mila, jump left pointer
                i = lastIndex[s[j]] + 1;
            }
            lastIndex[s[j]] = j;
            maxLength = max(maxLength, j - i + 1);
        }
        return maxLength;
    }
};
