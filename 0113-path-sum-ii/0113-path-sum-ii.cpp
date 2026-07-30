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
    void Sum(TreeNode* root,int t,int a,vector<int>& res,vector<vector<int>>& ans){
        
        if(root==nullptr) return;
        a+=root->val;
        res.push_back(root->val);
        if(!root->left&&!root->right&&a==t){
            ans.push_back(res);
        }
        Sum(root->left,t,a,res,ans);
        Sum(root->right,t,a,res,ans);
        res.pop_back();        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>res;
        Sum(root,targetSum,0,res,ans);
        return ans;
    }
};