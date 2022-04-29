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
    int FindMin(TreeNode *root){
        if(root==NULL) return -1;
        
        while(root->left!=NULL){
            root = root->left;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        //base case 
        if(root == NULL) return root;
        
        //element to be found 
        if(root->val == key){
            
            //0 child
            if(root->left==NULL && root->right == NULL)
            {   delete root;
                return NULL;
            }
            
            //1 child
            else if(root->left!=NULL && root->right==NULL){
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            else if(root->left==NULL && root->right!=NULL){
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            
            //2 child
            else{
                int mini = FindMin(root->right);
                //copy mini value to root
                root->val = mini;
                //delete mini
                root->right = deleteNode(root->right,mini);
                return root;
            }
        }
        
        //element to be deleted lies in left subtree
        else if(root->val > key){
            root->left = deleteNode(root->left,key);
            return root;
        }
        
        //element to be deleted lies in right subtree
        else{
            root->right = deleteNode(root->right,key);
            return root;
        }
    }
};
