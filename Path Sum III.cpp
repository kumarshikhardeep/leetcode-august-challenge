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
    
    void getSum(TreeNode* root, int sum, int& count, vector<int> nodes){
        
        if(!root)
            return;
        
        nodes.push_back(root->val);
        
        getSum(root->left, sum, count, nodes);
        getSum(root->right, sum, count, nodes);
        
        int tot = 0;
        for(int i=nodes.size()-1; i>=0; i--){
            tot += nodes[i];
            if(tot == sum)
                count++;
        }
        nodes.pop_back();
    }
    
    int pathSum(TreeNode* root, int sum) {
        int count = 0;
        vector<int> nodes;
        getSum(root, sum, count, nodes);
        return count;
       
    }
};
