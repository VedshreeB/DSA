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
    int help(TreeNode *root,int T,vector<int> &ds){
        if(root==NULL)return 0;
        
        ds.push_back(root->val);
        long long int sum = 0, op1 = 0;
        for(int i=ds.size()-1; i>=0 ; i--){
            sum += ds[i];
            if(sum == T)
                op1++;
        }
        
        op1 += help(root->left,T,ds);
        op1 += help(root->right,T,ds);
        ds.pop_back();
        return op1;
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> ds;
        return help(root,targetSum,ds);
    }
};