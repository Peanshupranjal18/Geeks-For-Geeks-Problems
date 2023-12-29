Ek Node aur uska aage wala node carry karna hoga curr and prev

    class Solution
{
public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node *head, int data)
    {
        Node *newNode = new Node(data);
        if (!head or head->data >= data)
        {
            newNode->next = head;
            return newNode;
        }
        Node *prev = head;
        Node *curr = head->next;

        while (curr and curr->data < data)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = newNode;
        newNode->next = curr;

        return head;
    }
};