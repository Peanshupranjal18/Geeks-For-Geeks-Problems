My Solution using recursion

    class Solution
{
public:
    bool solve(Node *root1, Node *root2)
    {
        if (root1 == NULL and root2 == NULL)
            return true;
        if (root1 == NULL or root2 == NULL)
            return false;
        if (root1->data != root2->data)
            return false;
        bool pair1 = solve(root1->left, root2->right);
        bool pair2 = solve(root1->right, root2->left);
        return pair1 and pair2;
    }

    bool isSymmetric(struct Node *root)
    {
        if (root == NULL)
            return true;
        return solve(root->left, root->right);
    }
};

Iterative Approach for the above problem

Iterative approach is done using stack and queue which we use for converting recursion to iterative code

// C++ program to check if a given Binary Tree is symmetric
// or not
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
    int key;
    struct Node *left, *right;
};

// Utility function to create new Node
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}

// Returns true if a tree is symmetric i.e. mirror image of
// itself
bool isSymmetric(Node *root)
{
    // If the root is null, then the binary tree is
    // symmetric.
    if (root == NULL)
    {
        return true;
    }

    // Create a stack to store the left and right subtrees
    // of the root.
    stack<Node *> stack;
    stack.push(root->left);
    stack.push(root->right);

    // Continue the loop until the stack is empty.
    while (!stack.empty())
    {
        // Pop the left and right subtrees from the stack.
        Node *node1 = stack.top();
        stack.pop();
        Node *node2 = stack.top();
        stack.pop();

        // If both nodes are null, continue the loop.
        if (node1 == NULL && node2 == NULL)
        {
            continue;
        }

        // If one of the nodes is null, the binary tree is
        // not symmetric.
        if (node1 == NULL || node2 == NULL)
        {
            return false;
        }

        // If the values of the nodes are not equal, the
        // binary tree is not symmetric.
        if (node1->key != node2->key)
        {
            return false;
        }

        // Push the left and right subtrees of the left and
        // right nodes onto the stack in the opposite order.
        stack.push(node1->left);
        stack.push(node2->right);
        stack.push(node1->right);
        stack.push(node2->left);
    }

    // If the loop completes, the binary tree is symmetric.
    return true;
}

// Driver code
int main()
{
    // Let us construct the Tree shown in the above figure
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    if (isSymmetric(root))
        cout << "Symmetric";
    else
        cout << "Not symmetric";
    return 0;
}

// This code is contributed by sramshyam
