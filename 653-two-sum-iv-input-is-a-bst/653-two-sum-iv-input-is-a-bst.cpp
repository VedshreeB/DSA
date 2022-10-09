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
    void f(TreeNode *root,vector<int> &inorder){
        if(!root)return;
        
        f(root->left,inorder);
        inorder.push_back(root->val);
        f(root->right,inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        f(root,v);
        
        int i=0;
        int j=v.size()-1;
        while(i<j){  
            if(v[i]+v[j] == k)return true;
            else if(v[i]+v[j] > k) j--;
            else i++;
        }
        return false;
    }
};