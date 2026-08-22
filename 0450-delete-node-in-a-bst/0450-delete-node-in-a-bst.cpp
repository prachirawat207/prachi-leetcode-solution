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
TreeNode* inorderpredecesor(TreeNode *root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
       
        TreeNode* ipre=NULL;
        if(root==NULL){
            return root;
        }
        //searching
        if(key>root->val){
            root->right=deleteNode(root->right,key);
        }
        else if(key<root->val){
            root->left=deleteNode(root->left,key);
        }
        //case1
        else {
            if(root->right ==NULL && root->left==NULL){
            delete root;
                return NULL;
            }
            else if(root->left==NULL){
            TreeNode* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            TreeNode* temp=root->left;
            delete root;
            return temp;
        }
        else{
            ipre=inorderpredecesor(root);
            root->val=ipre->val;
            root->left=deleteNode(root->left,ipre->val);
        }
        }
       return root;
    }
};