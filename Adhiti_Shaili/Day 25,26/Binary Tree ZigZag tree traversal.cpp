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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<TreeNode*> q;
        
        q.push(root);
        int count=0;
        while(!q.empty())
        {
            int size=q.size();
            vector<int> v;
            if(count==0)
            {
                while(size>0)
                {
                    TreeNode* curr=q.front();
                    q.pop();
                    if(curr->left!=NULL)
                    {
                        q.push(curr->left);
                    }
                    if(curr->right!=NULL)
                    {
                        q.push(curr->right);
                    }
                    v.push_back(curr->val);
                    size--;
                }
            }
            else
            {
                stack<int> s;
                while(size>0)
                {
                    TreeNode* curr=q.front();
                    q.pop();
                    s.push(curr->val);
                    if(curr->left!=NULL)
                    {
                        q.push(curr->left);
                    }
                    if(curr->right!=NULL)
                    {
                        q.push(curr->right);
                    }
                    size--;
                    
                }
                while(!s.empty())
                {
                    v.push_back(s.top());
                    s.pop();
                }
            }
            
            ans.push_back(v);
            count=1-count;
            
        }
        return ans;
        
    }
};