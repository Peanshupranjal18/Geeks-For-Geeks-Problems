// important concept for recursion

class Solution
{
public:
    void help(Node *root, Node *x, Node *&ans)
    {
        if (root == NULL)
            return;
        help(root->left, x, ans);
        if (x->data < root->data && ans == NULL)
        {
            ans = root;
        }
        help(root->right, x, ans);
    }
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node *inOrderSuccessor(Node *root, Node *x)
    {
        // Your code here
        Node *ans = NULL;
        help(root, x, ans);
        return ans;
    }
};

class Solution
{
public:
    // Function to find the in-order successor of a node in a BST
    Node *inOrderSuccessor(Node *root, Node *p)
    {
        // If the root or node to find the successor is NULL, return NULL
        if (root == NULL || p == NULL)
            return NULL;

        // Initialize a variable to store the successor node
        Node *suc = NULL;

        // Traverse the tree until we find the node or reach the end
        while (root != NULL)
        {
            // If the current node's data is less than or equal to the given node's data,
            // move to the right child of the current node
            if (root->data <= p->data)
                root = root->right;

            // If the current node's data is greater than the given node's data,
            // move to the left child and update the successor node
            else
            {
                suc = root;
                root = root->left;
            }
        }

        // Return the successor node
        return suc;
    }
};