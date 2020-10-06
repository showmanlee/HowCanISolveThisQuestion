// Tree: Height of a Binary Tree
// https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree

int height(Node* root) {
    if (root == NULL)
        return -1;
    int l = height(root->left) + 1, r = height(root->right) + 1;
    return max(l, r);
}