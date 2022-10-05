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
    void solve(TreeNode *root,int val,int depth){
        if(depth>1){
            if(root->left)solve(root->left,val,depth-1);
            if(root->right)solve(root->right,val,depth-1);
        }
        else{
            root->left = new TreeNode(val,root->left,NULL);
            root->right = new TreeNode(val,NULL,root->right);
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode *cur = new TreeNode(val,root,NULL);
            return cur;
        }
        
        solve(root,val,depth-1);
        return root;
    }
    
};