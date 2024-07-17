#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int maxPathSumUtil(TreeNode* root, int& maxSum) {
        if (!root) return 0;
        int left = max(0, maxPathSumUtil(root->left, maxSum));
        int right = max(0, maxPathSumUtil(root->right, maxSum));
        maxSum = max(maxSum, left + right + root->val);
        return max(left, right) + root->val;
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathSumUtil(root, maxSum);
        return maxSum;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    Solution solution;
    cout << "Maximum path sum: " << solution.maxPathSum(root) << endl;
    
    return 0;
}
