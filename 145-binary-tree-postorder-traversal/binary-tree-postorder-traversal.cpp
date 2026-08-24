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
class Solution1 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int> result;  
        if (root == nullptr) {
            return result;
        }
        vector<int> left_result = postorderTraversal(root->left);
        result.insert(result.end(), left_result.begin(), left_result.end());
        vector<int> right_result = postorderTraversal(root->right);
        result.insert(result.end(), right_result.begin(), right_result.end());

        result.push_back(root->val);        
        return result;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;

        TreeNode* node = root;
        TreeNode* lastVisited = nullptr;

        while (node != nullptr || !st.empty()) {

            // Go left
            while (node != nullptr) {
                st.push(node);
                node = node->left;
            }

            TreeNode* top = st.top();

            // If right child exists and hasn't been visited
            if (top->right != nullptr && lastVisited != top->right) {
                node = top->right;
            }
            else {
                // Left and right are done, so process root
                result.push_back(top->val);
                lastVisited = top;
                st.pop();
            }
        }

        return result;
    }
};