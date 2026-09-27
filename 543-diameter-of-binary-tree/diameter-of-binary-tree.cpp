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
int maxDepth(TreeNode* root) {
        if(root  == NULL)
            return 0;

        int leftHeight = maxDepth(root -> left);
        int rightHeight = maxDepth(root -> right);

        int result = max(leftHeight, rightHeight) + 1;
        return result;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root  == NULL)
        return 0;

        int height1 = diameterOfBinaryTree(root -> left);
        int height2 = diameterOfBinaryTree(root -> right);
        int finalHeight  = maxDepth(root->left) + maxDepth(root->right);
        int ans = max(height1 , max(height2 , finalHeight));
        return ans;
    }
};

class Solution {
public:
    int diameter = 0;
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        int left = height(root -> left);
        int right = height(root -> right);

        diameter = max(diameter, left + right);

        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
       height(root);
       return diameter;
    }
};


