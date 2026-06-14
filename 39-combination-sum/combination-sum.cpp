class Solution {
public:
    vector<vector<int>> ans; // Vector to store all valid combinations

    // Recursive function to generate combinations
    void solve(vector<int>& candidates, vector<int>& temp, int target, int j) {
        if (target == 0) { // Base case: if target is 0, we've found a valid combination
            ans.push_back(temp);
            return;
        }
        for (int i = j; i < candidates.size(); i++) { // Iterate through candidates
            if (candidates[i] > target) {
                break; // Since candidates are sorted, no further elements will be valid
            }
            // Include the current candidate
            temp.push_back(candidates[i]);
            // Recurse with the updated target and the same start index (since candidates can be reused)
            solve(candidates, temp, target - candidates[i], i);
            // Backtrack: remove the current candidate to explore other combinations
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp; // Temporary vector to store the current combination
        sort(candidates.begin(), candidates.end()); // Sort the candidates to handle duplicates
        solve(candidates, temp, target, 0); // Start the recursion
        return ans; // Return the result
    }
};