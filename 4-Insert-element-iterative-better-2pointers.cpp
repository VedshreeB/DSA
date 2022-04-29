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
    //ITERATIVE SOLUTION  USING TWO POINTERS
    //T.C. = O(LOG N ) = O(HEIGHT)
    //S.C. = O(1)
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            root = new TreeNode(val);
            return root;
        }
        
        TreeNode* t = root;
        TreeNode* r = NULL;
        
        while(t!=NULL){
            r = t;
            if(val < t->val)
                t = t->left;
            else 
                t = t->right;
        }
        t = new TreeNode(val);
        if(val< r->val)
            r->left = t;
        else
            r->right = t;
        
        return root;
    }
    
};
