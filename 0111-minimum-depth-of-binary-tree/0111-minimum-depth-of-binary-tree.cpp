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
    long long int Traversal(TreeNode* root){
        if(!root) return 0;
        long long int left=INT_MAX,right=INT_MAX;
        if(root->left) left=Traversal(root->left);
        if(root->right) right=Traversal(root->right);
        if(root->left==NULL and root->right==NULL){
            return 1;
        }
        return min(left,right)+1;
    }
public:
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return Traversal(root);
    }
};