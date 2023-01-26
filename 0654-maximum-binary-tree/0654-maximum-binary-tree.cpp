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
    TreeNode* helper(vector<int>nums,int left,int right){
        if(left>right) return  NULL;
        int index=left;
        
        for(int i=left;i<=right;i++){
            if(nums[i]>nums[index]){
                index=i;
            }
        }
        TreeNode* root=new TreeNode(nums[index]);   
        root->left=helper(nums,left,index-1);
        root->right=helper(nums,index+1,right);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};