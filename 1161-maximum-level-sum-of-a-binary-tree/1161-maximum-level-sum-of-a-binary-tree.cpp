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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int maxi=root->val;
        int level=1;
        int x=0;
        while(!q.empty()){
            int size=q.size();
            int sum=0;
            x++;
            while(size--){
                auto node=q.front();
                sum+=node->val;
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
            }
            if(sum>maxi){
                maxi=sum;
                level=x;
            }
        }
        return level;
    }
};