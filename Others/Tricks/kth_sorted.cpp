//https://www.interviewbit.com/problems/kth-smallest-element-in-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::kthsmallest(TreeNode* A, int B) {
    vector <int> inorder;
    function<void(TreeNode *)> dfs = [&](TreeNode * root) {
        if (root == nullptr) return;
        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    };
    dfs(A);
    return inorder[B - 1];
}
