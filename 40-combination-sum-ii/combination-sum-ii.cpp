class Solution {
public:
    void solve(int i, vector<int>& candidates, int target,
               vector<int>& temp, vector<vector<int>>& result) {

        if(target == 0) {
            result.push_back(temp);
            return;
        }

        if(i == candidates.size() || target < 0) {
            return;
        }

        // Take
        temp.push_back(candidates[i]);
        solve(i + 1, candidates, target - candidates[i], temp, result);
        temp.pop_back();

        // Skip duplicates
        int j = i + 1;
        while(j < candidates.size() &&
              candidates[j] == candidates[i]) {
            j++;
        }

        // Not Take
        solve(j, candidates, target, temp, result);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;
        vector<int> temp;

        solve(0, candidates, target, temp, result);

        return result;
    }
};