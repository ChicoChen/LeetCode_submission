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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        vector<int> post_idx_map(n + 1);
        for(int i = 0; i < n; i++){
            post_idx_map[postorder[i]] = i;
        }

        return constructNode(preorder, postorder, n, 0, 0, post_idx_map);
    }

    TreeNode* constructNode(const vector<int>& preorder, const vector<int>& postorder,
                            int tree_size, int pre_start, int post_start,
                            const vector<int> &post_idx_map)
    {   
        if(tree_size <= 0) return NULL;

        TreeNode* root = new TreeNode(preorder[pre_start]);
        if(tree_size == 1) return root;

        int left_val = preorder[pre_start + 1];
        int l_tree_size = post_idx_map[left_val] - post_start + 1;
        int r_tree_size = tree_size - 1 - l_tree_size;

        root->left = constructNode(preorder, postorder, l_tree_size,
                                    pre_start + 1, post_start,
                                    post_idx_map);
        root->right = constructNode(preorder, postorder, r_tree_size,
                                    pre_start + 1 + l_tree_size, post_start + l_tree_size,
                                    post_idx_map);
        return root;
    }
};