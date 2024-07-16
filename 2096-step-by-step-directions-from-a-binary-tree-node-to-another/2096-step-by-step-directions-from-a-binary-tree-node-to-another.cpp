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
    std::deque<char> StartValuePath;
    std::deque<char> destValuePath;
    string getDirections(TreeNode* root, int startValue, int destValue) {
        dfs(root, startValue, StartValuePath);
        dfs(root, destValue, destValuePath);

        while(!StartValuePath.empty() && !destValuePath.empty()){
            if(StartValuePath.front() == destValuePath.front()){
                StartValuePath.pop_front();
                destValuePath.pop_front();
            }
            else { break; }
        }
        
        string answer(StartValuePath.size(), 'U');
        while(!destValuePath.empty()){
            answer += destValuePath.front();
            destValuePath.pop_front();
        }
        return answer;
    }

    bool dfs(TreeNode* ptr, int targetValue, std::deque<char> &path){
        if(ptr->val == targetValue) return true;

        if(ptr->left){
            path.push_back('L');
            bool foundpath = dfs(ptr->left, targetValue, path);
            if(foundpath) { return true; }
            path.pop_back();
        }

        if(ptr->right){
            path.push_back('R');
            bool foundpath = dfs(ptr->right, targetValue, path);
            if(foundpath) { return true; }
            path.pop_back();
        }

        return false;
    }
};