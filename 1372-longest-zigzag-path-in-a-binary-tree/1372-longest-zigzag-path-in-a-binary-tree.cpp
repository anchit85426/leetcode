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
    int maxlength=0;
    void traversal(TreeNode* root,int dir,int length){
        if(!root) return ;
        maxlength=max(maxlength,length);
        traversal(root->left,0,dir?length+1:1);
        traversal(root->right,1,dir?1:length+1);
    }
public:
    int longestZigZag(TreeNode* root) {
        int l=0;
        int r=0;
        int ans=0;
    
        traversal(root,0,0);
        return maxlength;
    }
};