class Solution {
public:

    // Backtracking function to generate all possible combinations
    void solve(int k, int n, vector<vector<int>>& result,
               vector<int>& temp, int indx) {

        // Valid combination found:
        // k numbers have been chosen and their sum equals the target
        if (k == 0 && n == 0) {
            result.push_back(temp);
        }

        // Invalid case:
        // No numbers left to pick but target sum has not been achieved
        if (k == 0 && n < 0) {
            return;
        }

        // Try every number from current index to 9
        for (int i = indx; i <= 9; i++) {

            // Choose the current number
            temp.push_back(i);

            // Recur for the remaining numbers and remaining sum
            solve(k - 1, n - i, result, temp, i + 1);

            // Backtrack: remove the last chosen number
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> temp;

        // Start backtracking from number 1
        solve(k, n, result, temp, 1);

        return result;
    }
};