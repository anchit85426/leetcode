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
    void traversal(TreeNode* root,int &ans,string &s){
        if(root==NULL){
            return;
        }
        if(root->left) traversal(root->left,ans,s+=to_string(root->left->val));
       
        if(root->right) traversal(root->right,ans,s+=to_string(root->right->val));
        
        if(root->left ==NULL and root->right==NULL){
            
           
            ans+=stoi(s);        
           
            
        }
         s.pop_back();
        
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans=0;
        string s="";
        s+=to_string(root->val);
        traversal(root,ans,s);
        return ans;
    }
};