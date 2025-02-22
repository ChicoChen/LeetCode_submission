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
    TreeNode* recoverFromPreorder(string traversal) {
        int i = 0;
        int n = traversal.size();
        string number;
        while(i < n && traversal[i] != '-'){
            number += traversal[i];
            i++;
        }
        TreeNode* current = new TreeNode(stoi(number));
        TreeNode* root = current;
        
        int current_depth = 0;
        int depth_count = 0;

        stack<TreeNode*> path;
        path.push(current);
        for(; i < n;){
            if(traversal[i] != '-'){
                number.clear();
                do{
                    number += traversal[i];
                    i++;
                }
                while(i < n && traversal[i] != '-');
            }
            else{
                depth_count++;
                i++;
                continue;
            }


            int value = stoi(number);
            if(depth_count == current_depth + 1){
                current->left = new TreeNode(value);
                current = current->left;
            }
            else if(depth_count == current_depth){
                path.pop();
                current = path.top();
                current->right = new TreeNode(value);
                current = current->right;
            }
            else{ //depth_count < current_depth
                int difference = current_depth - depth_count;
                while(difference >= 0){
                    path.pop();
                    difference--;
                }
                current = path.top();
                current->right = new TreeNode(value);
                current = current->right;
            }
            path.push(current);
            current_depth = depth_count;
            depth_count = 0;
        }
        return root;
    }
};