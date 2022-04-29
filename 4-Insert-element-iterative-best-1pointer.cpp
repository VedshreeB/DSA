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
    //T.C. = O(LOG N) 
    //S.C = O(N)
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        
        TreeNode *curr = root;
        
        while(true){
            if(val < curr->val)//lie in left subtree
            {
                if(curr->left ==NULL){
                    curr->left = new TreeNode(val); break;
                }
                else
                    curr = curr->left;
            }
            else //lie in right subtree
            {
                if(curr->right == NULL)
                {
                    curr->right = new TreeNode(val); break;
                }
                else
                    curr = curr->right;                
            }
            
        }
        
        return root;
    }
};
