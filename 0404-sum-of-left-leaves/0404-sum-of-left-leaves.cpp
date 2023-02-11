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
    private:
    void traversal(TreeNode* root,TreeNode* par,int &sum){
        if(root==NULL) return;
        if(root->left) traversal(root->left,root,sum);
         if( root->left==NULL and root->right==NULL and par->left==root){
            sum+=root->val;
        }
        if(root->right) traversal(root->right,root,sum);
       
    }
        
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
         traversal(root,root,sum);
        return sum;
    }
};