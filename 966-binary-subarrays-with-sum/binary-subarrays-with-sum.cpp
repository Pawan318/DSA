class Solution {
public:
    // Returns the number of subarrays with sum <= goal
    int atMost(vector<int>& nums, int goal) {

        // If goal becomes negative, no valid subarray exists
        if (goal < 0)
            return 0;

        int i = 0;
        int sum = 0;
        int count = 0;

        // Expand the window using the right pointer
        for (int j = 0; j < nums.size(); j++) {

            // Add the current element to the window
            sum += nums[j];

            // Shrink the window until the sum becomes <= goal
            while (sum > goal) {
                sum -= nums[i];
                i++;
            }

            // Every subarray ending at j and starting
            // from i to j is valid
            count += (j - i + 1);
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        // Exact goal = atMost(goal) - atMost(goal - 1)
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};