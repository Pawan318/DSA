class Solution {
public:
    vector<vector<int>> ans; // Vector to store all subsets

    // Recursive function to generate subsets
    void solve(vector<int>& nums, vector<int>& temp, int i = 0) {
        int n = nums.size();
        if (i == n) { // Base case: when all elements are processed
            ans.push_back(temp); // Add the current subset to the result
            return;
        }
        // Exclude the current element
        solve(nums, temp, i + 1);
        // Include the current element
        temp.push_back(nums[i]);
        solve(nums, temp, i + 1);
        // Backtrack: remove the current element to explore other subsets
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp; // Temporary vector to store the current subset
        solve(nums, temp, 0); // Start the recursion
        return ans; // Return the result
    }
};