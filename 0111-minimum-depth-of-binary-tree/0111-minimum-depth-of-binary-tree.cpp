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
       queue<TreeNode*>q;
        if(!root) return 0;
        q.push(root);
        int steps=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto node=q.front();
                q.pop();
                if(node->right==NULL and node->left==NULL){
                    return steps+1;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            steps++;
        }
        return -1;
    }
};