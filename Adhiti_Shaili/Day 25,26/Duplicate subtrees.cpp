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
    
    string Dup_Subtree(TreeNode* root,vector<TreeNode*>& v,unordered_map<string,int>& hash)
    {
        if(root==NULL)
        {
            return "";
        }
        
        string leftAns=Dup_Subtree(root->left,v,hash);
        string rightAns=Dup_Subtree(root->right,v,hash);
        
        string curr=to_string(root->val)+"_"+leftAns+"_"+rightAns;
        //cout<<curr<<endl;
        
        if(hash.find(curr)==hash.end())
        {
            //hash.insert(curr);
            hash[curr]++;
            //cout<<hash[curr]<<endl;
        }
        else if(hash[curr]==1)
        {
            v.push_back(root);
            hash[curr]++;
        }
        else
        {
            hash[curr]++;
        }
        
        
        return curr;
        
        
        
    }
    
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        vector<TreeNode*> v;        
        if(root==NULL)
        {
            return v;
        }
        string ans="";
        unordered_map<string,int> hash;
        Dup_Subtree(root,v,hash);
        return v;
    }
};