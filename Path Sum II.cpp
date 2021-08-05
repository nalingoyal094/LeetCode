class Solution {
public:
    vector<vector<int>>paths;
    
    void findpaths(int sum,TreeNode*root,vector<int >v)
    {
        if (root==NULL)
            return;
        
        v.push_back(root->val);
        if (root->val==sum && root->left==NULL && root->right==NULL)
        {
            
            paths.push_back(v);
            return;
            
        }
        
        findpaths(sum-(root->val),root->left,v);
        findpaths(sum-(root->val),root->right,v);
        
        
        
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        
        vector<int>v={};
        
        findpaths(targetSum,root,v);
        
        return paths;
    }
    
    
    
};
