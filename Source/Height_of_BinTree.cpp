int height(Node* root) 
{
   if (root == NULL)    return 0; 
   int l{0},r{0};
   if (root->left==NULL && root->right==NULL) 
   return 0;
   if (root->left!=NULL)
   l = 1 + height(root->left);
   if(root->right!=NULL)
   r = 1 + height(root->right);
   return max(l,r);      
}