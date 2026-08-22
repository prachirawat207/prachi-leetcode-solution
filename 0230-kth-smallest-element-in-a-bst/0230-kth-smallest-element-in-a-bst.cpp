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
int count =0;
void inorder(TreeNode* root,int k,int &ans){
     
       if(root==NULL){
        return ;
        
       }
    
         
        inorder(root->left,k,ans);
   count++;
        if(count==k){
            ans=root->val;
            return;
        }

        //int node=root->val;
        inorder(root->right,k,ans);
        return;
       }
    int kthSmallest(TreeNode* root, int k) {
        int ans=0;
        inorder(root,k,ans);
      return ans; 
    }
};