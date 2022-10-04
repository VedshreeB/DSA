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
    bool solve(TreeNode *root,int sum,int T){
        if(root==NULL) return false;
        
        if(!root->left && !root->right){
            return(T-sum == root->val);
        }
        
        bool lans = solve(root->left,sum+root->val,T);
        bool rans = solve(root->right,sum+root->val,T);
            
        return (lans || rans);
    }
    bool hasPathSum(TreeNode* root, int T) {
        return solve(root,0,T);
    }
};