class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        // Stores the total amount of trapped rainwater.
        int ans = 0;

        // Two pointers representing the left and right boundaries.
        int l = 0, r = n - 1;

        // Maximum height encountered so far from both directions.
        int lmax = 0, rmax = 0;

        // Continue until both pointers meet.
        while (l < r) {

            // Update the maximum height seen from both sides.
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            // The side with the smaller maximum height determines
            // the amount of water that can be trapped.
            if (lmax < rmax) {

                // Water trapped at the current left position.
                ans += lmax - height[l];

                // Move the left pointer.
                l++;
            }
            else {

                // Water trapped at the current right position.
                ans += rmax - height[r];

                // Move the right pointer.
                r--;
            }
        }
        return ans;
    }
};


// Using Stack
class Solution1 {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        // Stores the total trapped rainwater.
        int ans = 0;

        // Current index while traversing the array.
        int current = 0;

        // Monotonic decreasing stack storing indices of bars.
        stack<int> st;

        // Traverse every bar in the histogram.
        while (current < n) {

            // If the current bar is taller than the top of the stack,
            // a container is formed and water can be trapped.
            while (!st.empty() && height[current] > height[st.top()]) {

                // The popped bar represents the bottom of the container.
                int top = st.top();
                st.pop();

                // If the stack becomes empty, there is no left boundary.
                if (st.empty())
                    break;

                // Width of the trapped water region.
                int distance = current - st.top() - 1;

                // Height of trapped water is determined by the smaller boundary.
                int bounded_height =
                    min(height[current], height[st.top()]) - height[top];

                // Water trapped in the current container.
                ans += distance * bounded_height;
            }

            // Push the current index as a potential left boundary.
            st.push(current);

            current++;
        }

        return ans;
    }
};