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
    int k;
    
    void del(TreeNode* t){   

        if(t->left){
            
            if(t->left->val == k){
                if(!t->left->left && !t->left->right){
                    t->left = NULL;
                    return;
                }
                else if(t->left->right){
                    TreeNode* left = t->left->left;
                    TreeNode* right = t->left->right;
                    TreeNode* next = right;
                    while(right->left){
                        cout<<right->val<<" ";
                        right = right->left;
                    }
                    t->left = right;
                    right->right = next;
                    if(left)
                        right->left = left;
                    return;
                }
                else{
                    t->left = t->left->left;
                    return;
                }
            }
            
            del(t->left);
            
        }
        
        if(t->right){
           
           if(t->right->val == k){
               // cout<<"E";
                if(!t->right->left && !t->right->right){
                    t->right = NULL;
                    return;
                }
                else if(t->right->right){
                    TreeNode* left = t->right->left;
                    TreeNode* right = t->right->right;
                    TreeNode* next = right;
                    // cout<<right<<"Q";
                    while(right->left){
                        right = right->left;
                    }
                    t->right = right;
                    right->right = next;
                    if(left)
                        right->left = left;
                    return;
                }
                else{
                    // cout<<"Z"<<t->right->val<<" "<<t->right->left->val<<"A";
                    t->right = t->right->left;
                    return;
                }
            }
            
            del(t->right);
        }
        

           
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if (root == nullptr) return root;
    if (key > root->val) {
      root->right = deleteNode(root->right, key);
    } else if (key < root->val) {
      root->left = deleteNode(root->left, key);
    } else {
      if (root->left != nullptr && root->right != nullptr) {
        TreeNode* min = root->right;
        while (min->left != nullptr) min = min->left;
        root->val = min->val;
        root->right = deleteNode(root->right, min->val);
      } else {
        TreeNode* new_root = root->left == nullptr ? root->right : root->left;
        root->left = root->right = nullptr;
        delete root;
        return new_root;
      }
    }    
    return root;
        
        
        k=key;
        if(!root)
            return root;
        if(root->val == k){
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            TreeNode* next = right;
            if(!left && !right)
                return left;
            else if(right){
                cout<<"A";
                while(right->left){
                    right = right->left;
                }
                root = right;
                right->right = next;
                if(left)
                    right->left = left;
                cout<<"B";
                return root;
            }
            else{
                root = left;
                return root;
            }
        }
        del(root);
        return root;
    }
};  
