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
    //MAXIMUM ELEMENT IS THE RIGHMOST NODE,WHICH DOESN'T HAVE A RIGHT CHILD
    //recursive SOLUTION
    //T.C = O(N) IN WORST CASE (SKEW TREE)
    //S.C = O(N) FOR RECURSIVE STACK
    TreeNode* FindMax(TreeNode* root){
        if(root == NULL) return NULL;
        
        if(root->right == NULL)
            return root;
        else
            return FindMax(root->right);
    }   
    
};
