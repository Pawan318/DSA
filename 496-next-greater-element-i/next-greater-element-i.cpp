class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        // Stores the next greater element for each number in nums2.
        unordered_map<int, int> mp;

        // Monotonic decreasing stack.
        stack<int> st;

        // Traverse nums2 from right to left.
        for (int i = nums2.size() - 1; i >= 0; i--) {

            // Remove all elements smaller than or equal to the current element
            // because they can never be the next greater element.
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            // If the stack is empty, no greater element exists on the right.
            if (st.empty()) {
                mp[nums2[i]] = -1;
            }
            // Otherwise, the top of the stack is the next greater element.
            else {
                mp[nums2[i]] = st.top();
            }

            // Push the current element for future comparisons.
            st.push(nums2[i]);
        }

        // Build the answer for nums1 using the precomputed map.
        vector<int> ans;

        for (int num : nums1) {
            ans.push_back(mp[num]);
        }

        return ans;
    }
};