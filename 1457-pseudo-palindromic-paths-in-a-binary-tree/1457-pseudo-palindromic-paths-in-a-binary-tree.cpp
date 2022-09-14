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
    int solve(TreeNode *root,int arr[10]){
        //leaf node
        if(root->left == NULL && root->right==NULL){
            arr[root->val]++;
            int digitOddFreq = 0;
            for(int i=0; i<=9; i++){
              if(arr[i]%2 != 0)
                  digitOddFreq++;
            }
            arr[root->val]--;
            return(digitOddFreq<=1);
        }
        
        arr[root->val]++;
       
        int leftans = 0 , rightans = 0;
        if(root->left)leftans = solve(root->left,arr);
        if(root->right)rightans = solve(root->right,arr);
        arr[root->val]--;
        return (leftans + rightans);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root == NULL) return 0;
        
        int arr[10]={0};
        return solve(root,arr);
    }
};