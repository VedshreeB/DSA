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
    //ITERATIVE SOLUTION
    //T.C = O(N) IN WORST CASE (SKEW TREE)
    //S.C = O(1)
    TreeNode* searchBST(TreeNode* root, int val) {
             
        while(root){
            if(root->val == val)
                return root;
            else if(val < root->val)
                root = root->left;
            else
                root = root->right;
        }
        
        return NULL;
    }
};