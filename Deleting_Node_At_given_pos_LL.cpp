just move the temp variable to the point where we want to delete the number and put its temp->next to temp->next->next

    Node *
    deleteNode(Node *head, int x)
{
    Node *temp = head;
    if (x == 1)
    {
        head = head->next;
    }
    else
    {
        for (int i = 1; i < x - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
    return head;
}