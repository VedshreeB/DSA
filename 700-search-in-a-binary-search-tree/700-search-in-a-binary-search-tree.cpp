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
    //RECURSIVE T.C = O(N) WORST CASE ( SKEW TREE)
    //S.C = O(N) FOR RECURSIVE STACK
    
    TreeNode* searchBST(TreeNode* root, int val) {
            //BASE CASE
            if(root == NULL) return NULL;
        
            if(root->val == val)
                return root;
        
            if(val < root->val)
                return searchBST(root->left,val);
            else
                return searchBST(root->right,val);
    }
};