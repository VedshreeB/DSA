*************************************************************/
bool isBST(BinaryTreeNode<int>* root,int min,int max){
	//base case
	if(root == NULL)return true;
	
	if(root->data > min && root->data<max) //root node sahi hai
	{
		bool left = isBST(root->left,min,root->data); 
		bool right = isBST(root->right,root->data,max);
		return left && right;
	}
	else
		return false;
}
bool validateBST(BinaryTreeNode<int>* root) 
{
	return isBST(root,INT_MIN,INT_MAX);
    // Write your code here
}
