/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };C
 */
 
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;  
        if (root == nullptr) {
            return result;
        }
        vector<int> left_result = inorderTraversal(root->left);

        result.insert(result.end(), left_result.begin(), left_result.end());
        result.push_back(root->val);

        vector<int> right_result = inorderTraversal(root->right);
        result.insert(result.end(), right_result.begin(), right_result.end());
        
        return result;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;

        TreeNode* node = root;

        while (node != nullptr || !st.empty()) {

            // Go as far left as possible
            while (node != nullptr) {
                st.push(node);
                node = node->left;
            }

            // Process the node
            node = st.top();
            st.pop();

            ans.push_back(node->val);

            // Now go to right subtree
            node = node->right;
        }

        return ans;
    }
};