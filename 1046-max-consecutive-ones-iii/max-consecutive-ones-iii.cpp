class Solution {
public:
    // Sliding Window (Variable Size Window)
    int longestOnes(vector<int>& nums, int k) {

        int left = 0;      // Left pointer of the sliding window
        int zeroCount = 0; // Number of zeros in the current window
        int ans = 0;       // Stores the maximum valid window length

        // Expand the window by moving the right pointer
        for (int right = 0; right < nums.size(); right++) {

            // Include the current element in the window
            if (nums[right] == 0)
                zeroCount++;

            // Shrink the window if the number of zeros exceeds k
            while (zeroCount > k) {

                // If the element leaving the window is a zero,
                // decrease the zero count
                if (nums[left] == 0)
                    zeroCount--;

                // Move the left pointer to shrink the window
                left++;
            }

            // Update the maximum length of a valid window
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

/*
Approach:
1. Use a variable-size sliding window.
2. Expand the window by moving the right pointer.
3. Count the number of zeros in the current window.
4. If zeros exceed k, shrink the window from the left until it becomes valid.
5. After every valid window, update the maximum window length.

Time Complexity: O(n)
- Each element is visited at most twice (once by the right pointer and once by the left pointer).

Space Complexity: O(1)
- Only a few variables are used.
*/