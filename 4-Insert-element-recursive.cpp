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
    //recursive 
    //AFTER INSERTING THE TREE IS RETURNED TO ITS PARENT.AS A RESULT,WHOLE TREE GETS UPDATED
    //T.C = O(N) 
    //S.C = O(N) FOR RECURSIVE STACK
    //return root of the tree
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //base case
        if(root == NULL){
            root = new TreeNode(val);
            return root;
        }
        
        else if(val < root->val){
            root->left = insertIntoBST(root->left,val);
        }
        else if(val > root->val){
            root->right = insertIntoBST(root->right,val);
        }
        
        return root;
        
    }
};
