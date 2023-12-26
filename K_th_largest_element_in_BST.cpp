Remember the fact that the inorder traversal of the BST gives a sorted array.

    class Solution
{
public:
    void inorder(Node *root, vector<int> &v)
    {
        if (root != NULL)
        {
            inorder(root->left, v);
            v.push_back(root->data);
            inorder(root->right, v);
        }
    }

    int kthLargest(Node *root, int k)
    {
        vector<int> v;
        inorder(root, v);
        return v[v.size() - k];
    }
};