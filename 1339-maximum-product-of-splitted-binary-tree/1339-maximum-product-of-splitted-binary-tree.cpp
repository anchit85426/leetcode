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
    long long int totalsum=0;
    long long int m=1e9+7;
    long long int currsum=0;
    long long int maxPro=0;
    private:
        void traversal(TreeNode* root){
            if(!root) return;
            
                traversal(root->left);
            
            
                traversal(root->right);
            
            totalsum=(totalsum+root->val)%m;
        }
        long long int traversal1(TreeNode* root){
            if(root==NULL)return 0;
            currsum=root->val+(traversal1(root->left))%m+(traversal1(root->right))%m;
            maxPro=max(maxPro,((((currsum)*(totalsum-currsum)))));
            return currsum;
        }
public:
    long long int maxProduct(TreeNode* root) {
           traversal(root);
           traversal1(root);
            return maxPro%m;
    }
};