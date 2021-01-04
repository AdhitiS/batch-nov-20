#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    
    bool helper(TreeNode* root,int ans,int sum)
    {
        if(root==NULL)
        {
            return false;
        }
        
        if(root->left==NULL&&root->right==NULL)
        {
            if(ans+root->val==sum)
            {
                return true;
            }
            else 
            {
                return false;
            }
        }
        
        bool leftans=helper(root->left,ans+root->val,sum);
        bool rightans=helper(root->right,ans+root->val,sum);
        
        return leftans||rightans;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)
        {
            return 0;
        }
        
        return helper(root,0,sum);
    }
};