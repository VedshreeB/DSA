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
    void solve(TreeNode *root,int T,vector<int> &path,vector<vector<int>> &ans){
        if(root==NULL)return;
        
        if(root->left == NULL && root->right==NULL){
            if(T==root->val){
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();
            }
            return;
        }
        
        path.push_back(root->val);
        solve(root->left,T-root->val,path,ans);
        solve(root->right,T-root->val,path,ans);
        path.pop_back();       
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        if(root == NULL)return ans;                          
        solve(root,targetSum,path,ans);
        return ans;
    }
};