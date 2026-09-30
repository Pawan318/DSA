/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;
    int solve(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left = solve(root -> left);
        int right = solve(root -> right);

        left = max(0, left);
        right = max(0, right);

        int sum = left + root -> val + right;
        ans = max(sum, ans);

        return root -> val + max(left, right);

    }

    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        solve(root);
        return ans;
    }
};