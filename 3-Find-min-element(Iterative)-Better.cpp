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
    //MINIMUM ELEMENT IS THE LEFTMOST NODE,WHICH DOESN'T HAVE A LEFT CHILD
    //ITERATIVE SOLUTION
    //T.C = O(N) IN WORST CASE (SKEW TREE)
    //S.C = O(1)
    TreeNode* FindMin(TreeNode* root){
        if(root == NULL) return NULL;
        
        while(root->left!=NULL){
            root = root->left;
        }
        return root;
    }   
    
};
