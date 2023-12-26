Given a Binary Tree of size N, find all the nodes which don 't have any sibling. You need to return a list of integers containing all the nodes that don' t have a sibling in sorted order.Two nodes are said to be siblings if they are present at the same level, and their parents are same

                                                                                                                                                                                                                                                                    void
                                                                                                                                                                                                                                                                    traverse(Node *root, set<int> &s)
{

    if (root->left == NULL and root->right == NULL)
        return;

    if (root->left != NULL and root->right != NULL)
    {
        traverse(root->left, s);
        traverse(root->right, s);
    }

    if (root->left != NULL and root->right == NULL)
    {
        s.insert(root->left->data);
        traverse(root->left, s);
    }

    if (root->right != NULL and root->left == NULL)
    {
        s.insert(root->right->data);
        traverse(root->right, s);
    }
}

vector<int> noSibling(Node *node)
{
    set<int> s;
    traverse(node, s);
    if (s.size() == 0)
        return {-1};
    vector<int> v(s.begin(), s.end());
    return v;
}