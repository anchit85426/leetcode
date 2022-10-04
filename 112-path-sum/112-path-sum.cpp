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
    void Traversal(TreeNode* root,int &sum,int targetSum,bool &flag){
        if(root->left!=NULL){
            sum+=root->left->val;
            Traversal(root->left,sum,targetSum,flag);
        }
        if(root->right!=NULL){
            sum+=root->right->val;
            Traversal(root->right,sum,targetSum,flag);
        }
        if(root->left==NULL and root->right==NULL){
            if(sum==targetSum){
                flag=1;
            }
        }
        sum-=root->val;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return NULL;
        bool flag=0;
        Traversal(root,root->val,targetSum,flag);
        return flag;
    }
};