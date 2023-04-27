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
    bool isCousins(TreeNode* node, int x, int y) {
        queue<TreeNode*>q;
        set<int>s;
        q.push(node);
        while(!q.empty()){
            int si=q.size();
            while(si--){
                auto root=q.front();
                q.pop();
                int r=0;
                if(root->left) {
                    q.push(root->left);
                    if(root->left->val==x or root->left->val==y){
                        
                        s.insert(root->left->val);
                        r++;
                    }
                    
                }
                 if(root->right) {
                    q.push(root->right);
                    if(root->right->val==x or root->right->val==y){
                        s.insert(root->right->val);
                        r++;
                    }
                }
                if(r==2) return false;
            }
           
            if(s.size()==1) return false;
            if(s.size()==2){
                return true;
            }
        }
        return false;
    }
};