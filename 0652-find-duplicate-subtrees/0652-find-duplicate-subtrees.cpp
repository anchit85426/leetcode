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
    map<string,int>mpp;
    string traversal(TreeNode *root,vector<TreeNode* >&ans){
        if(root==NULL) return ",";
        string s=traversal(root->left,ans)+','+traversal(root->right,ans)+','+to_string(root->val);
        mpp[s]++;
        if(mpp[s]==2){
            ans.push_back(root);
            
        }
        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;
        traversal(root,ans);
        return ans;
    }
};