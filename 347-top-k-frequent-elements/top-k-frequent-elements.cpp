class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         // Count frequency of each number
    unordered_map<int, int> mp;

    for (auto x : nums) {
        mp[x]++;
    }

    // Min heap: {frequency, number}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    // Keep only k elements with highest frequency
    for (auto [num, count] : mp) {

        pq.push({count, num});

        // Remove least frequent element
        if (pq.size() > k) {
            pq.pop();
        }
    }

    vector<int> ans;

    // Extract numbers from heap
    while (!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
    }
};