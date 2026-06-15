class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>&nums, vector<int>&temp, int i = 0){
        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }
        // Include the current element in temp
        temp.push_back(nums[i]);
        solve(nums, temp, i+1);
        temp.pop_back();

        // Exclude the duplicate element
        while(i+1 < nums.size() && nums[i] == nums[i+1]){
            i++;
        }
        solve(nums, temp, i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        solve(nums,temp, 0);
        return ans;
    }
};