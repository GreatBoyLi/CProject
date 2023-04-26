#ifndef TREE_H
#define TREE_H

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

inline void initTree(TreeNode *&root, int *a, int n, int i = 0)
{
    if (i >= n)
        return;
    if (a[i] == -1)
        return;
    root = new TreeNode(a[i]);
    initTree(root->left, a, n, 2 * i + 1);
    initTree(root->right, a, n, 2 * i + 2);
}

#endif // !TREE_H