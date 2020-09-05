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
    
//     void traverse(TreeNode* root, map<int, vector<int>>& um, vector<vector<int>>& res, int dis){
     
//         if(!root)
//             return;
//         if(um.find(dis) == um.end()){
//             vector<int> v;
//             um[dis] = v;
//         }
//         um[dis].push_back(root->val);
//         cout<<dis<<" "<<root->val<<"\n";

           
//         traverse(root->left, um, res, dis-1);
//         traverse(root->right, um, res, dis+1);
        
//     }
    
    void dfs(TreeNode* node, int r, int c, unordered_map<int, vector<pair<int, int>>>& cache, int& minC, int& maxC){
        if(node == nullptr) return;
        if(cache.count(c)) cache[c].push_back({r, node->val});
        else cache.insert({c, {{r, node->val}}});
        minC = min(minC, c);
        maxC = max(maxC, c);
        dfs(node->left, r+1, c-1, cache, minC, maxC);
        dfs(node->right, r+1, c+1, cache, minC, maxC);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        // vector<vector<int>> res;
        // map<int, vector<int>> um;
        // int dis = 0;
        // traverse(root, um, res, dis);
        // // sort(um.begin(), um.end());
        // for(auto i = um.begin(); i!=um.end(); i++){
        //     res.push_back(i->second);
        // }
        // // reverse(res.begin(), res.end());
        // return res;
        
         vector<vector<int>> result;
        if(root == nullptr) return result;
        
        unordered_map<int, vector<pair<int, int>>> cache;
        int minC = 0, maxC = 0;
        dfs(root, 0, 0, cache, minC, maxC);
        
        for(int c = minC; c < maxC+1; ++c){
            sort(cache[c].begin(), cache[c].end(), [](pair<int, int>& p1, pair<int, int>& p2){
                return (p1.first < p2.first) || ((p1.first == p2.first) && (p1.second < p2.second));
            });
            vector<int> col;
            for(pair<int, int>& p: cache[c])
                col.push_back(p.second);
            result.push_back(col);
        }
        return result;
    
    }
};
