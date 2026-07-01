class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        // Traverse the circular array twice from right to left.
        for (int i = 2 * n - 1; i >= 0; i--) {

            // Remove all elements that are smaller than or equal
            // to the current element.
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }

            // Store the answer only during the first pass.
            if (i < n) {
                if (!st.empty()) {
                    ans[i] = st.top();
                }
            }

            // Push the current element onto the stack.
            st.push(nums[i % n]);
        }

        return ans;
    }
};